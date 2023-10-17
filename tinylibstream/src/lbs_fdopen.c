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
