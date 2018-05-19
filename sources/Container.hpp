#ifndef Container_H
#define Container_H
template<typename T>
class Container
{
public:
    // Виртуальные методы, будут реализованы далее
    virtual void insert(T value) = 0;
    virtual bool exists(T value) = 0;
    virtual void remove(T value) = 0;
    // Это потом заменим на перегруженный оператор <<
    virtual void print() = 0;

    // Виртуальный деструктор
    virtual ~Container();
    Container();
};

#endif
