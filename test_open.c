#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	int32_t fd = open("./input1", O_RDONLY | O_CREAT | O_RDWR);
	printf("fd:%i", fd);
}