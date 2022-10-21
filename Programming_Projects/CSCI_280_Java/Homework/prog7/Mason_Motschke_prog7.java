// Mason Motschke - CSCI_280 - HW7 - 6/8/2022

public class Mason_Motschke_prog7 {

    public static void main (String[] args){
    
        // Creation of 2 people of class Student:
        Student person1 = new Student();
        Student person2 = new Student();
        
        // Setting of 'names':
        person1.name = "John";
        person2.name = "Sam";
        
        // Setting of 'roll_no' values:
        person1.roll_no = 2;
        person2.roll_no = 10;
        
        // Printing of values:
        System.out.printf("\n - %s has roll num of %d\n", person1.name, person1.roll_no);
        System.out.printf("\n - %s has roll num of %d\n\n", person2.name, person2.roll_no);
    
    }

}

class Student {

    String name = "null";
    int roll_no = -1;

}
