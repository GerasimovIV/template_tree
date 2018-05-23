#include <iostream>
#include "SimpleTree.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using std::cout;
using std::endl;


template<typename T>
SimpleTree<T>::SimpleTree()
{
    this->root = NULL;
    this->schetchik = 0;
}


template<typename T>
void SimpleTree<T>::delete_struckt(struct tree<T>* Position)
{
    if (Position != NULL)
    {
        if (Position->left != NULL)
        {
            delete_struckt(Position->left);
        }

        if (Position->right != NULL)
        {
            delete_struckt(Position->right);
        }
            free(Position);
    }
}

template<typename T>
SimpleTree<T>::~SimpleTree()
{
    delete_struckt(this->root);
}

template<typename T>
struct tree<T>* SimpleTree<T>::create(T value)
{
    struct tree<T>* Head = (struct tree<T>*)malloc(sizeof(struct tree<T>));
    Head->value = value;
    Head->right = NULL;
    Head->left = NULL;
    return Head;
}
template<typename T>
void SimpleTree<T>::insert_into_tree(struct tree<T>* Head, struct tree<T>* element)
{
        int t = 0;
    //printf("in func %d\n", Head->value);
    if (Head->value <= element->value)
    {
                t = 0;
        if (Head->right == NULL)
        {
            Head->right = element;
            Head = Head->right;
                        t = 1;
            //printf("add element %d\n", Head->value);
        }
        if ((Head->right != NULL)&&(t != 1))
        {
            insert_into_tree(Head->right, element);
        }
    }


    if (Head->value > element->value)
    {
                t = 0;
        if (Head->left == NULL)
        {
            Head->left = element;
            Head = Head->left;
                        t = 1;
            //printf("add element %d\n", Head->value);
        }
        if ((Head->left != NULL)&&(t != 1))
        {
            insert_into_tree(Head->left, element);
        }
    }


}
template<typename T>
void SimpleTree<T>::insert(T value)
{
    struct tree<T>* element = this->create(value);
    if (this->root == NULL)
    {
        this->root = element;
    }
    else
    {
        insert_into_tree(this->root, element);
    }
//    cout << "!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//    cout << value << endl;
//    this->print();
//    cout << "!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    Balance_tree_polzovatel();
    this->schetchik += 1;
    this->schet = 0;
}
template<typename T>
struct tree<T>* SimpleTree<T>::search_by_value(struct tree<T>* Head, T val)
{
    struct tree<T>* rezult;
    if (Head->value == val)
    {
        return Head;
    }
    if (Head->value < val)
    {
        if (Head->right == NULL)
        {
            return NULL;
        }
        if (Head->right != NULL)
        {
            rezult = search_by_value(Head->right, val);
        }
    }


    if (Head->value > val)
    {
        if (Head->left == NULL)
        {
            return NULL;
        }
        if (Head->left != NULL)
        {
            rezult = search_by_value(Head->left, val);
        }
    }
    return rezult;
}
template<typename T>
struct tree<T>* SimpleTree<T>::find(T value)
{
    return search_by_value(this->root, value);
}
template<typename T>
bool SimpleTree<T>::exists(T value)
{
    if (this->root == NULL)
    {
        return false;
    }
    struct tree<T>* el_for_find = this->find(value);
    return el_for_find != NULL;

}

template<typename T>
void SimpleTree<T>::remove(T value)
{
    if (this->root == NULL)
    {
        cout << "I can not delete element from empty tree" << endl;
    }
    else
    {
        struct tree<T>* el_del = this->find(value);
        if (el_del != NULL)
        {
            delete_element_tree(&this->root, el_del);
//            if (this->root != NULL)
//            {
//                Balance_tree_polzovatel();
//                this->schetchik -= 1;
//            }
        }
    }

}

template<typename T>
struct tree<T>* SimpleTree<T>::search_head_for_delete(struct tree<T>* Head, struct tree<T>* el_del)
{
    struct tree<T>* rezult = NULL;
    if (Head->left == el_del)
    {
        return Head;
    }

    if (Head->right == el_del)
    {
        return Head;
    }
    if (Head->value <= el_del->value)
    {
        if (Head->right == NULL)
        {
            return NULL;
        }
        if (Head->right != NULL)
        {
            rezult = search_head_for_delete(Head->right, el_del);
        }
    }


