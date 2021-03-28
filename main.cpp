#include<iostream>
#include<conio.h>
#include<cstdlib>
#include"node_operation.h"
#include"file_operation.h"

using namespace std;

int main()
{
    write_node make_node;
    write_file make_file;
    char menu[2][15]={"node method","txt method"};
    int poin=0;
    char* get="->";
    char press;

    while(1)
    {
        cout<<"*******************************\n";
        cout<<"///////Simple To Do list///////\n";
        cout<<"*******************************\n\n";
        for(int i=0;i<2;i++)
        {
            if(poin==i)
                cout<<get<<menu[i]<<endl<<endl;
            else
                cout<<menu[i]<<endl<<endl;
        }

        press=getch();

        if(press=='w')
            poin-=1;
        else if(press=='s')
            poin+=1;
        else if(press==0x0D)
        {
            system("cls");
            if(poin)
                make_file.display();
            else
                make_node.display();
        }

        if(poin < 0)
            poin=1;
        else if(poin > 1)
            poin=0;
        system("cls");
    }
    return 0;
}
