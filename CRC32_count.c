// CRC32_count.c
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include "CRC32_func.h"

int main (int argc, char **argv)
{
	if (argc < 2) {
		printf("Error: An absolute path to a file must be entered as the first argument to this program");
		return EXIT_FAILURE;
	}

	struct stat statbuf;
	int fd;
	void *src;

	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		printf("Failed to open file %s", argv[1]);
		return EXIT_FAILURE;
	}

	if (fstat(fd, &statbuf) < 0) {
		printf("Error fstat() %d", errno);
		return EXIT_FAILURE;
	}

	src = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (src== MAP_FAILED) {
		printf("Error mmap() %d", errno);
		return EXIT_FAILURE;
	}

	uint32_t num = crc32((const void *) src, statbuf.st_size);
	munmap (src, statbuf.st_size);
	printf ("CRC32 = %x\n", num);

	return 0;
}
