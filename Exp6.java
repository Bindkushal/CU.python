import java.util.Scanner;

public class FibonacciPyramid {

    // Recursive method to calculate Fibonacci number
    public static int fibonacci(int n) {
        if (n <= 1) {
            return n;  // Base case: Fibonacci(0) = 0, Fibonacci(1) = 1
        } else {
            // Recursive case: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user how many terms of the Fibonacci sequence to print in the pyramid
        System.out.print("Enter the number of terms to print in the Fibonacci sequence pyramid: ");
        int terms = scanner.nextInt();

        // Validate the input
        if (terms <= 0) {
            System.out.println("Please enter a positive number of terms.");
        } else {
            System.out.println("Fibonacci sequence pyramid up to " + terms + " terms:");

            int currentTerm = 0;  // To track how many Fibonacci numbers have been printed

            for (int row = 1; currentTerm < terms; row++) {
                // For each row, print 'row' Fibonacci numbers
                for (int col = 0; col < row && currentTerm < terms; col++) {
                    System.out.print(fibonacci(currentTerm) + " ");
                    currentTerm++;
                }
                System.out.println();  // Move to the next line after printing each row
            }
        }

        scanner.close();
    }
}
