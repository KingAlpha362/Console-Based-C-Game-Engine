#ifndef CITYCOMPONENT_H
#define CITYCOMPONENT_H

#include <string>
#include <iostream>

class CityComponent {
private:
    int componentID;
    std::string name;
    bool isActive;

public:
    CityComponent(int id, std::string n);
    virtual ~CityComponent() {}

    virtual void activate();
    virtual void deactivate();
    virtual std::string getStatus() const;
    
    virtual void processEvent() = 0; // Pure virtual function
};

class PowerSystem : public CityComponent {
private:
    double powerLevel;
public:
    PowerSystem(int id, std::string n, double pLevel);
    void supplyPower();
    void processEvent() override;
};

class TransportSystem : public CityComponent {
private:
    int trafficFlow;
public:
    TransportSystem(int id, std::string n, int flow);
    void manageTraffic();
    void processEvent() override;
};

class HealthSystem : public CityComponent {
private:
    int hospitalCnt;
public:
    HealthSystem(int id, std::string n, int count);
    void provideCare();
    void processEvent() override;
};

class SecuritySystem : public CityComponent {
private:
    int threatLevel;
public:
    SecuritySystem(int id, std::string n, int threat);
    void monitorCity();
    void processEvent() override;
};

#endif // CITYCOMPONENT_H
