#include <stdio.h>
#include <stdlib.h>

#include "file_disemvowel.h"

int main(int argc, char *argv[]) {
  char *line = NULL;
  size_t size = 0;
  char buffer[1024];
  File *fptr;
  const char *input_filename = argv[1];
  const char *output_filename = argv[2];
  fptr = fopen(input_filename, "r");

  if (input_filename == NULL){
    printf("Error, file non-existent/Error Opening File")
    return 1;
  }
  
  
  while (fgets(buffer, sizeof(buffer), fptr)) {
    char *dis = disemvowel(line);
    if (dis) {
       printf("%s\n", dis);
       free((void*) dis);
    }
  }
  fclose(input_filename);
  fclose(output_filename);
  free((void*) line);
  return 0;
}
