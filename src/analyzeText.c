#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

char **analyzeText(char *filename){
    FILE *file = fopen(filename, "r");
    char **result = malloc(sizeof(char *) * 5);
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int wordCount = 0, characterCount = 0, lineCount = 0;
    double readTime = 0.0;

    if(file == NULL){
        printf("File not found\n");
        return NULL;
    }

    while((read = getline(&line, &len, file)) != -1){
        lineCount++;
        characterCount += strlen(line);
        char *token = strtok(line, " ");
        while(token != NULL){
            wordCount++;
            token = strtok(NULL, " ");
        }
    }

    readTime = (double) characterCount / 1500;

    result[0] = malloc(sizeof(char) * 20);
    sprintf(result[0], "%d words", wordCount); 

    result[1] = malloc(sizeof(char) * 20);
    sprintf(result[1], "%d characters", characterCount); 

    result[2] = malloc(sizeof(char) * 20);
    sprintf(result[2], "%d lines", lineCount); 

    result[3] = malloc(sizeof(char) * 20);
    sprintf(result[3], "%.2f minutes", readTime); 

    result[4] = NULL;

    fclose(file);
    if(line){
        free(line);
    }

    return result;
}