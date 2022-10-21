// Mason Motschke - CSCI_280 - HW5 - 6/1/2022

import java.util.Scanner;

public class Mason_Motschke_prog5 {

    public static void main (String[] args){
    
        Scanner obj = new Scanner(System.in);
        
        System.out.printf("\nEnter a Integer: ");
        int user = obj.nextInt(); System.out.printf("\n");
        
        int sum = 0;
        for (int i = user; i <= user + 20; i++){
        
            sum += i;
        
        }
        
        System.out.printf(" - Sum of numbers %d-%d: %d\n\n", user, user + 20, sum);
        
        obj.close();
    
    }

}
