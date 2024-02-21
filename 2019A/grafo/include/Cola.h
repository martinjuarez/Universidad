#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
#include<stdexcept>

using namespace std;

template <typename T>
class Cola
{
public:
    Cola<T>():
        front_index(0),
        back_index(0),
        queue_size(0)
        {}
    bool full();
    bool empty();
    size_t size();
    const T& front();
    const T& back();
    void push(const T& elem);
    void pop();

private:
    static const size_t CAPACITY = 1000;

    size_t front_index,back_index,queue_size;
    T elements[CAPACITY];
};

template <typename T>
bool Cola<T>::full()
{
    return queue_size==CAPACITY;
}

template <typename T>
bool Cola<T>::empty()
{
    return queue_size==0;
}

template <typename T>
size_t Cola<T>::size()
{
    return queue_size;
}

template <typename T>
const T& Cola<T>::front()
{
    if(empty())
        throw invalid_argument("front() on empty queue");
    return elements[front_index];
}

template <typename T>
const T& Cola<T>::back()
{
    if(full())
        throw invalid_argument("back() on full queue");

    if(back_index==0)
        return elements[CAPACITY-1];
    else
        return elements[back_index-1];

}

template <typename T>
void Cola<T>::push(const T& elem)
{
    if (full())
        throw invalid_argument("Push() on full queue");

    elements[back_index]=elem;
    back_index=(back_index+1)%CAPACITY;
    queue_size++;
}

template <typename T>
void Cola<T>::pop()
{
    if(empty())
        throw invalid_argument("pop() on empty queue");

    front_index=(front_index+1)%CAPACITY;
    queue_size--;
}

#endif // COLA_H_INCLUDED
