#include <iostream>
#include "SystemSimulation.h"

int main() {
    SystemSimulation simulation;
    simulation.loadSystemState();

    std::string id, pass;
    std::cout << "NeoVerse AI City Survival System\n";
    std::cout << "Please log in.\n";
    
    // simple login loop
    while (true) {
        std::cout << "Engineer ID: ";
        std::cin >> id;
        std::cout << "Password: ";
        std::cin >> pass;

        if (simulation.authenticate(id, pass)) {
            break;
        }
    }

    // Populate with data and run
    simulation.generateSampleData();
    simulation.runSimulation();

    // Persist data
    simulation.saveSystemState();
    simulation.exportLogsToCSV();

    std::cout << "Simulation ended successfully.\n";
    return 0;
}
