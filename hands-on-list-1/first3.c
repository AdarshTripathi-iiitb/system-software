#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	const char* filename = "example.txt";
	int fd;

	//Create the file with read and write permissions fot the owner
	fd = creat(filename, S_IRUSR | S_IWUSR);

	if (fd == -1) {
		perror("Error creating file");
		return 1;
	}

	printf("File created: %\nFile descriptior: %d\n",filename, fd);

	//Close the file descriptor
	if(close(fd) == -1){
		perror("Error closing file");
		return 1;
	}

	return 0;

}
