#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>

class Engineer {
private:
    std::string engineerID;
    std::string username;
    std::string encryptedPassword;
    std::string clearanceLevel;

public:
    Engineer(std::string id, std::string uname, std::string pass, std::string clearance, bool isEncrypted = false);

    std::string getEngineerID() const;
    std::string getUsername() const;
    std::string getEncryptedPassword() const;
    std::string getClearanceLevel() const;

    bool verifyPassword(const std::string& inputPassword) const;

    // For algorithm usage
    bool operator<(const Engineer& other) const;
    bool operator==(const std::string& targetID) const;
};

#endif // ENGINEER_H
