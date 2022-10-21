// Mason Motschke - CSCI_280 - HW3 - 5/30/2022

import java.util.Scanner;

public class Mason_Motschke_prog3 {

    public static void main (String[] args){
    
        Scanner obj = new Scanner(System.in);
        float num1, num2;
        
        // Get num1
        System.out.printf("Input first number: ");
        num1 = obj.nextFloat(); System.out.printf("\n");
        
        // Get num2
        System.out.printf("Input second number: ");
        num2 = obj.nextFloat(); System.out.printf("\n");
        
        // Print sum
        System.out.printf("Sum: %.4f + %.4f = %.4f\n\n", num1, num2, num1 + num2);
        
        // Print product
        System.out.printf("Product: %.4f * %.4f = %.4f\n\n", num1, num2, num1 * num2);
        
        // Print difference
        System.out.printf("Difference: %.4f - %.4f = %.4f\n\n", num1, num2, num1 - num2);
        
        // Print divisor
        System.out.printf("Divisor: %.4f / %.4f = %.4f\n\n", num1, num2, num1 / num2);
        
        // Print remainder
        System.out.printf("Remainder: %.4f %% %.4f = %.4f\n\n", num1, num2, num1 % num2);
        
        obj.close();
    
    }

}
