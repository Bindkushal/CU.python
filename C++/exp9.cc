#include <iostream>
#include <fstream>
#include <string>

struct Student {
    std::string name;
    int age;
    int UID;
};

void writeToFile(const Student students[], int size, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << students[i].name << std::endl;
            outFile << students[i].age << std::endl;
            outFile << students[i].UID << std::endl;
        }
        outFile.close();
        std::cout << "Student information saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
}

void readFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string name;
        int age, UID;

        std::cout << "Student Information:" << std::endl;
        while (getline(inFile, name)) {
            inFile >> age >> UID;
            inFile.ignore(); // To ignore the newline character after the roll number
            std::cout << "Name: " << name << ", Age: " << age << ", UID: " << UID
            << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading" << std::endl;
    }
}

int main() {
    const int studentCount = 5;
    Student students[studentCount];

    // Input student information
    for (int i = 0; i < studentCount; ++i) {
        std::cout << "Enter details for student " << (i + 1) << ":\n";
        std::cout << "Name: ";
        std::getline(std::cin, students[i].name);
        std::cout << "Age: ";
        std::cin >> students[i].age;
        std::cout << "UID: ";
        std::cin >> students[i].UID;
        std::cin.ignore(); // To ignore the newline character after the roll number
    }

    // Write to file
    std::string filename = "students.txt";
    writeToFile(students, studentCount, filename);

    // Read from file
    readFromFile(filename);

    return 0;
}
