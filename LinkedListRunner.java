/* Name:
   Dr. Steinberg
   COP3330 Spring 2022
   Programming Assignment 5
*/

public class LinkedListRunner 
{
    
    public static void main(String []args)
    {
        LinkedList<String> lst = new LinkedList<String>();
        
        lst.insert("Sonic");
        lst.insert("Tails");
        lst.insert("Knuckles");
        lst.insert("Eggman");
        
        System.out.println(lst.toString());
        
        lst.remove("Eggman");
        System.out.println(lst.toString());
		
		lst.clear();
		System.out.println(lst.toString());
        
        System.out.println("Creating new list...");
        
        LinkedList<Integer> lst2 = new LinkedList<Integer>();
        
        lst2.insert(0);
        lst2.insert(1);
        lst2.insert(7, 99);
		lst2.insert(5);
		lst2.insert(4, 1);
		lst2.insert(8, 3);
        System.out.println(lst2.toString());
    }
}