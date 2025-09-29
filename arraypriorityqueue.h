#ifndef ARRAYPRIORITYQUEUE_H
#define ARRAYPRIORITYQUEUE_H

#define DEFAULT_CAPACITY 100

template<class T>
class ArrayPriorityQueue {
private:
    struct Item {
        T value;
        int priority;
    };

    Item array[DEFAULT_CAPACITY];
    int currentCount;
   int front;
   int back;

public:
   ArrayPriorityQueue() : front(0), back(0), currentCount(0) {}
   
   //works better here than other method
    bool isEmpty() const 
    {
       return currentCount == 0;
    }
    
    bool enqueue(const T& newEntry, int priority);
    bool dequeue();
    T peekFront() const;
    
};
#include "arraypriorityqueue.cpp"
#endif
