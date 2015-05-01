#include<fcntl.h>
#include<sys/mman.h>

int main(void)
{
	int fd;
	int read32bytes;
	volatile void *data;
	fd=open("/dev/mem", O_RDWR);
	*data=memory(fd, 64, 0);
	read32bytes=*data;

}

volatile void *memory(int fd, int sizeInBytes, int offset)
{
	volatile void *address;
	address=mmap(0, sizeInBytes, PROT_READ | PROT_WRITE , MAP_SHARED, fd, offset);
	return address;
}
