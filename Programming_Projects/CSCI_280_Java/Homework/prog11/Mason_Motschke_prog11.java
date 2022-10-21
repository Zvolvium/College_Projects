// Mason Motschke - CSCI_280 - HW11 - 6/22/2022

public class Mason_Motschke_prog11 {

    public static void main (String[] args){
    
        // ----- Student Test -----
        System.out.printf("\n----- Student -----\n");
        Student obj = new Student("Sally", "404 Liverpool");
        // Adding
        obj.addCourseGrade("ENGR 340", 55); obj.addCourseGrade("CSCI 160", 2);
        // Printing
        System.out.printf("\n%s's %s - Courses and Grades:", obj.getName(), obj.getAddress());
        obj.printGrades();
        // Grade Average
        System.out.printf("Grade Average: %d\n\n", obj.getAverageGrade());
        System.out.printf("-------------------\n");
        
        
        
        
        // ----- Teacher Test -----
        System.out.printf("\n----- Teacher -----\n");
        Teacher obj2 = new Teacher("Freddy", "9082 Lovecraftian Blvd.");
        // Adding
        boolean added; String course = "CS101";
        added = obj2.addCourse(course);
        System.out.printf("\n--- Adding Classes:\n");
        if (added == false){ System.out.printf("\nThe Course %s cannot be added\n", course); }
        else { System.out.printf("\nCourse %s added\n", course); } course = "CS102";
        added = obj2.addCourse(course);
        if (added == false){ System.out.printf("\nThe Course %s cannot be added\n", course); }
        else { System.out.printf("\nCourse %s added\n", course); } course = "CS101";
        added = obj2.addCourse(course);
        if (added == false){ System.out.printf("\nThe Course %s cannot be added\n", course); }
        else { System.out.printf("\nCourse %s added\n", course); }
        
        // Subtracting
        System.out.printf("\n--- Subtracting Classes:\n");
        boolean subbed; course = "CS101";
        subbed = obj2.removeCourse(course);
        if (subbed == false){ System.out.printf("\nThe Course %s cannot be subtracted\n", course); }
        else { System.out.printf("\nCourse %s subtracted\n", course); } course = "CS102";
        subbed = obj2.removeCourse(course);
        if (subbed == false){ System.out.printf("\nThe Course %s cannot be subtracted\n", course); }
        else { System.out.printf("\nCourse %s subtracted\n", course); } course = "CS101";
        subbed = obj2.removeCourse(course);
        if (subbed == false){ System.out.printf("\nThe Course %s cannot be subtracted\n", course); }
        else { System.out.printf("\nCourse %s subtracted\n", course); }
        
        System.out.printf("\n-------------------\n");
    }


}

class Person {

    String name;
    String address;
    
    Person (String name, String address){ setName(name); setAddress(address); }
    
    String getName (){ return this.name; }
    
    String getAddress (){ return this.address; }
    
    void setName (String name){ this.name = name; }
    
    void setAddress (String address){ this.address = address; }

}

class Student extends Person {

    int numCourses;
    String[] courses;
    int[] grades;
    
    Student (String name, String address){
    
        super(name, address);
        this.numCourses = 0;
        this.courses = new String[0];
        this.grades = new int[0];
    
    }
    
    void addCourseGrade (String course, int grade){
    
        String[] tmp = new String[this.courses.length + 1];
        int[] Itmp = new int[this.grades.length + 1];
        for (int i = 0; i < this.courses.length; i++){ 
            tmp[i] = this.courses[i];
            Itmp[i] = this.grades[i];
        }
        tmp[this.courses.length] = course;
        Itmp[this.grades.length] = grade;
        this.courses = tmp;
        this.grades = Itmp;
        this.numCourses++;
    
    }

    void printGrades (){
    
        int num = this.numCourses; System.out.printf("\n - Courses and Grades:\n");
        for (int i = 0; i < num; i++){ System.out.printf("   - %s: %d\n", this.courses[i], this.grades[i]); }
        System.out.println();
    
    }
    
    int getAverageGrade (){
    
        int num = this.numCourses; int ave = 0;
        for (int i = 0; i < num; i++){ ave += grades[i]; }
        ave = (int)(ave / num);
        return ave;
    
    }

}

class Teacher extends Person {

    int numCourses;
    String[] courses;
    
    Teacher (String name, String address){
    
        super(name, address);
        this.numCourses = 0;
        this.courses = new String[0];
    
    }
    
    boolean addCourse (String course){
    
        int num = this.numCourses;
        String[] tmp = new String[num + 1];
        for (int i = 0; i < num; i++){ if (this.courses[i].equals(course)){ return false; } }
        for (int i = 0; i < num; i++){
            if (num == 0){ break; }
            tmp[i] = this.courses[i];
        }
        tmp[num] = course;
        this.courses = tmp; this.numCourses++;
        return true;
    
    }
    
    boolean removeCourse (String course){
    
        int num = this.numCourses;
        if (num <= 0){ return false; } // If array is 0 return;
        
        // Is course in the array
        boolean found = false; 
        for (int i = 0; i < num; i++){
            if (this.courses[i].equals(course)){ found = true; break; } /// Go until course is found;
        }
        if (found == false){ return false; } // If course not found return false;
        
        // Remove Course
        int i = 0; String[] tmp = new String[num - 1];
        while (true){
            if (i >= num - 1){ break; }
            if (this.courses[i].equals(course)){
            
                tmp[i] = this.courses[i + 1]; i++;
            
            }
            else { tmp[i] = this.courses[i]; }
            i++;
        }
        this.courses = tmp; this.numCourses--;
        return true;
    
    }

}

