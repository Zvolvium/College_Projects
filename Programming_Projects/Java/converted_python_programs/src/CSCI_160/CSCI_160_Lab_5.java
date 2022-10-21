package CSCI_160;
import java.util.Scanner;

public class CSCI_160_Lab_5 {
  
  static Scanner obj = new Scanner(System.in);

  static int honorPointCalc(char letter, int credits){
    int honorPoints = 0;
    if (letter == 'A'){
      honorPoints = 4 * credits;
    } else if (letter == 'B'){
      honorPoints = 3 * credits;
    } else if (letter == 'C'){
      honorPoints = 2 * credits;
    } else if (letter == 'D'){
      honorPoints = credits;
    } else { honorPoints = 0; }
    return honorPoints;
  }

  static float GPAcalc(int honorTotal, int creditsAttempted){
    float gpaTotal;
    if (creditsAttempted != 0){
      gpaTotal = (float)(honorTotal / creditsAttempted);
    } else {
      gpaTotal = 0;
    } return gpaTotal;
  }

  static void Lab_5(){
    int honorPointTotal = 0, creditsAttempted = 0,
    creditsPassed = 0, classAttemptCount = 0, classPassCount = 0;
    
    System.out.print("Enter a Class you are taking this semester: ");
    String className = obj.nextLine(); System.out.println();
    
    while (className != ""){
      System.out.print("Enter number of credits for class: ");
      int creditNum = obj.nextInt(); System.out.println();

      System.out.print("Enter your class grade (A-F): ");
      char classGrade = obj.next().charAt(0); System.out.println(); obj.nextLine();

      creditsAttempted += creditNum; classAttemptCount++;
      classGrade = Character.toUpperCase(classGrade);
      if (classGrade >= 'A' && classGrade < 'F'){
        classPassCount++; creditsPassed += creditNum;
        int honorPoints = honorPointCalc(classGrade, creditNum);
        honorPointTotal += honorPoints;
      }
      System.out.print("Enter next class you are taking (Enter to quit): ");
      className = obj.nextLine(); System.out.println();
    }
    float GPA = GPAcalc(honorPointTotal, creditsAttempted);
    
    // Output ---\/
    System.out.printf("GPA: %1.3f\n", GPA);
    System.out.printf("Credits Attempted: %d\n", creditsAttempted);
    System.out.printf("Credits Passed: %d\n", creditsPassed);
    System.out.printf("Classes Attempted: %d\n", classAttemptCount);
    System.out.printf("Classes Passed: %d\n", classPassCount);
  }
  public static void main(String[] args){
    Lab_5();

    obj.close();
  }
}