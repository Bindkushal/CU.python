import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListexample {
    public static void main(String[] args) {
        // Create an ArrayList to store integers
        ArrayList<Integer> arrayList = new ArrayList<>();

        // Scanner for user input
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            // Display menu
            System.out.println("\nArrayList Operations:");
            System.out.println("1. Add Element");
            System.out.println("2. Remove Element");
            System.out.println("3. Display Elements");
            System.out.println("4. Get Element at Index");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1: // Add Element
                    System.out.print("Enter an integer to add: ");
                    int elementToAdd = scanner.nextInt();
                    arrayList.add(elementToAdd);
                    System.out.println("Element added: " + elementToAdd);
                    break;

                case 2: // Remove Element
                    System.out.print("Enter the index of the element to remove: ");
                    int indexToRemove = scanner.nextInt();
                    if (indexToRemove >= 0 && indexToRemove < arrayList.size()) {
                        int removedElement = arrayList.remove(indexToRemove);
                        System.out.println("Removed element: " + removedElement);
                    } else {
                        System.out.println("Invalid index.");
                    }
                    break;

                case 3: // Display Elements
                    System.out.println("ArrayList Elements: " + arrayList);
                    break;

                case 4: // Get Element at Index
                    System.out.print("Enter the index of the element to retrieve: ");
                    int indexToGet = scanner.nextInt();
                    if (indexToGet >= 0 && indexToGet < arrayList.size()) {
                        int retrievedElement = arrayList.get(indexToGet);
                        System.out.println("Element at index " + indexToGet + ": " + retrievedElement);
                    } else {
                        System.out.println("Invalid index.");
                    }
                    break;

                case 5: // Exit
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        scanner.close();
    }
}
