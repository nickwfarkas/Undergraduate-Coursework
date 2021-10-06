package package1;
import java.util.*;

public class Question16 
{

	public static void main(String[] args) 
	{
		String first;
		String second;
		
		Scanner scanner = new Scanner(System.in);  // Create a Scanner object
	    System.out.println("Enter the first string: ");
	    first = scanner.nextLine();
	    
	    System.out.println("Enter the first string: ");
	    second = scanner.nextLine();
	    
	    String answer = findCommonPrefix(first, second); 
        
        if (answer.length() > 0) 
        {
            System.out.println("The common prefix is " + answer); 
        }
        else
        {
        	System.out.println(first+" and "+second+" no common prefix");
        }
             
        scanner.close();
	}
	
	public static String findCommonPrefix(String first, String second) 
    { 
        String result = "";
        int x = 0;
        int y = minLength(first, second)-1;
        
        while (x <= y) 
        { 
            int m = (x + y)/2; 
  
            if (containsPrefix(first, second, m))
            { 
                result = result + first.substring(x, m + 1); 
                x = m + 1; 
            }  
            else
            { 
                y = m - 1; 
            } 
        } 
  
        return result; 
    } 
	
	public static int minLength(String first, String second) 
    { 
        if (second.length() < first.length()) 
        { 
            return second.length(); 
        }
        else
        {
        	return first.length(); 
        }
    } 
  
    public static boolean containsPrefix(String first, String second, int i) 
    { 
            for (int j = 0; j <= i; j++)
            {
            	if (second.charAt(j) != first.charAt(j))
            	{
            		return false;
            	}
            }
                
        return true; 
    } 
} 


