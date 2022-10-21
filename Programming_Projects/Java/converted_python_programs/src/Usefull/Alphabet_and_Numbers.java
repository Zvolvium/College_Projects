package Usefull;
import java.util.Scanner;

public class Alphabet_and_Numbers {

  static Scanner obj = new Scanner(System.in);
  public static void main(String[] args){
    String[] alphabet = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    for (int i = 0; i < 26; i++){
      String txt = alphabet[i] + " - " + i;
      System.out.println(txt);
    }
    System.out.print("End Session (y/n): ");
    char user = obj.next().charAt(0); System.out.println();
    user = Character.toLowerCase(user);
    if (user == 'y'){
      obj.close(); return;
    } else {
      main(args);
    }
  }

}