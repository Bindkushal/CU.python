import java.util.Scanner;

public class SumInt {
    public static void main(String[] args) {
       
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter the first number
        System.out.print("Enter the first number: ");
        int num1 = scanner.nextInt();

        // Prompt the user to enter the second number
        System.out.print("Enter the second number: ");
        int num2 = scanner.nextInt();

        // Calculate the sum of the two numbers
        int sum = num1 + num2;

        // Output the sum
        System.out.println("The sum of the two numbers is: " + sum);
    }
}
