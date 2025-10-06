#include <stdio.h>
#include <stdlib.h>

#include "file_disemvowel.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    return 1;
  }
  
  char *line = NULL;
  char buffer[1024];
  
  const char *input_filename = argv[1];
  const char *output_filename = argv[2];
  
  FILE *fptr_in = fopen(input_filename, "r");
  
  if (fptr_in == NULL){
    printf("Error opening file %s\n", input_filename);
    return 1;
  }
  
  FILE *fptr_out = fopen(output_filename, "w");
  if(fptr_out == NULL){
    printf("Error opening file %s\n", output_filename);
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), fptr_in)) {
    char *dis = disemvowel(buffer);
    if (dis) {
       printf("%s\n", dis);
       free((void*) dis);
    }
  }
  fclose(fptr_in);
  fclose(fptr_out);
  free((void*) line);
  return 0;
}
