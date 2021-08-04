#include "ListString.h"
#include <iostream>

int main() {
    char **list;

    StringListInit(&list);
    char buffer[30];
    gets(buffer);
    StringListAdd(list,buffer);
    /*puts(list[0]);*/
    gets(buffer);
    StringListAdd(list,buffer);
    /*puts(list[1]);*/
    gets(buffer);
    StringListAdd(list,buffer);
    /*puts(list[2]);*/
    std::cout<< sizeof(list)<<std::endl;
    std::cout<<"\n There are "<<StringListSize(list)<<" strings in list";
    ShowList(list);
    gets(buffer);

    if (FindString(list,buffer)!=-1){
        std::cout<<"\nWe found it in position -> "<<FindString(list,buffer);
    } else std::cout<<"There is no such string in the list";

    DeleteString(list,2);
    ShowList(list);
    std::cout<<"\n There are "<<StringListSize(list)<<" strings in list";

    return 0;
}