    if (Head->value > el_del->value)
    {
        if (Head->left == NULL)
        {
            return NULL;
        }
        if (Head->left != NULL)
        {
            rezult = search_head_for_delete(Head->left, el_del);
        }
    }
    return rezult;
}
template<typename T>
void SimpleTree<T>::delete_element_tree(struct tree<T>** Head, struct tree<T>* el_del)
{
    if ((*Head) == el_del)
    {
        if (((*Head)->left == NULL) && ((*Head)->right == NULL))
        {
            this->root = NULL;
            free(*Head);
        }
        else
        {
            struct tree<T>* new_Head = this->root;
            this->search_head_for_balance(this->root, &new_Head);
//            cout<<"1111111111111111 "<< new_Head->value << endl;
            struct tree<T>* prev = search_head_for_delete(*Head, new_Head);
//            cout<<"2222222222222222 "<< prev->value << endl;
            if (prev->value <= new_Head->value)
            {
                prev->right = NULL;
            }
            else
            {
                prev->left = NULL;
            }
            insert_into_tree(new_Head, (*Head)->left);
            insert_into_tree(new_Head, (*Head)->right);
            this->root = new_Head;
            balance(new_Head, &new_Head);


        }

    }
    else
    {
        struct tree<T>* s;
        s = search_head_for_delete((*Head), el_del);
                int t = 0;
        if ((t != 1) && (el_del->left == NULL) && (el_del->right == NULL))
        {
            if (s->value <= el_del->value)
            {
                s->right = NULL;
            }
            else
            {
                s->left = NULL;
            }
            free(el_del);
                        t = 1;
        }
        if ((t != 1) && (el_del->right == NULL) && (el_del->left != NULL))
        {
            if (s->value <= el_del->value)
            {
                s->right = el_del->left;
            }
            if (s->value > el_del->value)
            {
                s->left = el_del->left;
            }
            free(el_del);
                        t = 1;
        }
        if ((t != 1) && (el_del->right != NULL) && (el_del->left == NULL))
        {
            if (s->value <= el_del->value)
            {
                s->right = el_del->right;
            }
            if (s->value > el_del->value)
            {
                s->left = el_del->right;
            }
            free(el_del);
                        t = 1;
        }
        if ((t != 1) && (el_del->right != NULL) && (el_del->left != NULL))
        {
            if (s->value <= el_del->value)
            {
                s->right = el_del->left;
                insert_into_tree(s->right, el_del->right);
            }
            if (s->value > el_del->value)
            {
                s->left = el_del->left;
                insert_into_tree(s->left, el_del->right);
            }
            free(el_del);
                        t = 1;
        }
    }
}
template<typename T>
int SimpleTree<T>::get_hight(struct tree<T>* node)
{
    if (node == NULL)
    {
        return 0;
    }
    if ((node->left == NULL) && (node->right == NULL))
        return 0;
    else
    {
        if (get_hight(node->right) <= get_hight(node->left))
        {
            return  get_hight(node->left) + 1;
        }
        if (get_hight(node->right) > get_hight(node->left))
        {
            return get_hight(node->right) + 1;
        }
    }
    return 0;
}

template<typename T>
void SimpleTree<T>::change_hight(struct tree<T>* Position)
{
    if (Position->left != NULL)
    {
        change_hight(Position->left);
    }
    Position->hight = get_hight(Position);
    if (Position->right != NULL)
    {
        change_hight(Position->right);
    }
}

template<typename T>
void SimpleTree<T>::small_left_rotation(struct tree<T>* node_a)
{
        struct tree<T>* node_b = node_a->right;
        node_a->right = node_b->left;
        node_b->left = node_a;
}

template<typename T>
void SimpleTree<T>::big_left_rotation(struct tree<T>* node_a)
{
        struct tree<T>* node_b = node_a->right;
        struct tree<T>* node_c = node_b->left;
        node_a->right = node_c->left;
        node_b->left = node_c->right;
        node_c->left = node_a;
        node_c->right = node_b;
}

