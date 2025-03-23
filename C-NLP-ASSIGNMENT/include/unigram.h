#ifndef UNIGRAM_H
#define UNIGRAM_H

typedef struct{
    char* word1;
    int count;
}Unigram;

Unigram* create_unigrams(char** strings,int* unigram_count);
void count_unigrams(char** strings,Unigram* unigrams,int unigram_count);


#endif
