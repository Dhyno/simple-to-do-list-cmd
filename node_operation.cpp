#include<iostream>
#include<windows.h>
#include<conio.h>
#include"node_operation.h"

using namespace std;

write_node::write_node()
{
    head_t=NULL;
    head_l=NULL;
}

write_node::~write_node()
{
    delete_all();
}

void write_node::display()
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
                create_title();
                break;

            case 2:
                show();
                break;

            case 3:
                change();
                break;

            case 4:
                mark();
                break;

            case 5:
                del_list();
                break;

            case 6:
                return;

            default:
                cin.clear();
                cin.ignore();
        }
    }
}

void write_node::create_title()
{
    cin.ignore();
    node_title* help=head_t;
    node_title* add=new node_title;
    add->title=new char[50];

    cout<<"Title    :";
    cin.getline(add->title,50);

    if(help==NULL)
    {
        add->next=NULL;
        head_t=add;
    }

    else
    {
        while(help->next!=NULL)
            help=help->next;
        add->next=NULL;
        help->next=add;
    }
    cout<<"press tab to stop\n";
    cout<<"-----------------\n";
    create_list();
}

void write_node::create_list()
{
    int n=0;
    node_list* help=head_l;
    node_list* add=new node_list;
    while(1)
    {
        add->buffer[n]=getch();
        cout<<add->buffer[n];
        if(add->buffer[n]==0x09 && n<499)
        {
            add->buffer[n]='\0';
            break;
        }
        if(add->buffer[n]==0x0D)
        {
            add->buffer[n]='\n';
            cout<<endl;
        }
        n+=1;
    }
    if(help==NULL)
    {
        add->next=NULL;
        head_l=add;
    }
    else
    {
        while(help->next!=NULL)
            help=help->next;
        add->next=NULL;
        help->next=add;
    }
    system("cls");
}

void write_node::show()
{
    node_list* help_l=head_l;
    node_title* help_t=head_t;
    while(help_t->next!=NULL && help_l->next!=NULL)
    {
        cout<<"--"<<help_t->title<<"--\n";
        cout<<"--------------------------\n\n";
        cout<<help_l->buffer<<endl<<endl;
        help_t=help_t->next;
        help_l=help_l->next;
    }
    cout<<"--"<<help_t->title<<"--\n";
    cout<<"--------------------------\n\n";
    cout<<help_l->buffer<<endl;
    system("pause");
    system("cls");
}

void write_node::change()
{
    int n;
    int m=1;
    char title[50];

    node_title* help=head_t;
    node_list* help_l=head_l;

    if(help==NULL||help_l==NULL)
        return;
    cout<<"1.Change Title\n\n";
    cout<<"2.Change List\n\n";
    cout<<"Choose   :";
    cin>>n;
    system("cls");

    cout<<"Title\n";
    cout<<"----------------\n\n";
    while(help->next!=NULL)
    {
        cout<<m<<". "<<help->title<<endl<<endl;
        help=help->next;
        m++;
    }
    cout<<m<<". "<<help->title<<endl<<endl;

    delete help;
    help=head_t;

    cout<<"choose title   :";
    cin.ignore();
    cin.getline(title,50);

    while(strcmp(title,help->title)!=0)
    {
        help=help->next;
        help_l=help_l->next;
    }

    if(n==1)
    {
        system("cls");
        memset(title,0,50);

        cout<<"New Title    : ";
        cin.getline(title,50);
        strcpy(help->title,title);

    }

    else if(n==2)//1.copy n indeks to temp 2.change buffer n till size of n input 3.put temp tu n after change buff
    {
        system("cls");
        m=1;
        int poin;
        int i;
        int j;
        int before=0;
        char temp[500];
        char temp_input[250];

        cout<<help->title<<endl;
        cout<<"---------------\n\n";
        cout<<m<<". ";

        for(i=0;i<strlen(help_l->buffer);i++)
        {
            if(help_l->buffer[i]=='\n')
            {
                m++;
                cout<<endl<<m<<". ";
                continue;
            }
            cout<<help_l->buffer[i];
        }
        m=0;
        cout<<"\n\nchose line number: ";
        cin>>poin;

        int now=0;
        for(i=0;i<strlen(help_l->buffer);i++)//get point of indeks
        {
            if(m==poin)
                break;

            if(help_l->buffer[i]=='\n')
            {
                before=now;
                now=i;
                m++;
            }

        }

        for(j=0;i<strlen(help_l->buffer);i++,j++)
            temp[j]=help_l->buffer[i];

        memset(help_l->buffer+(before+1),'\0',strlen(help_l->buffer));

        cout<<"change to do list :";
        cin.ignore();
        cin.getline(temp_input,250);

        for(i=before+1,j=0;j<strlen(temp_input);i++,j++)
            help_l->buffer[i]=temp_input[j];
        now=strlen(help_l->buffer);
        help_l->buffer[now]='\n';

        for(i=now+1,j=0;j<strlen(temp);i++,j++)
            help_l->buffer[i]=temp[j];
    }

    else
        cout<<"invalid input";

    system("cls");
}

