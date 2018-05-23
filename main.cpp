#include <iostream>
#include <stdio.h>
#include "SimpleTree.hpp"

using namespace std;
/*
int main()
{
    Container<int>* c = new SimpleTree<int>();
    c->remove(5);
    delete c;
    return 0;
}
*/
/*
int main() 
{
    Container<int>* c = new SimpleTree<int>(); //Container<int> c;

    for(int i = 1; i < 10; i++)
    {
        c->insert(i*i);
    }

    printf("List after creation:\n");
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    cout << "Tree after deletion of the element:" << endl;
    c->print();
    delete c;
    return 0;
}*/
/*
int main()
{
    Container<int>* c = new SimpleTree<int>();
    c->insert(1);
    c->insert(2);
    c->print();

    c->remove(1);
    c->print();

    delete c;
    return 0;
}
*/

template<typename T>
class DebugTree: public SimpleTree<T>
{
    void print()
    {
        tree<T>* cur_element = this->root;
        printSubTree(cur_element);
    }

    void printSubTree(tree<T>* cur_element)
    {
        cerr << "Element: " << cur_element->value << " ";
        cerr << "Height: " << cur_element->hight << " ";

        if(cur_element->left != nullptr)
            cerr << "Left: " << cur_element->left->value << " ";
        else
            cerr << "Left: -- ";

        if(cur_element->right != nullptr)
            cerr << "Right: " << cur_element->right->value << " ";
        else
            cerr << "Right: -- ";

        cerr << endl;

        if (cur_element-> left != nullptr)
            printSubTree(cur_element->left);

        if (cur_element-> right != nullptr)
            printSubTree(cur_element->right);
    }
};

int main()
{
    Container<int>* c = new DebugTree<int>();

    for(int i = 1; i < 9; i++)
        c->insert(i*i);


    cerr << "Tree after creation:" << endl;
    c->print();
//    cout<<"******************************************************************"<<endl;

    c->remove(16);

    //c->Balance_tree_polzovatel();
    cerr << "Tree after deletion of the element:" << endl;
    c->print();
//    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    delete c;
    return 0;
}
