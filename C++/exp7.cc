#include <iostream>

class Complex {
private:
    double real; // Real part of the complex number
    double imag; // Imaginary part of the complex number

public:
    // Constructor to initialize real and imaginary parts
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloading the + operator to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading the - operator to subtract two complex numbers
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overloading the << operator to output a complex number
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) {
            out << " + " << c.imag << "i";
        } else {
            out << " - " << -c.imag << "i";
        }
        return out;
    }

    // Overloading the >> operator to input a complex number
    friend std::istream& operator>>(std::istream& in, Complex& c) {
        std::cout << "Enter real part: ";
        in >> c.real;
        std::cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

int main() {
    Complex num1, num2;

    // Input complex numbers from the user
    std::cout << "Input first complex number:\n";
    std::cin >> num1;
    std::cout << "Input second complex number:\n";
    std::cin >> num2;

    // Performing addition and subtraction
    Complex sum = num1 + num2;
    Complex difference = num1 - num2;

    // Displaying the results
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;

    return 0;
}