void write_node::mark()
{
    int m=1;
    char title[50];
    char done;

    node_title* help_t=head_t;
    node_list* help_l=head_l;

    if(help_t==NULL||help_l==NULL)
        return;

    cout<<"Title\n";
    cout<<"----------------\n\n";
    while(help_t->next!=NULL)
    {
        cout<<m<<". "<<help_t->title<<endl<<endl;
        help_t=help_t->next;
        m++;
    }
    cout<<m<<". "<<help_t->title<<endl<<endl;

    cout<<"choose title   :";
    cin.ignore();
    cin.getline(title,50);

    delete help_t;
    help_t=head_t;

    while(strcmp(title,help_t->title)!=0)
    {
        help_t=help_t->next;
        help_l=help_l->next;
    }

    cout<<"mark "<<help_t->title<<" as done? Y/N : ";
    cin>>done;

    if(done=='y' || done=='Y')
    {
        char done[]=" <done>";
        m=strlen(help_t->title);
        help_t->title;
        for(int i=0;i<strlen(done);i++,m++)
            help_t->title[m]=done[i];
    }
    help_t->title[m]='\0';
    system("cls");
}

void write_node::del_list()
{
    node_title* help_t=head_t;
    node_title* help_t_before;
    node_list* help_l=head_l;
    node_list* help_l_before;
    char title[50];
    char title_done[50];
    char done[]=" <done>";
    int m;

    cout<<"choose title : ";
    cin.ignore();
    cin.getline(title,50);

    strcpy(title_done,title);
    m=strlen(title_done);
    for(int i=0;i<strlen(done);i++,m++)
        title_done[m]=done[i];
    title_done[m]='\0';

    if(help_t==NULL)
        return;

    else
    {
        while(help_t->next!=NULL)
        {
            if(strcmp(title,help_t->title)==0 || strcmp(title_done,help_t->title)==0)
                break;
            help_t_before=help_t;
            help_l_before=help_l;

            help_t=help_t->next;
            help_l=help_l->next;
        }

        delete help_t->title;
        memset(help_l->buffer,0,500);

        help_t_before->next=help_t->next;
        delete help_t;

        help_l_before->next=help_l->next;
        delete help_l;

    }
    system("cls");

}

void write_node::delete_all()
{
    node_title* help_t_before;
    node_list* help_l_before;

    while(head_t->next!=NULL)
    {
        help_t_before=head_t;
        help_l_before=head_l;

        head_t=head_t->next;
        head_l=head_l->next;

        help_t_before->next=NULL;
        help_l_before->next=NULL;
        delete help_t_before->title;
        memset(help_l_before->buffer,0,500);
        delete help_t_before;
        delete help_l_before;
    }
    delete head_t;
    delete head_l;

}

















