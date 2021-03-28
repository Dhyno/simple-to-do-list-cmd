#ifndef NODE_OPERATION_H
#define NODE_OPERATION_H

#include"node_item.h"
#include"node_path.h"

class write_node{

    node_title* head_t;
    node_list* head_l;

public:

    write_node();
    ~write_node();

    void display();

    void create_title();
    void create_list();
    void show();
    void change();
    void mark();
    void del_list();
    void delete_all();
};

#endif // NODE_OPERATION_H
