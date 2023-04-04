import javax.sound.midi.Track;

/*
 * File Name: prog4MAM.java
 * 
 * Java Version: 17.0.5
 * 
 * Author: Mason A. Motschke
 * 
 * Contact: mason.motschke@und.edu
 * 
 * Comment:
 *      Write each of the following functions.
 *      The function header must be implemented exactly as specified.
 *      For Python the type of value that should be returned from each function is in parenthesis in the function description.
 *      Write a main function that HW4s each of the required functions/methods.
 *      You do not have to use keyboard input in main, just ensure that each function/method is called more than one.*
 *      Remember that the functions themselves will not display any output,
 *      they will return values that can then be written to the screen.
*/

public class prog4MAM {

    int findMaxScore (int[] scoresList){
        /*
            (int) def findMaxScore (scoresList): 
            int findMaxScore (int[] scoresList) 
            int findMaxScore (int scoresList[], int size)

            Return the largest integer value (int) found in the list.
            DO NOT make any assumptions about the range of values in the list.
            size is the number of items in the list/array.
        */

        int max = -1000000;
        for (int i = 0; i < scoresList.length; i++){
            if (scoresList[i] > max){
                max = scoresList[i];
            }
        }

        return max;
    }

    int findMinScore (int[] scoresList){
        /*
            (int) def findMinScore (scoresList): 
            int findMinScore (int[] scoresList) 
            int findMinScore (int scoresList[], int size) 
            
            Return the smaller integer value (int) found in the list.
            DO NOT make any assumptions about the range of values in the list.
            size is the number of items in the list/array.
        */

        int min = 1000000;
        for (int i = 0; i < scoresList.length; i++){
            if (scoresList[i] < min){
                min = scoresList[i];
            }
        }

        return min;
    }

    boolean hasPerfectScore (int[] scoresList){
        /*
            (boolean) def hasPerfectScore (scoresList): 
            boolean hasPerfectScore (int[] scoresList) 
            bool hasPerfectScore (int scoresList[], int size) 
            
            Returns the appropriate true reserved word if any of the scores is 100 or greater,
            otherwise returns the appropriate false reserved word.
        */

        for (int i = 0; i < scoresList.length; i++){
            if (scoresList[i] >= 100){
                return true;
            }
        }

        return false;
    }

    double calcAverage (int[] scoresList){
        /*
            (float) def calcAverage (scoresList): 
            double calcAverage (int[] scoresList) 
            double calcAverage (int scoresList[], int size) 
            
            Return the average (double) of all the scores found in the list.
            Return -1 if unable to determine an array – don’t let the program crash.
        */

        try {
            int av = 0;
            for (int i = 0; i < scoresList.length; i++){
                av += scoresList[i];
            }

            av = av / scoresList.length;

            return av;
        }
        catch (Exception e){
            return -1;
        }
    }

    String findStudentWithMax (int[] scoresList, String[] namesList){
        /*
            (str) def findStudentWithMax (scoresList, namesList): 
            String findMaxScore (int[] scoresList, String[] namesList) 
            string findMaxScore (int scoresList[], string namesList[], int size) 
            
            Return the name of the student with the largest score.
            You can assume there will be only one student with the largest score.
            IF there were two students with the largest score (there won’t be) you can return the name of the first student with that score.
        */

        int max = findMaxScore(scoresList);

        String name = "NULL";
        for (int i = 0; i < scoresList.length; i++){
            if (scoresList[i] == max){
                name = namesList[i];
                break;
            }
        }

        return name;
    }

    int[] mergeLists (int[] list1, int[] list2){
        /*
            ([]) def mergeLists (list1, list2): 
            int[] mergeLists (int[] list1, int[] list2) 
            int* mergeLists (int list1[], int list2[]) 
            
            Return a new array/list made up of the values from the two lists, values from list1 first, then the values from list2.
            This might not find into the theme of the other functions,
            but we’ll still include it in the list of required functions.
        */
        int[] res = new int[list1.length + list2.length];

        int cnt = 0;
        for (int i = 0; i < list1.length; i++){
            res[cnt] = list1[i];
            cnt++;
        }
        for (int i = 0; i < list2.length; i++){
            res[cnt] = list2[i];
            cnt++;
        }

        return res;
    }

    double standardDeviation (int[] scoresList){
        /*
            (float) standardDeviation (scoresList) 
            Double standardDeviation (int[] scoresList) 
            double standardDeviation (int scoresList[], int size) 
            
            Return the standard deviation of the values.
            To find the standard deviation start with the average of the list – DO NOT repeat the code for calculating the average.
            Then for each value in the list subtract the average from that value and square the result.
            Find the average of the squared differences and then take the square root of that average. 
        */

        double av = calcAverage(scoresList);

        int[] temp = new int[scoresList.length];
        double res;
        for (int i = 0; i < scoresList.length; i++){
            res = (scoresList[i] - av);
            temp[i] = (int)(Math.pow(res, 2));
        }

        av = calcAverage(temp);

        res = Math.pow(av, 0.5);

        return res;
    }

    int findInList (int[] scoresList, int valueTofind){
        /*
            (int) def findInList (scoresList, valueToFind, startingIndex=0): 
            int findInList (int[] scoresList, int valueToFind) 
            int findInList (int[] scoresList, int valueToFind, int startingIndex) 
            int findInList (int scoresList[], int valueToFind) 
            int findInList (int scoresList[], int valueToFind, int startingIndex) 
            
            Return the index of the first occurrence of valueToFind.
            IF specified, starting searching at the specified index, otherwise start searching at index 0.
            This requires a default parameter in Python and overloaded functions/methods in Java and C++.
            In any of the functions return -1 if the value is not found.
        */

        return findInList(scoresList, valueTofind, 0);
    }
    int findInList (int[] scoresList, int valueToFind, int startingIndex){
        /*
            Comments same as method above -----/\
        */

        for (int i = startingIndex; i < scoresList.length; i++){
            if (scoresList[i] == valueToFind){
                return i;
            }
        }

        return -1;
    }

    public static void main (String[] args){
        // HW4 Functions
        int[] merge = {
            22, 65, 4, 8, 9, 200, 300
        };
        int[] scoreList = {
               12,     15,       16,       55,       90,      102,         3
        };
        String[] namesList = {
            "Tom", "Phil", "Jackie", "Mickel", "Trevor", "Teapot", "Trishia"
        };

        prog4MAM HW4 = new prog4MAM();

        int[] temp;
        
        System.out.printf("findMaxScore: %d\n", HW4.findMaxScore(scoreList));
        System.out.printf("findMinScore: %d\n", HW4.findMinScore(scoreList));
        System.out.printf("hasPerfectScore: %b\n", HW4.hasPerfectScore(scoreList));
        System.out.printf("calcAverage: %f\n", HW4.calcAverage(scoreList));
        System.out.printf("findStudentWithMax: %s\n", HW4.findStudentWithMax(scoreList, namesList));

        temp = HW4.mergeLists(scoreList, merge); System.out.printf("mergeLists: ");
        for (int i = 0; i < temp.length; i++){ System.out.printf("%d ", temp[i]); } System.out.println();
        temp = HW4.mergeLists(merge, scoreList); System.out.printf("mergeLists: ");
        for (int i = 0; i < temp.length; i++){ System.out.printf("%d ", temp[i]); } System.out.println();

        System.out.printf("standardDeviation: %f\n", HW4.standardDeviation(scoreList));
        System.out.printf("findInList: %d\n", HW4.findInList(scoreList, 56, 10));
        System.out.printf("findInList: %d\n", HW4.findInList(scoreList, 102));

        return;
    }

}