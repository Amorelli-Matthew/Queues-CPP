#include "arrayqueue.h"
#include "queue.h"

template<class T>
bool ArrayQueue<T>::isEmpty() {
    return currentCount == 0;
}



template<class T>
bool ArrayQueue<T>::enqueue(const T& newEntry) {

if(currentCount ==  DEFAULT_CAPACITY)
{
    return false;
}
    
    if (isEmpty()) {
        back = 0; // Set back to zero if empty
    } else {
        back = (back + 1) % DEFAULT_CAPACITY; // Find the next space
    }

    Array[back] = newEntry; // Add the new entry
    currentCount++;
    return true;
}

template<class T>
bool ArrayQueue<T>::dequeue() {
    bool canDq = !isEmpty(); // Check if we can dequeue

    if (canDq) {
        front = (front + 1) % DEFAULT_CAPACITY;
        currentCount--; 
    }
    return canDq; 
}

template<class T>
T ArrayQueue<T>::peekFront() const
  {
 
    return Array[front]; 
}
