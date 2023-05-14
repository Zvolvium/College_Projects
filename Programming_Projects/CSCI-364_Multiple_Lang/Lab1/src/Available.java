package edu.und.cs364.quiz1;

/**
 * Available.java
 * David Apostal
 * 
 * Prints the number of cores available to the JVM. 
 * This number may include hardware threads available to each core.
 */
public class Available {
    public static void main(String[] args) {
        System.out.println("Available processors (cores): " +
                Runtime.getRuntime().availableProcessors());
    }
}
