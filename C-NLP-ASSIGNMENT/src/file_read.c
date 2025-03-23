#include "/.../include/file_read.h"   //change accordingly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** read(const char* filename,int* num_sentences){
  FILE* file=fopen(filename,"r");
  if(!file){
    printf("ERROR OPENING FILE");
    exit(1);
  }
  
  char ch;
  *(num_sentences)=0;
  while((ch=fgetc(file))!=EOF){
    if(ch=='\n'){
      (*num_sentences)++;
    }
  }
  fseek(file, -1, SEEK_END);
  if(fgetc(file)!='\n'){
    (*num_sentences)++;
    }
  rewind(file);
  
  char** sentences=malloc((*num_sentences)*sizeof(char*));
  if(!sentences){
      printf("malloc failed\n");
      exit(1);
  }
  size_t len=0;
  ssize_t read;
  char* line=NULL;
  int index=0;
  
  while((read=getline(&line,&len,file))!=-1){
      if(line[read-1]=='\n'){
          line[read-1]='\0';
      }
      sentences[index++] = strdup(line);
  }
  free(line);
  fclose(file);
  return sentences;

}

