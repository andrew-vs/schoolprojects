/* Andrew Van Siclen
  * Dr. Steinberg
  * COP3330 Spring 2022
  * Programming Assignment 2
  */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;
import java.util.Scanner;


public class TextAnalysis {
    
    // Declaring all variables from rubric, with the extra arrays for every-
    // upper and lowercase letter
    private String[] data;
    private int[] alphabet = new int[26];
    private int[] wordsize = new int[16];
    private int[] wordcount = new int[31];
    private int limit;
    private char[] letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    private char[] lettersUpper = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    // Getting the text from the files to fit into our variables
    public TextAnalysis(int limit, String[] data){
        
    this.data = data;
    this.limit = limit;
    
    }
    
    // A simple for loop to display the text file itself, line by line
    public void display(){
        
        for (int i = 0; i < limit; i++){
            
            System.out.println(data[i]);
            
        }  
    }
    
    // All information that was gathered is displayed here
    public void tableDisplay(){
        
        // Grabbing every upper case letter in the array from earlier
        System.out.println("Letter 	 Count");
        for(int i = 0; i < 26; i++){
 
            System.out.printf("%s	 %d\n", lettersUpper[i], alphabet[i]);
            
        }
        System.out.println("---------------------------------");
        System.out.println("Word Length 	Occurances");
        
        // Counting up to 15 starting from 1, with each word size matched
        for(int k = 1; k < 16; k++){
            
            System.out.printf("%d 		%d\n", k, wordsize[k]);
            
        }
        System.out.println("---------------------------------");
        System.out.println("Sentence Length 	Occurances");
        
        // Counting up to 30 now, with each sentence length
        for(int j = 1; j < 31; j++){
            
            System.out.printf("%d 			%d\n", j, wordcount[j]);
            
        }
        
        
    }
    
    // Getting the amount of each letter
    public void letterAnalysis(){
        
        for (int i = 0; i < limit; i++){
            
            // Making each line all lowercase
            String sentence;
            sentence = data[i].toLowerCase(); 
            
            // Getting the length of every sentence for our loop
            int sLength = sentence.length();
            
            // Making the sentence turn in to an array of characters instead of a string
            // Using getChars, the string is now an array of chars like in C
            char[] allChars = new char[sLength];
            sentence.getChars(0, sLength, allChars, 0);
            
            // Going through every single letter of every line and adding that-
            // letter to alphabet[k]
            for (int j = 0; j < sLength; j++){
                
                for (int k = 0; k < 26; k++){
                    
                    if (allChars[j] == letters[k]){
                        
                        alphabet[k]++;
                        
                    }  
                }         
            }
        }  
    }
    
    // Getting all word lengths
    public void wordAnalysis(){
        
        for (int i = 0; i < limit; i++){
            
            // Hear me out. This line is gross, but it removes all punctuation
            // ".replaceAll("\\p{Punct}", """ is the line that removes all-
            // punctuation except for apostrophies. Also, there are two kinds-
            // of apostrophies, ' and ’, Which is odd
            String replaced = data[i].replaceAll("--", " ").replaceAll("\\p{Punct}", "").replaceAll("'", "").replaceAll("’", "").replaceAll("\\d", "").replaceAll("  ", " ");
            
            // Now that replaced is every sentence with no punctuation,
            // eachWord is an array of every word in that sentence using .split()
            String[] eachWord = replaced.split(" ");
            
            // Now we can update wordsize with the length of every word
            for (int k = 0; k < eachWord.length; k++){
               
                wordsize[eachWord[k].length()]++;
    
            }
         
        }
    }
    
    // Sentence lengths are gathered here
    public void wordAnalysis(int num){
        
        // Get us out if num is larger than the limit
        if (num > limit){
            System.out.println("Exceeded and cannot produce an analysis on this component.");
            return;
        }
        
        // Going through 'num' sentences and analyzing length
        for (int i = 0; i < num; i++){
            
            // Printing every line because the output says so
            System.out.println(data[i]);
            
            // Removing punctuation again, but this time apostrophies dont matter
            // Did i mention ".replaceAll("\\d")" removes digits from strings?
            String replaced = data[i].replaceAll("\\p{Punct}", "").replaceAll("\\d", "").replaceAll("  ", " ");
            
            // Making each sentence an array of strings, then getting the length of that array for sentence length
            String[] eachWord = replaced.split(" ");
         
            wordcount[eachWord.length]++;
        }
        
    }
      
    // And the runner file from the project
    
    public static void main(String args[]) {
        
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
