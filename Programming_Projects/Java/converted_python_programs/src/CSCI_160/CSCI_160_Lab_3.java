package CSCI_160;
import java.util.Scanner;

public class CSCI_160_Lab_3 {

  static Scanner obj = new Scanner(System.in);
  // Better to define scanner for the class as you can only have one scanner per stream i.e.(System.in)
  // Allows scanner to be visible to all functions within class and avalible for use

  static void Part_1(){

    // Creates a Scanner to receive input from console
    //Scanner obj = new Scanner(System.in);

    // To be noted - multiple print options for formating and no '\n' character
    System.out.print("Enter a Number between 20 and 99: ");

    // Numerical input from user
    Integer user = obj.nextInt();

    if (user > 99 || user < 20){
      System.out.printf("Error: Input not in range of 20 and 99!!\n\n"); return;
    } else {
      Integer a = user % 10; Integer b = user % 100; Integer c = (b - a) / 10;

      String[] ones  = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
      String[] tens = {"Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

      System.out.printf("The number is: %s %s\n\n", tens[c - 2], ones[a]);
    }
  }

  static void Part_2(){
    //Scanner obj = new Scanner(System.in); // open scanner

    System.out.print("How many credits have you earned so far in college? ");
    Integer earnedCredits = obj.nextInt(); System.out.printf("\n");

    System.out.print("How many credits are you taking this semester? ");
    Integer currentCredits = obj.nextInt(); System.out.printf("\n");

    // Current Semester Calculation
    if (earnedCredits >= 0 && earnedCredits <= 23){
      System.out.println("Current Status: Freshman");
    } else if (earnedCredits >= 24 && earnedCredits <= 59){
      System.out.println("Current Status: Sophomore");
    } else if (earnedCredits >= 60 && earnedCredits <= 89){
      System.out.println("Current Status: Junior");
    } else if (earnedCredits >= 90){
      System.out.println("Current Status: Senior");
    } System.out.printf("\n");

    // Next Semester Calculation
    Integer nextSemester = earnedCredits + currentCredits;
    if (nextSemester >= 0 && nextSemester <= 23){
      System.out.println("Future Status for next semester: Freshman");
    } else if (nextSemester >= 24 && nextSemester <= 59){
      System.out.println("Future Status for next semester: Sophomore");
    } else if (nextSemester >= 60 && nextSemester <= 89){
      System.out.println("Future Status for next semester: Junior");
    } else if (nextSemester >= 90){
      System.out.println("Future Status for next semester: Senior");
    } System.out.printf("\n");

    // Future Semester Calculation
    Integer gradCredits = 120 - nextSemester;
    System.out.printf("Minimum credits to graduate after this semester for most degree's: %s\n\n", gradCredits);
    Integer semestersLeft = gradCredits / 15;
    System.out.printf("Semesters left till graduation @ 15 credits per semester: %s\n\n", semestersLeft);
  }

  public static void main(String[] args){
    Part_1();
    Part_2();

    obj.close(); // close scanner
  }
}