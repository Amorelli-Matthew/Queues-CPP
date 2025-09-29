#include "arraypriorityqueue.h"
#include "arrayqueue.h"
#include "event.h"
#include <iostream>
#include <fstream>

using namespace std;

int loadData(ifstream &input, ArrayPriorityQueue<Event> &EventPQueue);
int eventLoop(bool &tellerAvailable, ArrayPriorityQueue<Event> &EventPQueue, ArrayQueue<Event> &bankQueue);
void processArrival(bool &tellerAvailable, Event ArrivalEvent, ArrayPriorityQueue<Event> &EventPQueue, ArrayQueue<Event> &bankQueue);
int processDeparture(bool &tellerAvailable, Event DEvent, ArrayPriorityQueue<Event> &EventPQueue, ArrayQueue<Event> &bankQueue);

int main() {
    bool tellerAvailable = true;
    ArrayPriorityQueue<Event> EventPQueue;
    ArrayQueue<Event> bankQueue;

    ifstream input("input.txt");
    if (!input) {
        cerr << "Error opening file." << endl;
        return 1; // Exit if the file cannot be opened
    }

    int ec = loadData(input, EventPQueue);
    
    cout << "Simulation Begins" << endl;

    int wwt = eventLoop(tellerAvailable, EventPQueue, bankQueue);
    cout << "Simulation Ends" << endl << endl;

    double time = (wwt) / ec; 
    cout << "Final Statistics: " << endl;
    cout << "Total number of people processed: " << ec << endl;
    cout << "Average amount of time spent waiting: " << time << endl;

    return 0;
}

int loadData(ifstream &input, ArrayPriorityQueue<Event> &EventPQueue) {
    int arrival;
    int transaction;
    int counter = 0;

    while (input >> arrival >> transaction) {
        Event event("Arrival", arrival, transaction);
        EventPQueue.enqueue(event, arrival);
        counter++;
    }

    return counter;
}

int eventLoop(bool &tellerAvailable, ArrayPriorityQueue<Event> &EventPQueue, ArrayQueue<Event> &bankQueue) {
    int wT = 0;
    while (!EventPQueue.isEmpty()) {
        Event newEvent = EventPQueue.peekFront();
        int currentTime = newEvent.getTime();

        if (newEvent.getType() == "Arrival") {
            processArrival(tellerAvailable, newEvent, EventPQueue, bankQueue);
            cout << "Processing an arrival event at time: " << currentTime << endl;
        } else {
            wT += processDeparture(tellerAvailable, newEvent, EventPQueue, bankQueue);
        }
    }
    return wT;
}

void processArrival(bool &tellerAvailable, Event ArrivalEvent, ArrayPriorityQueue<Event> &EventPQueue, ArrayQueue<Event> &bankQueue) {
    EventPQueue.dequeue();

    if (bankQueue.isEmpty() && tellerAvailable) {
        int departureTime = ArrivalEvent.getTime() + ArrivalEvent.getDuration();
        cout << "Departure time of Customer C is: " << departureTime << endl;

        Event departure("Departure", departureTime, 0);
        EventPQueue.enqueue(departure, departureTime);
        tellerAvailable = false;
    } else {
        bankQueue.enqueue(ArrivalEvent);
    }
}

int processDeparture(bool &tellerAvailable, Event DEvent, ArrayPriorityQueue<Event> &EventPQueue, ArrayQueue<Event> &bankQueue) {
    int Wt = 0;
    EventPQueue.dequeue();

    cout << "Processing a departure event at time: " << DEvent.getTime() << endl;

    if (!bankQueue.isEmpty()) {
        Event customer = bankQueue.peekFront();
        Wt = DEvent.getTime() - customer.getTime();
        bankQueue.dequeue();

        int departureTime = customer.getTime() + customer.getDuration();
        cout << "Customer C begins transaction. Departure time of Customer C is: " << departureTime << endl;

        Event newDepartureEvent("Departure", departureTime, 0);
        EventPQueue.enqueue(newDepartureEvent, departureTime);
    } else {
        tellerAvailable = true;
    }

    return Wt;
}
