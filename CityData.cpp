#include "CityData.h"
#include <iostream>

void CityData::insertSensorReading(const SensorReading& reading) {
    dailyReadings.push_back(reading);
}

void CityData::insertCityLog(const CityLog& log) {
    historicalLogs.push_back(log);
}

#include <algorithm>

void CityData::removeOutdatedData(long long beforeTimestamp) {
    // Erase-Remove Idiom for O(N) complexity
    dailyReadings.erase(
        std::remove_if(dailyReadings.begin(), dailyReadings.end(),
            [beforeTimestamp](const SensorReading& r) { return r.timestamp < beforeTimestamp; }),
        dailyReadings.end());

    // remove_if for list
    historicalLogs.remove_if([beforeTimestamp](const CityLog& log) { return log.timestamp < beforeTimestamp; });
}

void CityData::displayData() const {
    std::cout << "--- Daily Sensor Readings ---\n";
    for (const auto& reading : dailyReadings) {
        std::cout << "Sensor " << reading.sensorID << " [" << reading.type << "]: " 
                  << reading.value << " (Time: " << reading.timestamp << ")\n";
    }

    std::cout << "--- Historical City Logs ---\n";
    for (const auto& log : historicalLogs) {
        std::cout << "[Time " << log.timestamp << "] " << log.logMessage << "\n";
    }
}
