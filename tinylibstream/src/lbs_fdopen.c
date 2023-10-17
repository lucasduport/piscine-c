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
    str->error = 0;
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
    if (strcmp(mode, "r+") == 0)
        fd = open(path, O_RDWR);
    if (strcmp(mode, "r") == 0)
        fd = open(path, O_RDONLY);
    if (strcmp(mode, "w+") == 0)
        fd = open(path, O_RDWR | O_CREAT | O_TRUNC);
    return lbs_fdopen(fd, mode);
}

/*
** Flushes the stream's buffer to the underlying file descriptor, making sure
** the stream position is correct. When there is some write data buffered, it
** has to be written. When there is some read data buffered, it has to be
** discarded and the process must seek the file descriptor back to the
** position the user expects.
**
** Works just like fflush(3), except:
**  - lbs_fflush() *DOES NOT* flush all open output streams if stream is NULL.
** May set the error indicator.
*/
int lbs_fflush(struct stream *stream)
{
    if (stream->io_operation == STREAM_WRITING)
    {
        if (write(stream->fd, stream->buffer, stream->buffered_size) == -1)
            stream->error = 1;
    }
    if (stream->io_operation == STREAM_READING)
    {
        if (lseek(stream->fd, -stream_unused_buffer_space(stream), SEEK_CUR)
            == -1)
            stream->error = 1;
    }
    stream->buffered_size = 0;
    return stream->error;
}

int lbs_fclose(struct stream *file)
{
    if (file == NULL)
        return 1;
    if (lbs_fflush(file) == 1)
        return 1;
    if (close(file->fd) == -1)
        return 1;
    free(file);
    return 0;
}

/*
** Writes a single character to some stream.
** It may cause the stream to flush if the buffer is full or the current
** buffering policy requires it.
** Works just like fputc(3). May set the error indicator.
*/
int lbs_fputc(int c, struct stream *stream)
{
    if (!stream_writable(stream))
    {
        stream->error = 1;
        return -1;
    }
    stream->buffer[stream->buffered_size++] = c;
    int wasR = 0;
    if (stream->io_operation == STREAM_READING)
    {
        wasR = 1;
        lbs_fflush(stream);
        stream->io_operation = STREAM_WRITING;
    }
    if (stream->buffered_size == LBS_BUFFER_SIZE
        || stream->buffering_mode == STREAM_UNBUFFERED)
        lbs_fflush(stream);
    if (stream->buffering_mode == STREAM_LINE_BUFFERED || c == '\n')
        lbs_fflush(stream);
    if (stream->error == 1)
        return -1;
    if (wasR == 1)
    {
        lbs_fflush(stream);
        stream->io_operation = STREAM_READING;
    }
    return c;
}

/*
** Reads a new character from the stream's buffer.
** If the buffer it empty, it should be refilled.
** Works just like fgetc(3). May set the error indicator.
*/
int lbs_fgetc(struct stream *stream)
{
    if (!stream_readable(stream))
    {
        stream->error = 1;
        return -1;
    }
    if (stream->buffered_size == 0)
    {
        stream->buffered_size =
            read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        if (stream->buffered_size == -1)
        {
            stream->error = 1;
            return -1;
        }
    }
    int wasW = 0;
    if (stream->io_operation == STREAM_WRITING)
    {
        wasW = 1;
        lbs_fflush(stream);
        stream->io_operation = STREAM_READING;
    }
    int c = stream->buffer[stream->already_read++];
    if (wasW == 1)
    {
        lbs_fflush(stream);
        stream->io_operation = STREAM_WRITING;
    }
    if (stream->already_read == stream->buffered_size)
        stream->buffered_size = 0;
    return c;
}
