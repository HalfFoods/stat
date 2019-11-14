#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  struct stat md;
  stat("stat.c", &md);
  printf("File size: %lld B\n", md.st_size);
  printf("Mode (permissions): %o\n", md.st_mode);
  printf("Time of last access: %s", ctime(&md.st_atime));

  char buffer[100];
  int i = 0;
  char * units[] = {"B", "KB", "MB", "GB"};
  float s = md.st_size;
  while (s >= 1024){
    s /= 1024.;
    i++;
  }
  sprintf(buffer, "Human readable form: %f %s\n", s, units[i]);
  printf("%s", buffer);

  char p[10] ="rwxrwxrwx";
  for (int i = 0; i < 9; i++){
    if(!(md.st_mode & (1 << (8-i)))){
      p[i] = '-';
    }
  }
  printf("Permissions in ls -l form: %s\n", p);
}
