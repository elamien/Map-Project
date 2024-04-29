#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "scheduleItem.h"
#include <map>
#include <fstream>
#include <sstream>
#include <vector>

class schedule {
private:
    std::map<std::string, scheduleItem> items;

public:
    void initSchedule(std::ifstream& file) {
        std::string line;
        getline(file, line);  // Skip the header line

        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string subject, catalog, section, component, session, instructor;
            int units, totEnrl, capEnrl;
            char comma;
            std::getline(iss, subject, ',');
            std::getline(iss, catalog, ',');
            std::getline(iss, section, ',');
            std::getline(iss, component, ',');
            std::getline(iss, session, ',');
            iss >> units >> comma >> totEnrl >> comma >> capEnrl >> comma;
            std::getline(iss, instructor);
            scheduleItem item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
            items[item.getKey()] = item;
        }
    }

    void print() {
        for (const auto& pair : items) {
            pair.second.print();
        }
    }

    void printHeader() {
        std::cout << "Subject Catalog Section Component Session Units TotEnrl CapEnrl Instructor\n";
    }

    void findSubject(const std::string& targetSubject) {
        for (const auto& pair : items) {
            if (pair.second.getSubject() == targetSubject) {
                pair.second.print();
            }
        }
    }

    void findSubjectCatalog(const std::string& targetSubject, const std::string& targetCatalog) {
        for (const auto& pair : items) {
            if (pair.second.getSubject() == targetSubject && pair.second.getCatalog() == targetCatalog) {
                pair.second.print();
            }
        }
    }

    void findInstructor(const std::string& lastName) {
        for (const auto& pair : items) {
            if (pair.second.getInstructor().find(lastName) != std::string::npos) {
                pair.second.print();
            }
        }
    }
};

#endif
