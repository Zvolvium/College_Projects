// Mason Motschke - CSCI_280 - HW8 - 6/8/2022

public class Mason_Motschke_prog8 {

    public static void main (String[] args){
    
        // New objects of class 'Holiday'
        Holiday obj1 = new Holiday("Independence Day", "July", 4);
        Holiday obj2 = new Holiday("Labor Day", "September", 5);
        
        // Output of Method 'inSameMonth'
        boolean sameMonth = Holiday.inSameMonth(obj1.month, obj2.month);
        
        // Printed objects and values
        System.out.printf("\nobj1: %s, %s, %d\n", obj1.name, obj1.month, obj1.day);
        System.out.printf("\nobj2: %s, %s, %d\n", obj2.name, obj2.month, obj2.day);
        System.out.printf("\n - Are the two months the same: %b\n\n", sameMonth);
    
    }

}

class Holiday{

    // Vars
    String name;
    String month;
    int day;
    
    // Constructor
    Holiday(String newName, String newMonth, int newDay) {
    
        name = newName;
        month = newMonth;
        day = newDay;
    
    }

    // inSameMonth Method
    public static boolean inSameMonth(String m1, String m2) {
    
        // Throws vars m1 and m2 to lower case
        m1 = m1.toLowerCase(); m2 = m2.toLowerCase();
        
        // Returns if they are equal or not
        return m1.equals(m2);
   
    }

}
