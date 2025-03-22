#include "include/file_read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** read(const char* filename,int* num_sentences){
  FILE* file=fopen(filename,"r");
  if(!file){
    printf("ERROR OPENING FILE");
    exit(1);
  }

  char** sentences=NULL;
  char line[1000];
  *num_sentences=0;

  while(fgets(line,1000,file)){
    sentences=realloc(sentences,(*num_sentences+1)*sizeof(char*));
    line[strcspn(line,"\n")]='\0';
    sentences[*num_sentences]=strdup(line);
    (*num_sentences)++;
  }
  fclose(file);
  return sentences;

}