template<typename T>
void SimpleTree<T>::big_right_rotation(struct tree<T>* node_a)
{
        struct tree<T>* node_b = node_a->left;
        struct tree<T>* node_c = node_b->right;
        node_a->left = node_c->right;
        node_b->right = node_c->left;
        node_c->left = node_b;
        node_c->right = node_a;
}


template<typename T>
void SimpleTree<T>::small_right_rotation(struct tree<T>* node_a)
{
        struct tree<T>* node_b = node_a->left;
        node_a->left = node_b->right;
        node_b->right = node_a;
}

template<typename T>
int SimpleTree<T>::get_hight_for_me(struct tree<T>* node)
{
        if (node == NULL)
        {
                return -1;
        }
        return node->hight;
}

template<typename T>
void SimpleTree<T>::search_head_for_balance(struct tree<T>* Head, struct tree<T>** new_Head)
{
    if (Head->left != NULL)
    {
        search_head_for_balance(Head->left, new_Head);
    }
    if (this->root != Head)
    {
        this->schet += 1;
    }
    if (this->schet == (this->schetchik / 2) + (this->schetchik % 2) )
    {
//        cout << this->schet << " " << Head->value << endl;
        *new_Head = Head;
    }

    if (Head->right != NULL)
    {
        search_head_for_balance(Head->right, new_Head);
    }
}
/*
template<typename T>
void SimpleTree<T>::proverka(struct tree<T>* node, struct tree<T>** Head)
{
    if (node->right == NULL && node->left != NULL)
    {
        struct tree<T>* prev = search_head_for_delete(*Head, node);

        if(node != *Head)
        {
            if (node->value < prev->value)
            {
                prev->left = node->left;
            }
            else
            {
                prev->right = node->left;
            }
            insert_into_tree(this->root, node);
            node->left = NULL;
            node->right = NULL;
            change_hight(this->root);
        }

    }
    if (node->right != NULL && node->left == NULL)
    {
        struct tree<T>* prev = search_head_for_delete(*Head, node);
        if(node != *Head)
        {
            if (node->value < prev->value)
            {
                prev->left = node->right;
            }
            else
            {
                prev->right = node->right;
            }
            insert_into_tree(this->root, node);
            node->left = NULL;
            node->right = NULL;
            change_hight(this->root);
        }
    }
}
*/
template<typename T>
void SimpleTree<T>::balance(struct tree<T>* node, struct tree<T>** Head)//передаем head, head второй понадобтся позже
{

//        cout << node->value << endl;
//        this->print();
//        printf("Head:%d 1: %d\n",(*Head)->value, node->value);
        if (node->left != NULL)
        {
                //printf("Head:%d 2: %d\n",(*Head)->value, node->value);
                balance(node->left, Head);
        }
        if (node->right != NULL)
        {
                //printf("Head:%d 2*: %d\n",(*Head)->value, node->value);
                balance(node->right, Head);
                //printf("Head:%d 2**: %d\n",(*Head)->value, node->value);
        }
        change_hight(*Head);


//        cout << node->value << endl;
        if (abs(get_hight_for_me(node->left) - get_hight_for_me(node->right)) >=2 )
        {
                int t = 0;
                //printnf("%d %d", )

                if ( (t != 1) && (abs(get_hight_for_me(node->right)-get_hight_for_me(node->left)) >= 2) && (get_hight_for_me(node->right->left) <= get_hight_for_me(node->right->right)))
                {
                        //малое левое вращение

                        struct tree<T>* prev = search_head_for_delete(*Head, node);

                        //printf("%d", prev->value);
                        if (prev != NULL)
                        {
                                //узнаем расположение prev и node
                                if (prev->value <= node->value)
                                {
                                        prev->right = node->right;
                                }
                                else
                                {
                                        prev->left = node->right;
                                }
                                small_left_rotation(node);
                                change_hight(*Head);
                                t = 1;
                        }
                        else
                        {

                                *Head = node->right;
                                small_left_rotation(node);
                                change_hight(*Head);
                                t = 1;

                        }
                }
                if ((t != 1) && (abs(get_hight_for_me(node->left) - get_hight_for_me(node->right)) >= 2) && (get_hight_for_me(node->left->right) <= get_hight_for_me(node->left->left)))
                {
                        //малое правое вращение
                        struct tree<T>* prev = search_head_for_delete(*Head, node);
                        if (prev != NULL)
                        {
                                //узнаем расположение prev и node
                                if (prev->value <= node->value)
                                {
                                        prev->right = node->left;
                                }
                                else
                                {
                                        prev->left = node->left;
                                }
                                small_right_rotation(node);
                                change_hight(*Head);
                                t = 1;
                        }
                        else
                        {
                                *Head = node->left;
                                small_right_rotation(node);
                                change_hight(*Head);
                                t = 1;
                        }
                }
                if ((t != 1) && (abs(get_hight_for_me(node->left) - get_hight_for_me(node->right)) >= 2) && (get_hight_for_me(node->right->left) > get_hight_for_me(node->right->right)))
                {
                        //большое левое вращение
                        struct tree<T>* prev = search_head_for_delete(*Head, node);
                        if (prev != NULL)
                        {
                                //узнаем расположение prev и node
                                if (prev->value <= node->value)
                                {
                                        prev->right = node->right->left;
                                }
                                else
                                {
                                        prev->left = node->right->left;
                                }
                                big_left_rotation(node);
                                change_hight(*Head);
                                t = 1;
                        }
                        else
                        {
                                *Head = node->right->left;
                                big_left_rotation(node);
                                change_hight(*Head);
                                t = 1;
                        }

                }

                if ((t != 1) && (abs(get_hight_for_me(node->left) - get_hight_for_me(node->right)) >= 2) && (get_hight_for_me(node->left->right) > get_hight_for_me(node->left->left)))
                {
                        //большое правое вращение
                        struct tree<T>* prev = search_head_for_delete(*Head, node);
                        if (prev != NULL)
                        {
                                //узнаем расположение prev и node
                                if (prev->value <= node->value)
                                {
                                        prev->right = node->left->right;
                                }
                                else
                                {
                                        prev->left = node->left->right;
                                }
                                big_right_rotation(node);
                                change_hight(*Head);
                                t = 1;
                        }
                        else
                        {
                                *Head = node->left->right;
                                big_right_rotation(node);
                                change_hight(*Head);
                                t = 1;
                        }
                }
//                change_hight(*Head);
//                printf("%d\n", node->value);
//                printf("??????????????????????????\n");
//                this->print();
//                printf("??????????????????????????\n");
        }


        if (node->right != NULL)
        {
                //printf("Head:%d 2*: %d\n",(*Head)->value, node->value);
                balance(node->right, Head);
                //printf("Head:%d 2**: %d\n",(*Head)->value, node->value);
        }



}

