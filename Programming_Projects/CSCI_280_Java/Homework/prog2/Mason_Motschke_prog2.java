// Mason Motschke - CSCI_280 - HW2 - 5/30/2022

import java.util.Scanner;

public class Mason_Motschke_prog2 {

    public static void main (String[] args){
    
        System.out.printf("----- Product of Two Numbers -----\n\n");
        
        Scanner obj = new Scanner(System.in);
        float num1, num2;
        
        // Get num1
        System.out.printf("Input first number: ");
        num1 = obj.nextFloat(); System.out.printf("\n");
        
        // Get num2
        System.out.printf("Input second number: ");
        num2 = obj.nextFloat(); System.out.printf("\n");
        
        // Print product
        System.out.printf("Product of %.4f and %.4f is %.4f\n\n", num1, num2, num1 * num2);
        
        obj.close();
    
    }

}
