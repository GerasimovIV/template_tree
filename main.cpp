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

