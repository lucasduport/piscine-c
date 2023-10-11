#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int handle_args(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(STDERR_FILENO, "Invalid number of arguments\n", 28);
        ;
        return -1;
    }
    int f_read = open(argv[1], O_RDONLY);
    if (f_read == -1)
    {
        write(STDERR_FILENO, "Could not open file\n", 20);
        return -1;
    }
    close(f_read);
    return 1;
}

int main(int argc, char *argv[])
{
    if (handle_args(argc, argv) == -1)
        return 1;
    int f_read = open(argv[1], O_RDONLY);
    char res[] = "  \n";
    int j = 1;
    char buff[5] = "";
    ssize_t bytesRead = 0;
    int finish = 0;
    int r = 1;
    while (!finish && r != 0)
    {
        off_t s = lseek(f_read, -5 - bytesRead, SEEK_END);
        if (s == -1)
        {
            s = lseek(f_read, 0, SEEK_SET);
            r = 0;
        }
        int r = read(f_read, buff, 5);
        bytesRead += r;
        for (int i = 4; i >= 0; i--)
        {
            if (buff[i] != 0 && !isspace(buff[i]))
            {
                res[j] = buff[i];
                j--;
                if (j < 0)
                {
                    finish = 1;
                    break;
                }
            }
        }
    }
    close(f_read);
    if (finish == 0)
    {
        write(STDERR_FILENO, "File is not long enough\n", 24);
        return 1;
    }
    write(STDOUT_FILENO, res, 3);
    return 0;
}
