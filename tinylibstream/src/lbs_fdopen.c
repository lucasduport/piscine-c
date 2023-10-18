#include <stdlib.h>
#include <string.h>

#include "../include/libstream.h"
#include "fcntl.h"
#include "unistd.h"

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd == -1)
        return NULL;
    struct stream *str = calloc(sizeof(struct stream), 1);
    if (!str)
        return NULL;
    if (strcmp(mode, "w") == 0)
        str->flags = (O_WRONLY | O_CREAT | O_TRUNC);
    if (strcmp(mode, "r+") == 0)
        str->flags = (O_RDWR);
    if (strcmp(mode, "r") == 0)
        str->flags = (O_RDONLY);
    if (strcmp(mode, "w+") == 0)
        str->flags = (O_RDWR | O_CREAT | O_TRUNC);
    str->fd = fd;
    str->buffering_mode = STREAM_BUFFERED;
    if (isatty(fd))
        str->buffering_mode = STREAM_LINE_BUFFERED;
    if (strcmp(mode, "r+") == 0 || strcmp(mode, "r") == 0)
        str->io_operation = STREAM_READING;
    if (strcmp(mode, "w+") == 0 || strcmp(mode, "w") == 0)
        str->io_operation = STREAM_WRITING;
    str->buffered_size = 0;
    str->already_read = 0;
    return str;
}

struct stream *lbs_fopen(const char *path, const char *mode)
{
    int fd = -1;
    if (strcmp(mode, "w") == 0)
        fd = open(path, O_WRONLY | O_CREAT | O_TRUNC);
    else if (strcmp(mode, "r+") == 0)
        fd = open(path, O_RDWR);
    else if (strcmp(mode, "r") == 0)
        fd = open(path, O_RDONLY);
    else if (strcmp(mode, "w+") == 0)
        fd = open(path, O_RDWR | O_CREAT | O_TRUNC);
    else
        return NULL;
    return lbs_fdopen(fd, mode);
}

int lbs_fflush(struct stream *stream)
{
    if (stream->io_operation == STREAM_WRITING && stream->buffered_size != 0)
    {
        if (write(stream->fd, stream->buffer, stream->buffered_size) == -1)
            stream->error = 1;
    }
    if (stream->io_operation == STREAM_READING)
    {
        if (lseek(stream->fd, -stream_remaining_buffered(stream), SEEK_CUR)
            == -1)
            stream->error = 1;
    }
    stream->buffered_size = 0;
    stream->already_read = 0;
    return stream->error;
}

int lbs_fclose(struct stream *file)
{
    if (file == NULL)
        return 1;
    if (lbs_fflush(file) == 1 || close(file->fd) == -1)
    {
        free(file);
        return 1;
    }
    free(file);
    return 0;
}

int lbs_fputc(int c, struct stream *stream)
{
    if (!stream_writable(stream))
    {
        stream->error = 1;
        return -1;
    }
    if (stream->io_operation == STREAM_READING)
    {
        if (lbs_fflush(stream) == 1)
            return -1;
        stream->io_operation = STREAM_WRITING;
    }
    stream->buffer[stream->buffered_size++] = c;
    if (stream->buffered_size == LBS_BUFFER_SIZE
        || stream->buffering_mode == STREAM_UNBUFFERED)
        lbs_fflush(stream);
    if (stream->buffering_mode == STREAM_LINE_BUFFERED && c == '\n')
        lbs_fflush(stream);
    if (c == 0 || stream->error == 1)
    {
        lbs_fflush(stream);
        stream->error = 1;
        return -1;
    }
    return c;
}

int lbs_fgetc(struct stream *stream)
{
    if (!stream_readable(stream))
    {
        stream->error = 1;
        return -1;
    }
    if (stream->io_operation == STREAM_WRITING)
    {
        if (lbs_fflush(stream) == 1)
            return -1;
        stream->io_operation = STREAM_READING;
    }
    if (stream->already_read == stream->buffered_size)
        stream->buffered_size = 0;
    if (stream->buffered_size == 0)
    {
        ssize_t r = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        stream->already_read = 0;
        if (r <= 0)
        {
            stream->error = 1;
            return -1;
        }
        stream->buffered_size = r;
    }
    unsigned char c = stream->buffer[stream->already_read++];
    return c;
}
