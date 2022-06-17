package package1;

import java.util.Scanner;

public class Question17 
{

	public static void main(String[] args) 
	{
		int number, width;
		
		Scanner scanner = new Scanner(System.in);  // Create a Scanner object
	    System.out.println("Enter your number: ");
	    number = scanner.nextInt();
	    
	    System.out.println("Enter the the number's width: ");
	    width = scanner.nextInt();
	    
	    System.out.print(format(number,width));
	    
	    scanner.close();
	}
	
	public static String format(int number, int width)
	{
		String numberToString = Integer.toString(number);
		int j = width - numberToString.length();
		String newString = "";
		
		if(j > 0)
		{
			for(int i = 0; i < j; i++)
			{
				newString += "0";
			}
		}
		else
		{
			return numberToString;
		}
		
		return newString+numberToString;
	}
}
