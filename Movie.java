// COP3330 Object Oriented Programming
// Andrew Van Siclen
// Spring 2022

import java.util.Arrays;


public class Movie {
    
    private String title;
    private double boxoffice;
    
    public Movie() {
    
    System.out.println("Movie object created");
    
    }

    public Movie(String title, double boxoffice){
        
       this.title = title;
       this.boxoffice = boxoffice;
       
        
    }
    
    public void Who()
    {    
        System.out.println("Who");   
    }
    
    public String getTitle(){
        return title;   
    }
    
    public Double getboxoffice(){
        return boxoffice;
    }

    public static void main(String [] args){
        
        Movie obj2 = new Movie("Thor", 1000000.01);
        System.out.printf("%s, %.2f%n", obj2.getTitle(), obj2.getboxoffice());
        System.out.println ("OMG !" + 1 * 6 + "Dr. Steinberg Rocks !" + 8 / 2) ;
      
        int arr [] =  new int [5];
        System.out.println(Arrays.toString(arr));
        Arrays.fill(arr, 2, 2, 2);
        System.out.println(Arrays.toString(arr));
        
        
    }
}
