#include "EventSystem.h"
#include <numeric>

void EventProcessor::addEvent(const Event& e) {
    eventQueue.push(e);
}

void EventProcessor::addEmergency(const EmergencyEvent& e) {
    emergencyStack.push(e);
}

void EventProcessor::processEvents() {
    // Process emergencies first (LIFO)
    while (!emergencyStack.empty()) {
        EmergencyEvent e = emergencyStack.top();
        emergencyStack.pop();
        std::cout << "[EMERGENCY OVERRIDE] Resolving: " << e.emergencyType 
                  << " - " << e.description << " (Severity: " << e.severityLevel << ")\n";
        eventsProcessed++;
        recordEmergency(e.emergencyType);
        recordResponseTime(e.severityLevel * 2); // mock response time based on severity
    }

    // Process normal events next (FIFO)
    while (!eventQueue.empty()) {
        Event e = eventQueue.front();
        eventQueue.pop();
        std::cout << "[NORMAL EVENT] Processing: " << e.eventType 
                  << " - " << e.description << "\n";
        eventsProcessed++;
        recordResponseTime(5); // mock normal response time
    }
}

void EventProcessor::filterAndPrioritizeEvents(std::vector<Event>& incomingEvents) {
    // Example use of algorithm to sort events by timestamp before adding to queue
    std::sort(incomingEvents.begin(), incomingEvents.end());
    
    for (const auto& e : incomingEvents) {
        addEvent(e);
    }
}

void EventProcessor::recordResponseTime(int time) {
    responseTimes.push_back(time);
}

void EventProcessor::recordEmergency(const std::string& type) {
    emergencyCounts[type]++;
}

double EventProcessor::getAverageResponseTime() const {
    if (responseTimes.empty()) return 0.0;
    double sum = std::accumulate(responseTimes.begin(), responseTimes.end(), 0.0);
    return sum / responseTimes.size();
}

std::string EventProcessor::getMostCommonEmergency() const {
    if (emergencyCounts.empty()) return "None";
    
    auto it = std::max_element(emergencyCounts.begin(), emergencyCounts.end(), 
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second < b.second;
        });
        
    return it->first;
}
