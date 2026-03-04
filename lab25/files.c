#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    char a = 'x', b = 'x', c = 'x', d = 'x';
    int f = open("stuff.txt", O_RDONLY);

    // LOCATION #1

    int pid = fork();

    // LOCATION #2

    read(0, &a, 1);
    read(f, &b, 1);

    // LOCATION #3

    int g = open("stuff.txt", O_RDONLY);
    int h = open("stuff.txt", O_RDONLY);

    read(g, &c, 1);
    if (pid != 0) {
        read(h, &d, 1);
    }
    read(h, &d, 1);

    // LOCATION #4

    printf("%c%c%c%c\n", a, b, c, d);

    if (pid == 0) {
        exit(0);
    } else {
        wait(NULL);
    }
    return 0;
}
