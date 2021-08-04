#include "ListString.h"
#include <iostream>

int main() {
    char **list;

    StringListInit(&list);
    char buffer[30];
    gets(buffer);
    StringListAdd(list,buffer);
    gets(buffer);
    StringListAdd(list,buffer);
    gets(buffer);
    StringListAdd(list,buffer);
    std::cout<<"\n There are "<<StringListSize()<<" strings in list";
    ShowList(list);

    /*gets(buffer);

    if (FindString(list,buffer)!=-1){
        std::cout<<"\nWe found it in position -> "<<FindString(list,buffer)<<std::endl;
    } else std::cout<<"There is no such string in the list";*/

    DeleteString(list,1);
    ShowList(list);
    std::cout<<"\n There are "<<StringListSize()<<" strings in list";

    return 0;
}


