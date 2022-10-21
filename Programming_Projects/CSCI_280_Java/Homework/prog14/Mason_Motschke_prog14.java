// Mason Motschke - CSCI_280 - HW14 - 7/13/2022

import java.io.*;

public class Mason_Motschke_prog14 {

    public static void main (String[] args){
    
        try {
        
            int bufferSize = 1000000;
            
            // Read data from input.txt using FileReader & BufferedReader
            String inputName = "input.txt";
            FileReader inputFile = new FileReader(inputName);
            BufferedReader input = new BufferedReader(inputFile);
            
            char[] buff = new char[bufferSize];
            input.read(buff);
            
            // Input buffer being stored as string
            String fileData = new String(buff);
            
            System.out.printf("\nData in file 'input.txt': \n");
            System.out.println("\n" + fileData);
            
            // Read input string from keyboard using BufferedReader
            InputStreamReader user = new InputStreamReader(System.in);
            BufferedReader keyboard = new BufferedReader(user);
            
            buff = new char[bufferSize];
            
            System.out.printf("Enter input from keyboard: ");
            String data = keyboard.readLine();
            
            System.out.printf("\nData from keyboard: \n");
            System.out.println("\n" + data);
            
            // Read from 'inpt.txt' using StringReader, print char by char, each char = newLine;
            StringReader string = new StringReader(fileData);
            
            buff = new char[bufferSize];
            
            string.read(buff);
            
            System.out.printf("\nData from String of 'input.txt' file char by char: \n");
            for (int i = 0; i < buff.length; i++){
            
                if (buff[i] != 0){ // If char != null, print char
                
                    System.out.println(buff[i]);
                    
                }
            }
            
            // Print string obj fileData to file called 'output.txt' using PrintWriter
            String outputName = "output.txt";
            FileWriter file = new FileWriter(outputName);
            PrintWriter writer = new PrintWriter(file);
            
            buff = new char[fileData.length()];
            
            for (int i = 0; i < fileData.length(); i++){
            
                buff[i] = fileData.charAt(i);
                
                if (buff[i] != 0){ // If char != null, write char to file.
                
                    writer.append(buff[i]);
                    
                }
            }
            
            System.out.println("\nOutputing String to 'output.txt'!!!\n");
            writer.flush();
            System.out.println(" - Finished outputing to 'output.txt'\n");
            
            // Close Readers before file end
            inputFile.close(); input.close(); keyboard.close();
            user.close(); string.close();
            file.close(); writer.close();
        
        } catch (Exception e){ e.getStackTrace(); }
    }
}




