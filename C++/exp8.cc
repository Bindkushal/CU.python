#include <iostream>

class Sample {
private:
    int value;

public:
    // Constructor
    Sample(int val) : value(val) {
        std::cout << "Object created with value: " << value << std::endl;
    }

    // Destructor
    ~Sample() {
        std::cout << "Object with value " << value << " is being deleted." << std::endl;
    }

    // Member function to display the value
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    // Creating an object of Sample class dynamically
    Sample* obj = new Sample(10); // Using new to create an object

    // Displaying the value
    obj->display();

    // Deleting the object
    delete obj; // Using delete to free memory

    return 0;
}
