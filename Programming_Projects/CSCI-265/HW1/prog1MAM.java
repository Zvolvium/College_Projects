/*
 * File Name: prog1MAM.java
 * 
 * Java Version: 17.0.5
 * 
 * Author: Mason A. Motschke
 * 
 * Contact: mason.motschke@und.edu
 * 
 * Comment:
 *  Write each of the following programs in C, C++, Python, and Java.
 *  Write a single problem that addresses all three parts:
 *      Part 1 – Convert from seconds
 *      Part 2 – Convert to dollars
 *      Part 3 - Work with output
*/
import java.util.Scanner;

public class prog1MAM {

    private static Scanner keyboard;

    public static void part1 (Scanner keyboard){
        System.out.printf("---------- Part 1 ----------\n");
        System.out.printf("Enter the number of seconds(EX: 5): ");

        int start = keyboard.nextInt();
        int sec = (start % 60); int min = ((start / 60) % 60); int hrs = ((start / 60) / 60);

        System.out.printf("\n -- Hours: %d, Minutes: %d, Seconds: %d\n", hrs, min, sec);
    }

    public static void part2 (Scanner keyboard){
        System.out.printf("\n---------- Part 2 ----------");
        System.out.printf("\nEnter Number of Quarters(EX: 5): "); int quarters = keyboard.nextInt();
        System.out.printf("Enter Number of Dimes(EX: 5): "); int dimes = keyboard.nextInt();
        System.out.printf("Enter Number of Nickles(EX: 5): "); int nickles = keyboard.nextInt();
        System.out.printf("Enter Numbrer of Pennies(EX: 5): "); int pennies = keyboard.nextInt();

        int dollars = (int)((quarters * 0.25) + (dimes * 0.10) + (nickles * 0.05) + (pennies * 0.01));
        int cents = (int)((((quarters * 0.25) + (dimes * 0.10) + (nickles * 0.05) + (pennies * 0.01)) * 100) % 100);

        System.out.printf("\n -- Dollars: %d, Cents: %d\n", dollars, cents);
    }

    public static void part3 (Scanner keyboard){
        keyboard.nextLine(); // Flush Input Buffer

        System.out.printf("\n---------- Part 3 ----------");
        System.out.printf("\nEnter your First Name: "); String first = keyboard.nextLine().strip();
        System.out.printf("Enter your Last Name: "); String last = keyboard.nextLine().strip();
        System.out.printf("Enter Address: "); String addr = keyboard.nextLine().strip();
        System.out.printf("Enter City: "); String city = keyboard.nextLine().strip();
        System.out.printf("Enter State: "); String state = keyboard.nextLine().strip();
        System.out.printf("Enter Zip Code: "); String zip = keyboard.nextLine().strip();

        // Print format using 1 print statement
        System.out.printf("\n%s, %s\n%s\n%s, %s  %s\n\n", first, last, addr, city, state, zip);

        // Print format using 6 print statements
        System.out.printf("%s, ", first); System.out.println(last);
        System.out.println(addr);
        System.out.printf("%s, ", city); System.out.printf("%s  ", state); System.out.println(zip + "\n");
    }

    public static void main (String[] args){
        // Open Scanner 
        keyboard = new Scanner(System.in);

        part1(keyboard); part2(keyboard); part3(keyboard);

        // Close Scanner
        keyboard.close();
    }
}
