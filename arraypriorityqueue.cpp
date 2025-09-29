#include <iostream>
#include "arraypriorityqueue.h"

template<class T>
bool ArrayPriorityQueue<T>::enqueue(const T& newEntry, int priority) {
    if (currentCount >= DEFAULT_CAPACITY) {
        return false; // Queue is full
    }

    // Find the correct position to insert
    int insertIndex = 0;
    while (insertIndex < currentCount && array[(front + insertIndex) % DEFAULT_CAPACITY].priority <= priority) {
        insertIndex++;
    }

    // Shift elements to make room for the new item
    for (int i = currentCount; i > insertIndex; --i) {
        array[(front + i) % DEFAULT_CAPACITY] = array[(front + i - 1) % DEFAULT_CAPACITY];
    }

    int forFrontIndex = (front + insertIndex) % DEFAULT_CAPACITY;

    // Insert the new item
    array[forFrontIndex].value = newEntry;
    array[forFrontIndex].priority = priority;
    currentCount++;

    return true;
}

template<class T>
bool ArrayPriorityQueue<T>::dequeue() {
    if (isEmpty()) {
        return false; 
    }

    // Find the item with the highest priority (lowest value)
    int highestPriorityIndex = front;
    for (int i = 1; i < currentCount; ++i) {
        int index = (front + i) % DEFAULT_CAPACITY;
        if (array[index].priority < array[highestPriorityIndex].priority) {
            highestPriorityIndex = index;
        }
    }

    // Shift items to remove the highest priority item
    for (int i = highestPriorityIndex; i != (front + currentCount - 1) % DEFAULT_CAPACITY; 
         i = (i + 1) % DEFAULT_CAPACITY) {
        array[i] = array[(i + 1) % DEFAULT_CAPACITY];
    }

    currentCount--;

    return true;
}

template<class T>
T ArrayPriorityQueue<T>::peekFront() const {

    
    // Find the item with the highest priority (lowest value)
    int highestPriorityIndex = front;
    for (int i = 1; i < currentCount; ++i) {
        int index = (front + i) % DEFAULT_CAPACITY;
        if (array[index].priority < array[highestPriorityIndex].priority) {
            highestPriorityIndex = index;
        }
    }

    return array[highestPriorityIndex].value; // Return the front item
}