//
// Created by Artem on 04.08.2021.
//

#include "ListString.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define SIZE 1

int StringListSize(char **list){
    int size=(sizeof(list)/sizeof (char*));
    return size;
}

void SwapStrings(char** list,int string1,int string2){
    char* temp=nullptr;
    temp=list[string1];
    list[string1]=list[string2];
    list[string2]=temp;
    /*temp= (char*)malloc(strlen(list[string1])+1);
 strcpy(temp,list[string1]);
 list[string1]=(char*)realloc(list[string1], strlen(list[string2])+1);
 strcpy(list[string1],list[string2]);
 strcpy(list[string2],temp);*/
}

void StringListInit(char ***list){
    (*list)= (char **)malloc(1);
    (*list)[0]=nullptr;
}

void StringListAdd(char** list, char* buffer){
    if (list[0]== nullptr){
        list[0]= (char*)malloc(strlen(buffer)+1);
        strcpy(list[0],buffer);
    } else {
        list= (char**)realloc(list,sizeof(char*)*(StringListSize(list)+1));
        list[StringListSize(list)]=(char*)malloc(strlen(buffer)+1);
        strcpy(list[StringListSize(list)],buffer);
    }
}

void DeleteString(char** list, int StringNumber){
    SwapStrings(list, StringNumber, StringListSize(list));
    list= (char**)realloc(list, StringListSize(list)-1);
    free(list[StringNumber]);
    strcpy(list[StringNumber]," ");

}


int FindString(char** list, char* CompareString){
    for (int i = 0; i < StringListSize(list); ++i) {
        if(!strcmp(list[i],CompareString)){
            return i;
        }
    }
    return -1;
}

void ShowList(char **list){
    std::cout<<"\n\t THE LIST IS ->\n";
    for (int i = 0; i < StringListSize(list); ++i) {
        puts(list[i]);
    }
}

void StringListDestroy(char*** list){
    for (int i = StringListSize(*list); i >= 0; --i) {
        free(*list[i]);
    }
    free(list);
}

void StringListRemoveDuplicates(char** list){
    for (int i = 0; i < StringListSize(list); ++i) {
        for (int j = i+1; j < StringListSize(list); ++j) {
            if (!strcmp(list[i],list[j])){
                DeleteString(list,j);
            }
        }
    }
}

void StringListReplaceInStrings(char** list, char* before, char* after){
    for (int i = 0; i < StringListSize(list); ++i){
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
    qsort(list, StringListSize(list), sizeof(const char*), myCompare);
}