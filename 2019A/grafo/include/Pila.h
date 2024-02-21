#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Pila
{
public:
    Pila<T>():index(0){};
    ~Pila<T>(){};
    bool empty();
    bool full();
    size_t size();
    const T& top();
    void push(const T& elem);
    void pop();

private:
    static const size_t CAPACITY=100;
    T elements[CAPACITY];
    size_t index;
};

template <typename T>
bool Pila<T>::empty()
{
    return index==0;
}

template <typename T>
bool Pila<T>::full()
{
    return index==CAPACITY;
}

template <typename T>
size_t Pila<T>::size()
{
    return index;
}

template <typename T>
const T& Pila<T>::top()
{
    if(empty())
        throw invalid_argument("Top() on empty stack");
    return elements[index-1];
}

template <typename T>
void Pila<T>::push(const T& elem)
{
    if(full())
        throw invalid_argument("Push() on full stack");
    elements[index]=elem;
    index++;
}

template <typename T>
void Pila<T>::pop()
{
    if(empty())
        throw invalid_argument("Pop() on empty stack");
    index--;
}

#endif // PILA_H_INCLUDED
