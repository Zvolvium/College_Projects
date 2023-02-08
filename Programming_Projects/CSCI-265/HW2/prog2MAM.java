/*
 * File Name: prog2MAM.java
 * 
 * Java Version: 17.0.5
 * 
 * Author: Mason A. Motschke
 * 
 * Contact: mason.motschke@und.edu
 * 
 * Comment:
 *      Write each of the following programs in C, C++, Python, and Java.
 *      Write a program that surveys the majors of students in some unnamed class.
 *      Only majors I’m concerned with are Computer Science, Data Science, and Cyber Security.
 *      For only the CS majors we want to ask about their minor.
*/
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class prog2MAM {

    private static Scanner keyboard;

    private static Map<String, Map<String, Integer>> getMajorsAndMinors (Scanner keyboard){  // Collects and Returns Majors and Minors from the Users in Map 'majorsAndMinors'
        Map<String, Integer> minors = new HashMap<String, Integer>();
        Map<String, Integer> majors = new HashMap<String, Integer>();

        majors = majorAndMinorSetup(majors, 0);
        minors = majorAndMinorSetup(minors, 1);

        System.out.printf("Enter a Major('Done to quit'): ");
        String input = keyboard.nextLine().strip();

        int cnt;
        while (!(input.toLowerCase().equals("Done".toLowerCase()))){
            if (input.toLowerCase().equals("CS".toLowerCase())){
                cnt = majors.get("CS");
                // Major
                majors.replace("CS", ++cnt);
                // Minor
                minors = getMinor(keyboard, minors);

            } else if (input.toLowerCase().equals("Data".toLowerCase())){
                cnt = majors.get("Data");
                majors.replace("Data", ++cnt);

            } else if (input.toLowerCase().equals("Cyber".toLowerCase())){
                cnt = majors.get("Cyber");
                majors.replace("Cyber", ++cnt);

            } else {
                cnt = majors.get("Other");
                majors.replace("Other", ++cnt);

            }
            System.out.printf("\nEnter a Major('Done to quit'): ");
            input = keyboard.nextLine().strip();
        }

        Map<String, Map<String, Integer>> majorsAndMinors = new HashMap<String, Map<String, Integer>>();
        majorsAndMinors.put("majors", majors);
        majorsAndMinors.put("minors", minors);
        return majorsAndMinors;
    }

    private static Map<String, Integer> getMinor (Scanner keyboard, Map<String, Integer> Minors){  // Returns Updated Minors Map
        System.out.printf("Enter your Minor: ");
        String input = keyboard.nextLine().strip();

        int cnt;
        if (input.toLowerCase().equals("Data".toLowerCase())){
            cnt = Minors.get("Data");
            Minors.replace("Data", ++cnt);

        } else if (input.toLowerCase().equals("Cyber".toLowerCase())){
            cnt = Minors.get("Cyber");
            Minors.replace("Cyber", ++cnt);

        } else if (input.toLowerCase().equals("Math".toLowerCase())){
            cnt = Minors.get("Math");
            Minors.replace("Math", ++cnt);

        } else {
            cnt = Minors.get("Other");
            Minors.replace("Other", ++cnt);

        }
        return Minors;
    }

    private static float getStudentNumber (Map<String, Integer> map, Object[] keys){  // Returns Number of Students that were Surveyed from the Entries in the Map
        float num = 0;
        for (int i = 0; i < keys.length; i++){
            num += map.get(keys[i]);
        }
        return num;
    }

    private static Map<String, Integer> majorAndMinorSetup (Map<String, Integer> map, int flag){  // Returns Initialized Map / Dictionary
        if (flag == 0){ // If Major Setup
            map.put("CS", 0);
            map.put("Data", 0);
            map.put("Cyber", 0);
            map.put("Other", 0);
        } else if (flag == 1){ // If Minor Setup
            map.put("Data", 0);
            map.put("Cyber", 0);
            map.put("Math", 0);
            map.put("Other", 0);
        }
        return map;
    }

    private static void printData (Map<String, Map<String, Integer>> data){  // Prints all Data from the Map 
        Set<String> dataSet = data.keySet();
        Object[] dataKeys = dataSet.toArray();

        Map<String, Integer> majors = data.get(dataKeys[0]);
        Map<String, Integer> minors = data.get(dataKeys[1]);

        Set<String> majorSet = majors.keySet();
        Set<String> minorSet = minors.keySet();

        Object[] majorKeys = majorSet.toArray();
        Object[] minorKeys = minorSet.toArray();

        float studentNumber = getStudentNumber(majors, majorKeys);
        System.out.println("\n\n\nNumber of Students Surveyed: " + (int)studentNumber);

        System.out.println("\n\nMajors of Students in the Survey:");
        for (int i = 0; i < majorKeys.length; i++){
            if (studentNumber == 0){
                System.out.println("".format("%-10s %3d %10.2f", majorKeys[i], majors.get(majorKeys[i]), studentNumber));
            } else {
                System.out.println("".format("%-10s %3d %10.2f", majorKeys[i], majors.get(majorKeys[i]), (majors.get(majorKeys[i]) / studentNumber) * 100));
            }
        }

        studentNumber = getStudentNumber(minors, minorKeys);

        System.out.println("\n\nMinors of Computer Science Students in Survey:");
        for (int i = 0; i < minorKeys.length; i++){
            if (studentNumber == 0){
                System.out.println("".format("%-10s %3d %10.2f", minorKeys[i], minors.get(minorKeys[i]), studentNumber));
            } else {
                System.out.println("".format("%-10s %3d %10.2f", minorKeys[i], minors.get(minorKeys[i]), (minors.get(minorKeys[i]) / studentNumber) * 100));
            }
        }
        System.out.println("\n\n");
        return;
    }

    public static void main (String[] args){
        keyboard = new Scanner(System.in);

        Map<String, Map<String, Integer>> data = getMajorsAndMinors(keyboard);

        printData(data);

        keyboard.close();
    }

}
