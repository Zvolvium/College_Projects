// Mason Motschke - CSCI_280 - HW6 - 6/1/2022

import java.util.Scanner;

public class Mason_Motschke_prog6 {

    public static void main (String[] args){
        
        Scanner obj = new Scanner(System.in);
        float sum = 0, user;
        
        try {
        
            System.out.printf("\nEnter Number (Any character to Quit): ");
            user = obj.nextFloat(); System.out.printf("\n");
            
            while (true){
            
                if (user > 0.0){ sum += user; }
                
                System.out.printf("Enter next Number (Any character to Quit): ");
                user = obj.nextFloat(); System.out.printf("\n");
            
            }
            
        } catch (Exception e){
        
            System.out.printf("\n - Sum of Numbers = %.4f\n\n", sum);
            obj.close();
        
        }
    
    }

}
