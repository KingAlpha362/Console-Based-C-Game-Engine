#ifndef CITYDATA_H
#define CITYDATA_H

#include <string>
#include <vector>
#include <list>

struct SensorReading {
    int sensorID;
    std::string type; // e.g., "Power", "Temperature"
    double value;
    long long timestamp;

    bool operator<(const SensorReading& other) const {
        return value < other.value;
    }
};

struct CityLog {
    std::string logMessage;
    long long timestamp;

    bool operator==(const CityLog& other) const {
        return timestamp == other.timestamp && logMessage == other.logMessage;
    }
};

class CityData {
private:
    std::vector<SensorReading> dailyReadings;
    std::list<CityLog> historicalLogs;

public:
    void insertSensorReading(const SensorReading& reading);
    void insertCityLog(const CityLog& log);
    void removeOutdatedData(long long beforeTimestamp);
    void displayData() const;

    const std::vector<SensorReading>& getReadings() const { return dailyReadings; }
    std::vector<SensorReading>& getReadingsRef() { return dailyReadings; }
    const std::list<CityLog>& getLogs() const { return historicalLogs; }
};

#endif // CITYDATA_H
