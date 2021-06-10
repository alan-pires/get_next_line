#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    char *linha;
    int fd;
    

    fd = open("teste.txt", O_RDONLY);
    get_next_line(fd, &linha);
    free(linha);
}