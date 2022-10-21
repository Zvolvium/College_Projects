// Mason Motschke - CSCI_280 - HW9 - 6/13/2022

public class Mason_Motschke_prog9 {

    public static void main (String[] args){
    
        Account obj1 = new Account("89-p", "John P", 1000);
        Account obj2 = new Account("01-a", "Jane Z");
        
        // Print objects using get Methods
        System.out.printf("\nStarting:\n\n - obj1 ID: %s; NAME: %s; BALANCE: %d;\n", obj1.getID(), obj1.getName(), obj1.getBalance());
        System.out.printf(" - obj2 ID: %s; NAME: %s; BALANCE: %d;\n\n", obj2.getID(), obj2.getName(), obj2.getBalance());
    
        // Testing credit
        obj1.credit(50); obj2.credit(100);
        System.out.printf("\nAfter Credit:\n\n - obj1 ID: %s; NAME: %s; BALANCE: %d;\n", obj1.getID(), obj1.getName(), obj1.getBalance());
        System.out.printf(" - obj2 ID: %s; NAME: %s; BALANCE: %d;\n\n", obj2.getID(), obj2.getName(), obj2.getBalance());
        
        // Testing debit
        obj1.debit(60); obj2.debit(20); obj1.debit(10000); obj2.debit(5000);
        System.out.printf("\nAfter Debit:\n\n - obj1 ID: %s; NAME: %s; BALANCE: %d;\n", obj1.getID(), obj1.getName(), obj1.getBalance());
        System.out.printf(" - obj2 ID: %s; NAME: %s; BALANCE: %d;\n\n", obj2.getID(), obj2.getName(), obj2.getBalance());
        
        // Testing Transfer
        obj1.transferTo(obj2, 500); obj2.transferTo(obj1, 10); obj1.transferTo(obj2, 10000); obj2.transferTo(obj1, 5000);
        System.out.printf("\nAfter Transfer:\n\n - obj1 ID: %s; NAME: %s; BALANCE: %d;\n", obj1.getID(), obj1.getName(), obj1.getBalance());
        System.out.printf(" - obj2 ID: %s; NAME: %s; BALANCE: %d;\n\n", obj2.getID(), obj2.getName(), obj2.getBalance());
    
        // Print objects using get Methods
        System.out.printf("\nFinishing:\n\n - obj1 ID: %s; NAME: %s; BALANCE: %d;\n", obj1.getID(), obj1.getName(), obj1.getBalance());
        System.out.printf(" - obj2 ID: %s; NAME: %s; BALANCE: %d;\n\n", obj2.getID(), obj2.getName(), obj2.getBalance());
    
    }
    
}

class Account {

    // Vars
    String id = "";
    String name = "";
    int balance = 0;
    
    // Constructors
    Account (String ID, String NAME){
    
        id = ID;
        name = NAME;
    
    }
    Account (String ID, String NAME, int BALANCE){
    
        id = ID;
        name = NAME;
        balance = BALANCE;
    
    }
    
    // Getters
    String getID (){
    
        return id;
    
    }
    String getName (){
    
        return name;
    
    }
    int getBalance (){
    
        return balance;
    
    }
    
    // Methods
    int credit (int amount){
    
        return balance += amount;
    
    }
    
    int debit (int amount){
    
        if (amount <= balance){
        
            balance -= amount;
        
        } else {
        
            System.out.printf("\n - Amount exceeds the available balance!!!\n");
        
        }
        
        return balance;
    
    }
    
    int transferTo (Account otherAccount, int amount){
    
        if (amount <= balance){
        
            otherAccount.balance += amount;
            this.balance -= amount;
        
        } else {
        
            System.out.printf("\n - Amount exceeds balance!!!\n");
        
        }
        
        return balance;
    
    }

}
