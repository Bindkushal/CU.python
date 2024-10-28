public class PrimeNumbers {
    public static void main(String[] args) {
        int limit = 20;  // Define the upper limit

        System.out.println("Prime numbers up to " + limit + ":");

        // Iterate from 2 up to 'limit' to identify prime numbers
        for (int i = 2; i <= limit; i++) {
            boolean isPrime = true;  // Assume 'i' is prime

            // Check for divisibility from 2 up to sqrt(i)
            for (int j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) {
                    isPrime = false;  // Set to false if a divisor is found
                    break;  // Exit loop if 'i' is not prime
                }
            }

            // Print 'i' if it is prime
            if (isPrime) {
                System.out.print(i + " ");
            }
        }
        System.out.println();  // Print a new line after the output
    }
}
java
