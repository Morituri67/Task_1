//
// Created by Artem on 04.08.2021.
//

#include "ListString.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

static int StringCount;

int StringListSize(){
    return StringCount;
}

void SwapStrings(char** list,int string1,int string2){
    char* temp= (char*)malloc(strlen(list[string1])+1);

    strcpy(temp,list[string1]);
    /*list[string1]=(char*)realloc(list[string1], strlen(list[string2])+1);*/
    strcpy(list[string1],list[string2]);
    strcpy(list[string2],temp);
}

void StringListInit(char ***list){
    (*list)= (char **) calloc(1,sizeof(char*)) ;
    StringCount= 0;
}

void StringListAdd(char** list, char* buffer){
    if (StringCount==0){
        list[0]= (char*)malloc(strlen(buffer)+1);
        strcpy(list[0],buffer);
        StringCount++;
    } else {
        list= (char**)realloc(list, StringCount+2);
        list[StringCount]=(char*)malloc(strlen(buffer)+1);
        strcpy(list[StringCount],buffer);
        StringCount++;
    }

}

void DeleteString(char** list, int StringNumber){
    std::swap(list[StringNumber],list[StringCount]);
    list= (char**)realloc(list, sizeof(char*)*(--StringCount));
    free(list[StringNumber]);
    strcpy(list[StringNumber]," ");

}


int FindString(char** list, char* CompareString){
    for (int i = 0; i < StringCount; ++i) {
        if(!strcmp(list[i],CompareString)){
            return i;
        }
    }
    return -1;
}

void ShowList(char **list){
    std::cout<<"\n\t THE LIST IS ->\n";
    for (int i = 0; i < StringCount; ++i) {
        printf("%s \n",list[i]);
    }
}

void StringListDestroy(char*** list){
    for (int i = StringCount; i >= 0; --i) {
        free(*list[i]);
    }
    free(list);
    StringCount=0;
}

void StringListRemoveDuplicates(char** list){
    for (int i = 0; i < StringCount; ++i) {
        for (int j = i+1; j < StringCount; ++j) {
            if (!strcmp(list[i],list[j])){
                DeleteString(list,j);
            }
        }
    }
}

void StringListReplaceInStrings(char** list, char* before, char* after){
    for (int i = 0; i < StringCount; ++i){
        if(!strcmp(list[i],before)){
            strcpy(list[i],after);
        }
    }
}

static int myCompare(const void* string1, const void* string2)
{

    return strcmp(*(const char**)string1, *(const char**)string2);
}

void StringListSort(char** list){
    qsort(list, StringCount, sizeof(const char*), myCompare);
}