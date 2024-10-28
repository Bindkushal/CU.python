class Main {
    public static void main(String[] args) {
        int n = 10;
        int firstTerm = 0, secondTerm = 1;

        System.out.println("Fibonacci Series up to " + n + " terms:");
        System.out.print("[ ");

        for (int i = 1; i <= n; ++i) {
            System.out.print(firstTerm);

            // Add a comma and space between terms, but not after the last term
            if (i < n) {
                System.out.print(", ");
            }

            // Compute the next term
            int nextTerm = firstTerm + secondTerm;
            firstTerm = secondTerm;
            secondTerm = nextTerm;
        }

        System.out.print(" ]\n");
    }
}
