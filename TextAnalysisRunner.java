/* Name:
 * Dr. Steinberg
 * COP3330
 * Programming Assignment 2
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;
import java.util.Scanner;

public class TextAnalysisRunner {
    
    public static void main(String[] args) {
        
        System.out.println("Beginning Text Analysis...");
        
        
        //file objects
        File myObj = new File("sample1.txt"); //file object
        File myObj2 = new File("sample2.txt"); //file object
        File myObj3 = new File("macbethexcerpts.txt"); //file object
        
        Random rand = new Random(0); //create new Random class object
        
        //Scanner instances assign to null
        Scanner fileio = null;
        Scanner fileio2 = null;
        Scanner fileio3 = null;
        
        int num = rand.nextInt(96) + 1;
        int num2 = rand.nextInt(114) + 1;
        int num3 =rand.nextInt(128) + 1;

        
        String [] data = new String [num]; //create string to store document 1
        String [] data2 = new String [num2]; //create string to store document 2
        String [] data3 = new String [num3]; //create string to store document 3
        
        
        try 
        {
            fileio = new Scanner(myObj);
            fileio2 = new Scanner(myObj2);
            fileio3 = new Scanner(myObj3);
        }
        catch (FileNotFoundException e) //do not worry about this just yet. We will learn about exception handling at the end
        {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        
        int x = 0;
        
        while (fileio.hasNextLine() && x < num) 
        {
            data[x] = fileio.nextLine();
            ++x;
        }
        
        x = 0;
        
        while (fileio2.hasNextLine() && x < num2) 
        {
            data2[x] = fileio2.nextLine();
            ++x;
        }
        
        x = 0;
        
        while (fileio3.hasNextLine() && x < num3) 
        {
            data3[x] = fileio3.nextLine();
            ++x;
        }
        
        System.out.println("Creating a TextAnalysis object text1 with limit " + num + ".");
        TextAnalysis text1 = new TextAnalysis(num, data);
        
        System.out.println("Here is the following text...");
        System.out.println();
        text1.display();
        
        System.out.println();
        
        System.out.println("Before any analysis is peformed for text1...");
        text1.tableDisplay();
        System.out.println();

        System.out.println("Now Performing a Letter Analysis for text1...");
        
        text1.letterAnalysis();
        
        System.out.println("After letter analysis is peformed for text1...");
        
        text1.tableDisplay();
        
        System.out.println();
        
        System.out.println("Now Performing a Word Analysis for text1...");
        
        text1.wordAnalysis();
        
        System.out.println("After letter Word Analysis (sentence limit) is peformed for text1...");
        
        text1.wordAnalysis(99);
        
        text1.tableDisplay();

        fileio.close();
        
        System.out.println();
        System.out.println();
        
        System.out.println("Creating a TextAnalysis object text2 with limit " + num2 + ".");
        TextAnalysis text2 = new TextAnalysis(num2, data2);
        
        System.out.println("Here is the following text...");
        System.out.println();
        text2.display();
        
        System.out.println();
        
        System.out.println("Before any analysis is peformed for text2...");
        text2.tableDisplay();
        System.out.println();

        System.out.println("Now Performing a Letter Analysis for text2...");
        
        text2.letterAnalysis();
        
        System.out.println("After letter analysis is peformed for text2...");
        
        text2.tableDisplay();
        
        System.out.println();
        
        System.out.println("Now Performing a Word Analysis for text2...");
        
        text2.wordAnalysis();
        
        System.out.println("After letter Word Analysis (sentence limit) is peformed for text2...");
        
        text2.wordAnalysis(99);
        
        text2.tableDisplay();

        fileio2.close();
        
        System.out.println();
        System.out.println();
        
        System.out.println("Creating a TextAnalysis object text3 with limit " + num3 + ".");
        TextAnalysis text3 = new TextAnalysis(num3, data3);
        
        System.out.println("Here is the following text...");
        System.out.println();
        text3.display();
        
        System.out.println();
        
        System.out.println("Before any analysis is peformed for text3...");
        text3.tableDisplay();
        System.out.println();

        System.out.println("Now Performing a Letter Analysis for text3...");
        
        text3.letterAnalysis();
        
        System.out.println("After letter analysis is peformed for text3...");
        
        text3.tableDisplay();
        
        System.out.println();
        
        System.out.println("Now Performing a Word Analysis for text3...");
        
        text3.wordAnalysis();
        
        System.out.println("After letter Word Analysis (sentence limit) is peformed for text3...");
        
        text3.wordAnalysis(21);
        
        text3.tableDisplay();

        fileio3.close();
        
        System.out.println("Ending Analysis...");
        
    }
    
}
