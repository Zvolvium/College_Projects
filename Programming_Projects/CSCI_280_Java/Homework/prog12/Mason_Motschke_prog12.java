// Mason Motschke - CSCI_280 - HW12 - 6/29/2022

import java.util.Scanner;

public class Mason_Motschke_prog12 {

    public static void main (String[] args){
    
        Scanner obj = new Scanner(System.in);
        int num1 = -1000000, num2 = -1000000, attempts = 0;
        boolean flag = true;
        
        while (flag){
            flag = false;
            try {
                System.out.printf("\nEnter a Number: ");
                num1 = obj.nextInt(); System.out.println();
            } catch (Exception e){
                System.out.println("\nPlease enter an Integer!!");
                flag = true; attempts++; obj.nextLine();
            }
        } flag = true;
        
        while (flag){
            flag = false;
            try {
                System.out.printf("\nEnter a Second Number: ");
                num2 = obj.nextInt(); System.out.println();
            } catch (Exception e){
                System.out.println("\nPlease enter an Integer!!");
                flag = true; attempts++; obj.nextLine();
            }
        }
        
        System.out.printf("\n - Sum of " + num1 + " and " + num2 + " is: " + (num1 + num2) + "\n");
        System.out.println(" - Amount of Invalid Entries: " + attempts + "\n");
    
    }

}
