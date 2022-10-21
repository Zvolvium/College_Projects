package CSCI_160;
import java.util.Scanner;

public class CSCI_160_Lab_4 {

  static Scanner obj = new Scanner(System.in);

  static void Part_A(){
    System.out.println("Part 1: \n");
    for (int i = 10; i < 51; i++){
      System.out.println(i);
    } System.out.println();

    System.out.println("Part 2: \n");
    for (int z = 20; z > -1; z--){
      System.out.println(z);
    } System.out.println();

    System.out.println("Part 3: \n");
    float x = 0;
    while (x <= 10){
      System.out.println(x); x += 0.5;
    } System.out.println();

    System.out.println("Part 4: \n");
    System.out.print("Enter a single letter: ");

    // Reads in a char ----\/
    char input = obj.next().charAt(0); System.out.println();

    int lowerCase = 0, upperCase = 0;
    while (input != 'q' && input != 'Q'){
      System.out.printf("Letter entered was: '%s'\n", input);
      if (input >= 'a' && input <= 'z'){
        lowerCase++;
      } else if (input >= 'A' && input <= 'Z'){
        upperCase++;
      }
      System.out.print("Enter a single letter ('q' or 'Q' to quit): ");
      input = obj.next().charAt(0); System.out.println();
    }
    System.out.printf("Number of Lowercase letters enterd: %d\n", lowerCase);
    System.out.printf("Number of Uppercase letters enterd: %d\n", upperCase);
  }

  static void Part_B(){
    int posCnt = 0, negCnt = 0, posNum = 0, negNum = 0;
    System.out.print("\nEnter a integer (Zero when finished): ");
    int a = obj.nextInt(); System.out.println();
    while (a != 0){
      if (a > 0){
        posNum += a; posCnt++;
      } else if (a < 0){
        negNum += a; negCnt++;
      } System.out.print("Next (Zero to quit): ");
      a = obj.nextInt(); System.out.println();
    }
    if (posCnt == 0){ posCnt = 1; }
    if (negCnt == 0){ negCnt = 1; }
    float posAv = (float)(posNum / posCnt), negAv = (float)(negNum / negCnt);
    System.out.printf("Positive Average: %1.2f\n", posAv);
    System.out.printf("Negative Average: %1.2f", negAv);
  }

  static void Part_C(){
    System.out.print("Enter a value to multiply by (1-10): ");
    int multNum = obj.nextInt(); System.out.println();
    if (multNum > 10 || multNum < 1){
      System.out.println("Error: Input is Invalid\n"); return;
    } else {
      System.out.printf("Multiplication table for: %d\n\n", multNum);
      for (int x = 1; x < 11; x++){
        int finalMult = multNum * x;
        if (multNum >= 10){
          System.out.printf("%2d * %d = %3d\n", x, multNum, finalMult);
        } else {
          System.out.printf("%2d * %d = %2d\n", x, multNum, finalMult);
        }
      }
    }
  }
  public static void main(String[] args){
    // Part_A(); Part_B();
    // Part_C();
    obj.close();
  }
}
