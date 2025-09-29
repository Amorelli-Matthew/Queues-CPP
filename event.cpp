#include "event.h"
#include <iostream>

// Constructor
Event::Event(const string& type, int time, int duration)
    : type(type), time(time), duration(duration) {}

// Getters
string Event::getType() const {
     return type;
      }
int Event::getTime() const {
     return time;
      }
int Event::getDuration() const {
     return duration;
      }

// Setters
void Event::setType(const string& t) {
     type = t;
      }

void Event::setTime(int t) {
     time = t;
      }

void Event::setDuration(int d) 
{
     duration = d; 
     }

bool Event::operator>( const Event& rhs) {
    if (rhs.type != rhs.type) {
        return type > rhs.type; // Compare by type
    }
    if (time != rhs.time) {
        return time > rhs.time; // If types are equal, compare by time
    }
    return duration > rhs.duration; // If both type and time are equal, compare by duration
}