
#include <stdio.h>
#include "/.../include/unigram.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


static char* to_lower(char* str) {
  for (char* p=str;*p;p++) *p = tolower(*p);
  return str;
}

Unigram* create_unigrams(char** strings,int* unigram_count){
  Unigram* unigrams=NULL;
  *unigram_count=0;
  int i=0;

  while(strings[i]!=NULL){
    char* st=strdup(strings[i]);
    if(!st){
      printf("strdup failed\n");
      exit(1);
    }
    to_lower(st);
    int found=0;
    for (int j=0;j<*unigram_count;j++){
      if(unigrams[j].word1&&strcmp(unigrams[j].word1,st)==0){
            found=1;
            break;
        }
    }
    if(!found){
      unigrams=realloc(unigrams,(*unigram_count+1)*sizeof(Unigram));
      if(!unigrams){
          printf("realloc failed\n");
          free(st);
          exit(1);
      }
      
      unigrams[*unigram_count].word1=strdup(st);
      unigrams[*unigram_count].count=0;
      (*unigram_count)++;
    }
    free(st);
    i++;
  }

return unigrams;
}

void count_unigrams(char** strings,Unigram* unigrams,int unigram_count){
  int i=0;
  while (strings[i]!=NULL){
      char* st=strdup(strings[i]);
      to_lower(st);

      for (int j=0;j<unigram_count;j++){
          if (strcmp(unigrams[j].word1,st)==0){
              unigrams[j].count++;
              break;
          }
      }

      free(st);
      i++;
  }

}


