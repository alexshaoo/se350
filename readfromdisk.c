// ssize_t read(int file_descriptor, void *buffer, size_t count);
// int bytes read = read(file, buffer, num_bytes);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void readfile(int fd);

int main (int argc, char** argv) {
  // Check for correct number of arguments
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }
  int fd = open(argv[1], O_RDONLY);
  // Check if file is valid
  if (fd == -1) {
    printf("Unable to open file! %s is invalid name?\n", argv[1]);
    return -1;
  }
  readfile(fd);
  close(fd);
  return 0;
}

void readfile(int fd) {
  int buf_size = 256;
  char* buffer = malloc(buf_size);
  while (1) {
    memset(buffer, 0, buf_size);
    int bytes_read = read(fd, buffer, buf_size - 1);
    if (bytes_read == 0) {
      break;
    }
    printf("%s", buffer);
  }
  printf("\nEnd of File.\n");
  free(buffer);
}
