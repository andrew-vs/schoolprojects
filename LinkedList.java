/* Name: Andrew Van Siclen
   Dr. Steinberg
   COP3330 Spring 2022
   Programming Assignment 5
*/

class Node <T> {
    
    T data;
    Node next;
    
    Node(){
        
        this.data = null;
        this.next = null;
        System.out.println("Node() Constructor Invoked...");
    }
    
    Node(T data){
        
        this.data = data;
        this.next = null;
        System.out.println("Node(T data) Constructor Invoked...");
        
        
    }
}

public class LinkedList <T> {
    
    Node head;
    int length;
    
    LinkedList() {
        
        System.out.println("LinkedList() Constructor Invoked...");
        this.head = null;
        this.length = 0;
        
    }
    
    void insert(T data) {
        
        Node add = new Node(data);
        
        if(head == null) {
            
            head = add;
            this.length++;
            return;
        }
        
        Node temp = head;
        
        while (temp.next != null) {
            
            temp = temp.next;
        }
        
        temp.next = add;
        this.length++;
    }
    
    void insert(int pos, T data) {
        
        if(pos < 1 || pos > this.length+1) {
            
            System.out.println("Out of range!");
            return;
        }
        
        Node add = new Node(data);
        
        if(pos == 1) {
            
            add.next = head;
            head = add;
            this.length++;
            return;
        }
        
        if (pos == this.length()+1){
            
            Node temp = head;
            while(temp.next != null){
                
                temp = temp.next;
            }
            
            temp.next = new Node(data);
            this.length++;
            return;
        }
        
        
        Node current = head;
        int tracker = 1;
        while(tracker <= pos) {
            
            current = current.next;
            tracker++;
        }
        
        add.next = current.next;
        current.next = add;
        this.length++;
    }
    
    void remove(T data) {
        
        Node temp = head;
        while(temp.next != null) {
            
            if(temp.next.data == data) {
                break;
            }
            
            temp = temp.next;
        }
        
        temp.next = temp.next.next;
        this.length--;
    }
    
    void clear(){
        
        this.head = null;
        this.length = 0;
    }
    
    boolean empty() {
        
        return this.length == 0;
    }
    
    int length() {
        
        return this.length;
    }
    
    @Override
    public String toString() {
        
        if(head == null){
            
            return "Empty List";
        }
        
        String print = "";
        Node temp = head;
        while(temp != null){
                
            if(temp.next!= null){
                
                print += temp.data + " ---> ";
            }
            else{
                
                print += temp.data;
            }
            
            temp = temp.next;
        }
        
        return print;
    }
}
