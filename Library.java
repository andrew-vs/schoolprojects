/* Andrew Van Siclen
  * Dr. Steinberg
  * COP3330 Spring 2022
  * Programming Assignment 3
  */

public class Library {
    
    Book first;
    private int total;

    public Library() {
        
        this.first = null;
        this.total = 0;
        
    }
  
    public Library(Library library) {
        
        System.out.println("Copying your Library collection.");
        this.first = library.first;
        this.total = library.total;
        
    }
    
private class Book {
    
    private String title;
    private String author;
    private double cost;
    Book nextptr;

    public Book(String title, String author, double cost) {
        
        this.title = title;
        this.author = author;
        this.cost = cost;
    }

    public Book(Book old){
        
        this(old.getTitle(), old.getAuthor(), old.getCost());
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public double getCost() {
        return cost;
    }

}
  

    public void add(String title, String author, double cost) {
    
        Book book = new Book(title, author, cost);
    
        if(total < 5){    
        
            if(first == null){
            
                first = book;
            }
            else{
            
                Book temp = first;
            
                while(temp.nextptr != null){
                
                    temp = temp.nextptr;
                }
            
                temp.nextptr = book;
            }
        
            total++;
        }   
        else{
        
            System.out.println("Your library is full.");
        }
    }
  
    public Book search(String title){
        
        System.out.println("Looking up an existing book.");
        
        Book temp = first;
  
        if(first == null) {
            
            System.out.println("Library is empty");
            return null;
        }
        
        while(temp != null) {
            
            if(temp.getTitle().equals(title)){
                
                System.out.println(title);
                return temp;
            }
            
  
            temp = temp.nextptr;
        }
        
        return temp;
    }
  
    public void reverse(){
        
        Book previous = null;
        Book current = first;
        Book next = null;
        
        while (current != null){
            
            next = current.nextptr;
            current.nextptr = previous;
            previous = current;
            current = next;
        }
        
        first = previous;
    }
  
    public void remove(String title){
        
        Book prev = null;
        Book current = first;
  
        if(first == null) {
            
            System.out.println("Library is empty");
            return;
        }
        
        while(current != null) {
            
            if(current.getTitle().equals(title)){
                
                if(current == first){
                    
                    first = first.nextptr;
                    current = first;
                }
                else{
                    
                    prev.nextptr = current.nextptr;
                    current = current.nextptr;
                }
                
                total--;
            }
            else{
                
                prev = current;
                current = current.nextptr;
            } 
        }
        
        System.out.println();
    }
  
    public void clearLibrary(){
        
        System.out.println("Now clearing a library.");
        Book temp = first;
        
        if(first == null) {
            
            System.out.println("Library is empty");
            return;
        }
        
        while(temp != null) {
            
            first.nextptr = null;
            first = null;
            temp = temp.nextptr;
            first = temp;
        }
        
        total = 0;
    }

    public boolean empty(){
        
        System.out.println("Checking to see if library is empty.");
        
        if(total == 0){
            
            return true;
        }
            
        return false;
    }

    public boolean full(){
        
        if(total == 5){
            
            return true;
        }
            
        return false;
    }
  
    public String getTitle(Book temp){
        
        return temp.getTitle();
    }
  
    public void display(){
        
        Book temp = first;
  
        if(first == null) {
            
            System.out.println("Library is empty");
            return;
        }
        while(temp != null) {
            
            System.out.println("Title: "+temp.getTitle());
            System.out.println("Author: "+temp.getAuthor());
            System.out.println("Cost: "+temp.getCost());
            temp = temp.nextptr;
        }
        
        System.out.println();
    }
  
    public static void main(String args[]) {
        
        
        System.out.println("*********************************************");
        System.out.println("Beginning test with default constructor.");
        Library mylibrary = new Library();
        
        System.out.println("Lets start adding books to the collection.");
        
        mylibrary.add("Julius Caesar", "William Shakespeare", 12.99);
        mylibrary.add("The Great Gatsby", "F. Scott Fitzgerald", 10.99);
        mylibrary.add("The Canterbury Tales", "Geoffrey Chaucer", 14.99);
        mylibrary.add("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 13.99);
        mylibrary.add("Moby Dick", "Herman Melville", 10.99);
        mylibrary.display();
        
        System.out.println("Let's try adding a sixth book.");
        mylibrary.add("The Hunger Games", "Suzanne Collins", 11.99);
        
        
        System.out.println("*********************************************");
        System.out.println("Now it is time to copy the library");
        
        Library mylibrary2 = new Library(mylibrary);
        
        mylibrary2.display();
        
        System.out.println("*********************************************");
        System.out.println("Now I will reverse the collection order.");
        mylibrary2.reverse();
        mylibrary2.display();
        System.out.println("*********************************************");
        
        System.out.println("Now removing book from mylibrary.");
        mylibrary.remove("The Great Gatsby");
        mylibrary.display();
        
        System.out.println("*********************************************");
        System.out.println("Now lets add that book to the collection.");
        mylibrary.add("The Hunger Games", "Suzanne Collins", 11.99);
        mylibrary.display();
        System.out.println("*********************************************");
        
        System.out.println("Now clearing a library.");
        mylibrary.clearLibrary();
        System.out.println("Checking to see if library is empty.");
        
        if(mylibrary.empty())
            System.out.println("Empty");
        else
            System.out.println("Not Empty");
        
        
        System.out.println("*********************************************");
        System.out.println("Looking up an existing book.");
        Book temp = mylibrary2.search("The Canterbury Tales");
        System.out.println(temp.getTitle());
        System.out.println("Looking up a book that doesn't exist.");
        Book temp2 = mylibrary2.search("What if...");
        System.out.println(temp2);
        System.out.println("*********************************************");
        System.out.println("End of program run.");

    }
}
