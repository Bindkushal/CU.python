#include <iostream>

class SerialObject {
private:
    static int objectCount; // Static member to count the objects
    int serialNumber; // Serial number for each object

public:
    // Constructor
    SerialObject() {
        serialNumber = ++objectCount; // Increment and assign the serial number
    }

    // Member function to report serial number
    void reportSerialNumber() const {
        std::cout << "Serial Number: " << serialNumber << std::endl;
    }
};

// Initialize the static member
int SerialObject::objectCount = 0;

int main() {
    SerialObject obj1;
    SerialObject obj2;
    SerialObject obj3;

    obj1.reportSerialNumber(); // Output: Serial Number: 1
    obj2.reportSerialNumber(); // Output: Serial Number: 2
    obj3.reportSerialNumber(); // Output: Serial Number: 3

    return 0;
}
