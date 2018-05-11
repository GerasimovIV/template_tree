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


template class Container<int>;
template class Container<float>;
template class Container<double>;
template class Container<long int>;
template class Container<unsigned int>;
template class Container<long long int>;
