#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

struct Event {
    std::string eventType; // Traffic accident, Power failure, Network overload, Weather alert
    std::string description;
    long long timestamp;

    bool operator<(const Event& other) const {
        return timestamp < other.timestamp;
    }
    
    bool operator==(const Event& other) const {
        return eventType == other.eventType && description == other.description && timestamp == other.timestamp;
    }
};

struct EmergencyEvent {
    std::string emergencyType;
    std::string description;
    long long timestamp;
    int severityLevel; // higher is worse
};

class EventProcessor {
private:
    std::queue<Event> eventQueue;
    std::stack<EmergencyEvent> emergencyStack;
    int eventsProcessed;
    std::vector<int> responseTimes;
    std::map<std::string, int> emergencyCounts;

public:
    EventProcessor() : eventsProcessed(0) {}

    void addEvent(const Event& e);
    void addEmergency(const EmergencyEvent& e);
    void processEvents();
    
    int getEventsProcessed() const { return eventsProcessed; }
    
    // For algorithms requirement 
    void filterAndPrioritizeEvents(std::vector<Event>& incomingEvents);
    
    // For analytics
    void recordResponseTime(int time);
    void recordEmergency(const std::string& type);
    double getAverageResponseTime() const;
    std::string getMostCommonEmergency() const;
};

#endif // EVENTSYSTEM_H
