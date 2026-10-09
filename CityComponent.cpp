#include "CityComponent.h"

CityComponent::CityComponent(int id, std::string n) : componentID(id), name(n), isActive(false) {}

void CityComponent::activate() {
    isActive = true;
    std::cout << name << " (ID: " << componentID << ") activated.\n";
}

void CityComponent::deactivate() {
    isActive = false;
    std::cout << name << " (ID: " << componentID << ") deactivated.\n";
}

std::string CityComponent::getStatus() const {
    return name + " is " + (isActive ? "ONLINE" : "OFFLINE");
}


PowerSystem::PowerSystem(int id, std::string n, double pLevel) : CityComponent(id, n), powerLevel(pLevel) {}
void PowerSystem::supplyPower() {
    std::cout << "[PowerSystem] Supplying " << powerLevel << " MW of power.\n";
}
void PowerSystem::processEvent() {
    std::cout << "[PowerSystem] Processing power-related event...\n";
}

TransportSystem::TransportSystem(int id, std::string n, int flow) : CityComponent(id, n), trafficFlow(flow) {}
void TransportSystem::manageTraffic() {
    std::cout << "[TransportSystem] Managing traffic flow: " << trafficFlow << " vehicles/hr.\n";
}
void TransportSystem::processEvent() {
    std::cout << "[TransportSystem] Processing traffic-related event...\n";
}

HealthSystem::HealthSystem(int id, std::string n, int count) : CityComponent(id, n), hospitalCnt(count) {}
void HealthSystem::provideCare() {
    std::cout << "[HealthSystem] Providing care across " << hospitalCnt << " hospitals.\n";
}
void HealthSystem::processEvent() {
    std::cout << "[HealthSystem] Processing health-related event...\n";
}

SecuritySystem::SecuritySystem(int id, std::string n, int threat) : CityComponent(id, n), threatLevel(threat) {}
void SecuritySystem::monitorCity() {
    std::cout << "[SecuritySystem] Monitoring city. Current threat level: " << threatLevel << "\n";
}
void SecuritySystem::processEvent() {
    std::cout << "[SecuritySystem] Processing security-related event...\n";
}
