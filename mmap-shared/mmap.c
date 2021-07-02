#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define MEMSIZE 1024*1024*1024
#define MPFILE "./../mmapfile"
int main()
{
    void *ptr;
    int fd;
    fd = open(MPFILE, O_RDWR);
    if (fd < 0) {
        perror("open()");
        exit(1);
    }
    ptr = mmap(NULL, MEMSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == NULL) {
        perror("mmap()");
        exit(1);
    }
    printf("%p\n", ptr);
    bzero(ptr, MEMSIZE);
    printf("pid=%d\n", getpid());
    sleep(50);
    munmap(ptr, MEMSIZE);
    close(fd);
    exit(1);
}
