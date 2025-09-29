#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <ostream>
#include <istream> 
using namespace std; 

class Event {
private:
    string type;
    int time;
    int duration;

public:
    Event(const string& type = "", int time = 0, int duration = 0);

    string getType() const;
    int getTime() const;
    int getDuration() const;

    void setType(const string& type);
    void setTime(int time);
    void setDuration(int duration);

bool operator>( const Event& rhs);

};

#endif // EVENT_H
