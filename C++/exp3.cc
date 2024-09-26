#include <iostream>
using namespace std;

class SerialNumberGenerator {
private:
    static int objectCount;
    int serialNumber;

public:
    SerialNumberGenerator() {
        serialNumber = ++objectCount;
    }

    void showSerialNumber() const {
        cout << "Serial Number: " << serialNumber << endl;
    }
};

int SerialNumberGenerator::objectCount = 0;

int main() {
    SerialNumberGenerator obj1, obj2, obj3;
    obj1.showSerialNumber();
    obj2.showSerialNumber();
    obj3.showSerialNumber();
    return 0;
}
