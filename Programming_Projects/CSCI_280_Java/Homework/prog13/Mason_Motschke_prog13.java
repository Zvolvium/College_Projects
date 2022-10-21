// Mason Motschke - CSCI_280 - HW13 - 7/11/2022

import java.io.*;
import java.util.Scanner;

public class Mason_Motschke_prog13 {

    public static void main (String[] args){
    
        try {
            // Create File
            String fileName = "output.txt";
            File obj = new File(fileName);
            OutputStream Output = new FileOutputStream(obj);
            
            if (!obj.exists()){ obj.createNewFile(); }
            
            // Get User Input
            int totalSize = 50, length;
            Scanner user = new Scanner(System.in);
            byte[] buff;
            
            System.out.printf("\nEnter input (only 50 bytes will be read): ");
            while (totalSize > 0){
            
                System.out.printf("\nKeep Entering Data: 50 bytes not yet reached!!\n");
                buff = user.nextLine().getBytes();
                length = buff.length;
                if (length > totalSize){
                
                    // If length is greater write to all available space in buff to stream
                    Output.write(buff, 0, totalSize);
                    Output.flush(); break;
             
                } else {
                
                    // Else decrement and write available bytes
                    totalSize -= length;
                    Output.write(buff, 0, length);
                    
                }
            }
            // Close Unneeded Scanner and Output Streams
            user.close(); Output.close();
            
            // Read From File + Print to Screen
            InputStream Input = new FileInputStream(fileName);
            buff = new byte[50];
            Input.read(buff);
            
            String data = new String(buff);
            System.out.printf("\nTxt from output.txt: ");
            System.out.printf("%s\n", data);
            
            Input.close();
            
        } catch (IOException ioe){ }
    }
}




