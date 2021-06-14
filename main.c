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
	// printf("linha: %s\n",linha);
	// get_next_line(fd, &linha);
	// printf("linha 2: %s\n",linha);
    free(linha);
}
