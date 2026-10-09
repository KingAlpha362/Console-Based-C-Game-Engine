#ifndef SYSTEMSIMULATION_H
#define SYSTEMSIMULATION_H

#include "Engineer.h"
#include "CityData.h"
#include "EventSystem.h"
#include "CityComponent.h"
#include <vector>
#include <string>

class SystemSimulation {
private:
    std::vector<Engineer> engineers;
    CityData cityData;
    EventProcessor eventProcessor;
    std::vector<CityComponent*> cityComponents;

public:
    SystemSimulation();
    ~SystemSimulation();

    // Authentication
    void loadEngineers();
    bool authenticate(const std::string& id, const std::string& password);

    // File I/O
    void saveSystemState();
    void loadSystemState();
    void exportLogsToCSV();

    // Simulation
    void generateSampleData();
    void runAnalytics();
    void runSimulation();
    
    // Algorithm showcases
    void showcaseAlgorithms();
};

#endif // SYSTEMSIMULATION_H
