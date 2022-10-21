// Mason Motschke - CSCI_280 - HW10 - 6/13/2022

public class Mason_Motschke_prog10 {

    public static void main (String[] args){
    
        SavingsAccount saver1 = new SavingsAccount((float)2000.00, (float)0.4);
        SavingsAccount saver2 = new SavingsAccount((float)3000.00, (float)0.4);
        float Interest;
        
        // Print objects
        System.out.printf("\nBefore:\n\n - Saver1: Balance: %.4f; Rate: %.2f\n", saver1.savingsBalance, saver1.annualInterestRate);
        System.out.printf(" - Saver2: Balance: %.4f; Rate: %.2f\n\n", saver2.savingsBalance, saver2.annualInterestRate);
        
        Interest = saver1.calculateMonthlyInterest();
        System.out.printf("\nFirst Interest:\n\n - Saver1: Balance: %.4f; Interest: %.4f; Rate: %.2f;\n", saver1.savingsBalance, Interest, saver1.annualInterestRate);
        Interest = saver2.calculateMonthlyInterest();
        System.out.printf(" - Saver2: Balance: %.4f; Interest: %.4f; Rate: %.2f;\n", saver2.savingsBalance, Interest, saver2.annualInterestRate);

        
        //saver1.modifyInterestRate((float)0.5); saver2.modifyInterestRate((float)0.5); // Works
        SavingsAccount.modifyInterestRate((float)0.5); // Works as well
        Interest = saver1.calculateMonthlyInterest();
        System.out.printf("\nSecond Interest:\n\n - Saver1: Balance: %.4f; Interest: %.4f; Rate: %.2f;\n", saver1.savingsBalance, Interest, saver1.annualInterestRate);
        Interest = saver2.calculateMonthlyInterest();
        System.out.printf(" - Saver2: Balance: %.4f; Interest: %.4f; Rate: %.2f;\n\n", saver2.savingsBalance, Interest, saver2.annualInterestRate);


    
    }

}

class SavingsAccount {

    // Vars
    static float annualInterestRate;
    float savingsBalance;
    
    // Constructor
    SavingsAccount (float balance, float interestRate){
    
        this.annualInterestRate = interestRate;
        this.savingsBalance = balance;
    
    }
    
    // Methods
    float calculateMonthlyInterest (){
    
        float interest = (float)((this.savingsBalance * this.annualInterestRate) / (float)12);
        this.savingsBalance += interest;
        return interest;
    
    }
    
    static void modifyInterestRate (float newRate){
    
        annualInterestRate = newRate;
    
    }

}
