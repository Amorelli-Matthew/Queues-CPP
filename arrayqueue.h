#ifndef QUEUE_INTERFACE 
#define QUEUE_INTERFACE
#define DEFAULT_CAPACITY 100
template<class T> 
class ArrayQueue { 
T Array[ DEFAULT_CAPACITY];

int front;

int back;
int currentCount;
public: 
     bool isEmpty();
    
     bool enqueue(const T &newEntry); 
     bool dequeue();
    T peekFront() const;
    
     
};

#include "arrayqueue.cpp"
#endif
