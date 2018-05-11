#include <iostream>
#include "Container.hpp"

using std::cout;
using std::endl;
template<typename T>
Container<T>::Container()
{
    cout << "Container created" << endl;
}
template<typename T>
Container<T>::~Container() { }
