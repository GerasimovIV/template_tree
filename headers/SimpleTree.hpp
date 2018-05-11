#ifndef SimpleTree_H
#define SimpleTree_H

#include "Container.hpp"
template<typename T>
struct tree {
    T value;
    int hight;
    struct tree* left;
    struct tree* right;
};

template<typename T>
class SimpleTree: public Container
{
public:
    SimpleTree();
    ~SimpleTree();
    void insert(T value);
    bool exists(T value);
    void remove(T value);
    void print();

protected:
    struct tree<T>* create(T i);
    struct tree<T>* find(T i);
    struct tree<T>* root;
    void insert_into_tree(struct tree<T>* Head, struct tree<T>* element);
    struct tree<T>* search_by_value(struct tree<T>* Head, T val);
    void delete_element_tree(struct tree<T>** Head, struct tree<T>* el_del);
    void delete_struckt(struct tree<T>* Head);
    struct tree<T>* search_head_for_delete(struct tree<T>* Head, struct tree<T>* el_del);
    void print_tree(struct tree<T>* Head);
    struct tree<T>* balance_tree(struct tree<T>* node);
    void balance(struct tree<T>* node, struct tree<T>** Head);
    void small_left_rotation(struct tree<T>* node_a);
    void big_left_rotation(struct tree<T>* node_a);
    void big_right_rotation(struct tree<T>* node_a);
    void small_right_rotation(struct tree<T>* node_a);
    int get_hight_for_me(struct tree<T>* node);
    int get_hight(struct tree<T>* node);
    void change_hight(struct tree<T>* Position);
    void print_tree_with_hight (struct tree<T>* Position);
    void Balance_tree_polzovatel();
};


#endif
