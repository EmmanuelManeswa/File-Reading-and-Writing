#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define buf_size 100

int main(int argc, char *argv[]){

  if(argc-1 != 2){
    perror("Incomplete or Too many arguments.\n");
    exit(EXIT_FAILURE);
  }

  int read_fd = open(argv[1], O_RDONLY);
  if(read_fd < 0){
    printf("Error! %s does not exist.\n",argv[1]);
    exit(EXIT_FAILURE);
  }

  int write_fd = open(argv[2], O_APPEND | O_CREAT | O_WRONLY, 0666);
  if(write_fd < 0){
    perror("Unknown error!\n");
    exit(EXIT_FAILURE);
  }

  char buf[buf_size];
  ssize_t bytes_read, bytes_written;
  while((bytes_read = read(read_fd, buf, buf_size)) > 0){
    bytes_written = write(write_fd, buf, bytes_read);
    if(bytes_written < 0){
      perror("write error!\n");
      exit(EXIT_FAILURE);
    }
  }

  close(read_fd);
  close(write_fd);
  unlink(argv[1]);

  exit(EXIT_SUCCESS);
}
