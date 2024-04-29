#pragma once
#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <string>
#include <iostream>

class scheduleItem {
private:
    std::string Subject, Catalog, Section, Component, Session, Instructor;
    int Units, TotEnrl, CapEnrl;

public:
    scheduleItem(std::string subject = "", std::string catalog = "", std::string section = "",
        std::string component = "", std::string session = "", int units = 0,
        int totEnrl = 0, int capEnrl = 0, std::string instructor = "") :
        Subject(subject), Catalog(catalog), Section(section), Component(component),
        Session(session), Units(units), TotEnrl(totEnrl), CapEnrl(capEnrl), Instructor(instructor) {}

    bool operator==(const scheduleItem& other) const {
        return Subject == other.Subject && Catalog == other.Catalog && Section == other.Section;
    }

    bool operator!=(const scheduleItem& other) const {
        return !(*this == other);
    }

    bool operator>=(const scheduleItem& other) const {
        return (Subject >= other.Subject) && (Catalog >= other.Catalog) && (Section >= other.Section);
    }

    void print() const {
        std::cout << Subject << " " << Catalog << " " << Section << " " << Component << " "
            << Session << " " << Units << " " << TotEnrl << " " << CapEnrl << " " << Instructor << std::endl;
    }

    std::string getKey() const {
        return Subject + "_" + Catalog + "_" + Section;
    }

    // Getters for find functions
    std::string getSubject() const { return Subject; }
    std::string getCatalog() const { return Catalog; }
    std::string getInstructor() const { return Instructor; }
};

#endif
