#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    int pageSize = getpagesize();
    
    printf("Page size: %d bytes.\n", pageSize);
    
    //Page size: 4096 bytes.

    char *p = mmap(0, pageSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    printf("Page Address: %p\n", p);

    return 0;
}

