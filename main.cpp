#include <iostream>
#include <fstream>
#include "schedule.h"

int main() {
    schedule mySchedule;
    std::ifstream file("STEM Summer 2022 Schedule.csv");

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    mySchedule.initSchedule(file);

    char choice;
    std::string subject, catalog, instructor;

    do {
        std::cout << "Menu:\n"
            << "1. Print schedule\n"
            << "2. Find by subject\n"
            << "3. Find by subject and catalog\n"
            << "4. Find by instructor's last name\n"
            << "5. Exit\n"
            << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            mySchedule.printHeader();
            mySchedule.print();
            break;
        case '2':
            std::cout << "Enter subject: ";
            std::cin >> subject;
            mySchedule.printHeader();
            mySchedule.findSubject(subject);
            break;
        case '3':
            std::cout << "Enter subject: ";
            std::cin >> subject;
            std::cout << "Enter catalog number: ";
            std::cin >> catalog;
            mySchedule.printHeader();
            mySchedule.findSubjectCatalog(subject, catalog);
            break;
        case '4':
            std::cout << "Enter instructor's last name: ";
            std::cin >> instructor;
            mySchedule.printHeader();
            mySchedule.findInstructor(instructor);
            break;
        case '5':
            break;
        default:
            std::cout << "Invalid choice, please choose again.\n";
        }
    } while (choice != '5');

    return 0;
}