template<typename T>
struct tree<T>* SimpleTree<T>::balance_tree(struct tree<T>* Head)
{

        struct tree<T>* Head1 = Head;
        balance(Head, &Head1);
        change_hight(Head1);

//        while (Head != Head1)
//        {
//                Head = Head1;
//                balance(Head, &Head1);
//                change_hight(Head1);
//        }


        return Head1;
}
template<typename T>
void SimpleTree<T>::Balance_tree_polzovatel()
{
        if (this->root == NULL)
        {
                printf("Error: Can not make balance for empty tree!\n");
        }
        else
        {
            change_hight(this->root);
//            printf("??????????????????????????\n");
//            this->print();
//            printf("??????????????????????????\n");
            this->root = balance_tree(this->root);
        }
}

template<typename T>
void SimpleTree<T>::print_tree_with_hight (struct tree<T>* Position)
{
    if (Position->left != NULL)
    {
        print_tree_with_hight(Position->left);
    }
    cout << "value:"<<Position->value<< " height:" <<Position->hight<< endl;
    if (Position->right != NULL)
    {
        print_tree_with_hight(Position->right);
    }
}

template<typename T>
void SimpleTree<T>::print()
{
        if (this->root != NULL)
        {
                change_hight(this->root);
                print_tree_with_hight(this->root);
        }
        else
        {
                printf("Error: empty tree!");
        }
}


template class SimpleTree<int>;
template class SimpleTree<float>;
template class SimpleTree<double>;
template class SimpleTree<long int>;
template class SimpleTree<unsigned int>;
template class SimpleTree<long long int>;
