#include <stdio.h>
#include <stdlib.h>
#include "/.../include/file_read.h"
#include "/.../include/unigram.h"

int main(){
    int num_sentences;
    char** sentences=read("input.txt",&num_sentences);
    int unigram_count;
    char* temp_arr[]={"hello","world","this","is","sampl",NULL};
    char** st=temp_arr;
    Unigram* unigrams=create_unigrams(st,&unigram_count);
    count_unigrams(st,unigrams,unigram_count);
    return 0;
}
