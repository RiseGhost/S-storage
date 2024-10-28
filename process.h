#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* read_process(char *path,short Buffer_Size){
    char* buffer = (char*) malloc(sizeof(char) * Buffer_Size);
    FILE *f = fopen(path,"r");
    if (f == NULL){
        printf("Erro open file. Creating fifo\n");
        mkfifo(path,0666);
        read_process(path, Buffer_Size);
    }
    fread(buffer,sizeof(char),100,f);
    fclose(f);
    return buffer;
}

void write_process(char *path, short Buffer_Size, char* content){
    FILE* f = fopen(path,"w");
    fwrite(content, sizeof(char), strlen(content),f);
    fclose(f);
}

void create_pipes(char files_names[][100], short size){
    while (size > 0){
        mkfifo(files_names[size - 1],0666);
        size--;
    } 
}

void delete_pipes(char file_names[][100], short size){
    while(size > 0){
        remove(file_names[size - 1]);
        size--;
    }
}