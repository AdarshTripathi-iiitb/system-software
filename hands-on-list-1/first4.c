#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char* args[])
{
      if(argc!=2)
	printf("Input File name not given/n");
      int fd = open(args[1],O_CREAT| O_EXCL);
       if(fd == -1)
      printf("File Already Created\n");
       else
      printf("File Scucessuly Create\n");
       return 0;
}




