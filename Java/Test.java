// Java program to illustrate the concept of inheritance

// Base class
class Bicycle {
    // Fields for Bicycle class
    public int gear;
    public int speed;

    // Constructor for Bicycle class
    public Bicycle(int gear, int speed) {
        this.gear = gear;
        this.speed = speed;
    }

    // Method to decrease speed
    public void applyBrake(int decrement) {
        speed -= decrement;
    }

    // Method to increase speed
    public void speedUp(int increment) {
        speed += increment;
    }

    // toString() method to display Bicycle info
    @Override
    public String toString() {
        return "Number of gears: " + gear + "\nSpeed of bicycle: " + speed;
    }
}

// Derived class
class MountainBike extends Bicycle {
    // Additional field for MountainBike class
    public int seatHeight;

    // Constructor for MountainBike class
    public MountainBike(int gear, int speed, int startHeight) {
        // Invoking the base class (Bicycle) constructor
        super(gear, speed);
        this.seatHeight = startHeight;
    }

    // Method to adjust seat height
    public void setHeight(int newValue) {
        seatHeight = newValue;
    }

    // Overriding toString() method to display additional MountainBike info
    @Override
    public String toString() {
        return super.toString() + "\nSeat height: " + seatHeight;
    }
}

// Driver class
public class Test {
    public static void main(String[] args) {
        // Creating an instance of MountainBike
        MountainBike mb = new MountainBike(3, 100, 25);

        // Displaying the information of MountainBike instance
        System.out.println(mb.toString());
    }
}
