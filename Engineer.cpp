#include "Engineer.h"

// Simple encryption utility for demonstration
std::string encrypt(const std::string& text) {
    std::string result = text;
    for (char& c : result) {
        c = c + 3; // Shift cipher
    }
    return result;
}

Engineer::Engineer(std::string id, std::string uname, std::string pass, std::string clearance, bool isEncrypted) 
    : engineerID(id), username(uname), clearanceLevel(clearance) {
    if (!isEncrypted) {
        encryptedPassword = encrypt(pass);
    } else {
        encryptedPassword = pass;
    }
}

std::string Engineer::getEngineerID() const {
    return engineerID;
}

std::string Engineer::getUsername() const {
    return username;
}

std::string Engineer::getEncryptedPassword() const {
    return encryptedPassword;
}

std::string Engineer::getClearanceLevel() const {
    return clearanceLevel;
}

bool Engineer::verifyPassword(const std::string& inputPassword) const {
    return encrypt(inputPassword) == encryptedPassword;
}

bool Engineer::operator<(const Engineer& other) const {
    return engineerID < other.engineerID;
}

bool Engineer::operator==(const std::string& targetID) const {
    return engineerID == targetID;
}
