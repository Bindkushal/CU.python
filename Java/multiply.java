import java.util.Scanner;

public class multiply{
    public static void main(String[] args) {
        // Create a scanner object for user input
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter the first floating-point number
        System.out.print("Enter the first floating-point number: ");
        float num1 = scanner.nextFloat();

        // Prompt the user to enter the second floating-point number
        System.out.print("Enter the second floating-point number: ");
        float num2 = scanner.nextFloat();

        // Calculate the product of the two numbers
        float product = num1 * num2;

        // Output the product
        System.out.println("The product of the two numbers is: " + product);
    }
}
