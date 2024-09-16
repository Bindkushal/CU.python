#include <iostream>
using namespace std;

int main() {
    int num, sum = 0, digit;

    // Input a positive integer from the user
    cout << "Enter a positive integer: ";
    cin >> num;

    // Loop to extract and sum each digit
    while (num > 0) {
        digit = num % 10;  // Get the last digit
        sum += digit;      // Add the digit to sum
        num /= 10;         // Remove the last digit from the number
    }

    // Output the sum of the digits
    cout << "Sum of individual digits: " << sum << endl;

    return 0;
}
