#include <iostream>

class Int {
private:
    int value; // The underlying integer value

public:
    // Default constructor initializes to 0
    Int() : value(0) {}

    // Constructor that initializes to a specific int value
    Int(int val) : value(val) {}

    // Function to display the value
    void display() const {
        std::cout << value;
    }

    // Overloading the + operator to add two Int objects
    Int operator+(const Int& other) const {
        return Int(this->value + other.value);
    }
};

int main() {
    // Creating two initialized Int objects and one uninitialized Int object
    Int num1(10);  // Initialize num1 to 10
    Int num2(20);  // Initialize num2 to 20
    Int result;    // Uninitialized Int object

    // Adding num1 and num2 and storing the result in the uninitialized object
    result = num1 + num2;

    // Displaying the result
    std::cout << "The result of adding ";
    num1.display();
    std::cout << " and ";
    num2.display();
    std::cout << " is: ";
    result.display();
    std::cout << std::endl;

    return 0;
}
