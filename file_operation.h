#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H

class write_file{

    char* title;
    char wrt_list[200];
public:

    write_file();
    ~write_file();

    void display();

    void create_file();
    void show();
    void change_mark_delete(int);

};


#endif // FILE_OPERATION_H
