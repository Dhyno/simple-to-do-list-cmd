#include<iostream>
#include<cstring>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include"file_operation.h"

using namespace std;

write_file::write_file()
{
    ;
}

write_file::~write_file()
{
    memset(wrt_list,0,200);
    delete title;
}

void write_file::display()
{
    int chose;
    while(1)
    {
        cout<<"1.add to do list\n\n";
        cout<<"2.show to do list\n\n";
        cout<<"3.change to do list\n\n";
        cout<<"4.mark as done\n\n";
        cout<<"5.delete to do list\n\n";
        cout<<"6.exit\n\n";
        cout<<"choosen :";
        cin>>chose;
        system("cls");
        switch(chose)
        {
            case 1:
                create_file();
                break;

            case 2:
                show();
                break;

            case 3:
            case 4:
            case 5:
                change_mark_delete(chose);
                break;

            case 6:
                return;

            default:
                cin.clear();
                cin.ignore();
        }
    }
}

void write_file::create_file()
{
    ofstream out("to_do.txt",ios::app);
    char stop;

    title=new char[50];
    cout<<"Title : ";
    cin.ignore();
    cin.getline(title,50);
    out<<"------------------------------------------\n";
    out<<title<<endl;
    out<<"------------------------------------------\n";
    cout<<"\npress tab to stop\n";
    cout<<"---------------------\n\n";

    while(stop!=0x09)
    {
        cout<<"list : ";
        cin.getline(wrt_list,200);
        out<<wrt_list<<endl;
        memset(wrt_list,0,200);
        cout<<"stop? ";
        stop=getch();
    }

    out<<endl;
    out.close();
    system("cls");
}

void write_file::show()
{
    ifstream in("to_do.txt");
    char temp[200];

    if(!in)
        return;

    while(!in.eof())
    {
        in.getline(temp,200);
        cout<<temp<<endl;
    }
    cout<<endl;
    system("pause");
    system("cls");
}

void write_file::change_mark_delete(int value)//read to_do txt, write to temp txt till indeks and jump it,write to to_do txt
{
    ifstream in("to_do.txt");
    ofstream out("temp.txt");
    char temp[200];
    char input_title[100];
    char input_list[200];
    char to_change[200];
    int sub=0;
    int indeks_to_change=0;

    int counter=0;
    ////////////////////////////////////////
    if(!in)
        return;

    if(!out)
        out.ios::app;
    else
        out.ios::trunc;
    ////////////////////////////////////////
    while(!in.eof())//show to do list
    {
        in.getline(temp,200);
        cout<<temp<<endl;
    }
    cout<<endl;
    in.clear();
    in.seekg(ios::beg);
    cin.ignore();

    cout<<"choose title and list to change?\n\n";
    cout<<"input title :";
    cin.getline(input_title,100);
    cout<<"\ninput list :";
    cin.getline(input_list,200);

    while(!in.eof())//find indeks
    {
        in.getline(temp,200);

        if(sub)
        {
            indeks_to_change++;
            if(strcmp(temp,input_list)==0)
                break;
            continue;
        }

        if(strcmp(temp,input_title)==0)
            sub=1;
        indeks_to_change++;
    }
    if(in.eof())
    {
        cout<<"there is no title or list\n";
        return;
    }
    /////////value to change or mark///////
    if(value==3)
    {
        cout<<"change to do list : ";
        cin.getline(to_change,200);
    }
    else if(value==4)
        strcpy(to_change," <done>");
    /////////////////////////////////////

    in.clear();
    in.seekg(ios::beg);

    int mark=0;
    while(!in.eof())//write to temp
    {
        in.getline(temp,200);
        mark++;
        if(mark==indeks_to_change)
        {
            if(value==3)
                out<<to_change<<endl;
            else if(value==4)
                out<<temp<<to_change<<endl;
            continue;
        }
        out<<temp<<endl;
    }

    in.close();
    out.close();

    in.open("temp.txt",ios::app);
    out.open("to_do.txt",ios::trunc);

    int read_endl=0;
    while(!in.eof())//write to it own
    {
        in.getline(temp,200);

        if(strlen(temp)==0)
            read_endl++;
        else if(strlen(temp)!=0)
            read_endl--;

        if(read_endl<0)
            read_endl=0;

        if(read_endl==2)
        {
            out<<temp;
            break;
        }

        out<<temp<<endl;
    }
}

























