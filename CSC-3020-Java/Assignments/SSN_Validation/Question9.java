package package1;

import java.util.Scanner;

public class Question9 {

	public static void main(String[] args) 
	{
		Scanner scanner= new Scanner(System.in);
		
		print("Enter a SSN: ");
		String ssn = scanner.nextLine();
		scanner.close();
		
		if(checkInput(ssn))
		{
			print(ssn+" is a valid social security number");
		}
		else
		{
			print(ssn+" is an invalid social security number");
		}
	}
	
	public static boolean checkInput(String ssn)
	{
		if(ssn.length() == 11)
		{
			if(checkValidCharacters(ssn))
			{
				if(checkDashes(ssn))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	
	public static boolean checkValidCharacters(String ssn)
	{
		boolean isValid = true;
		for(int i = 0; i < ssn.length(); i++)
		{
			isValid = isValidChar(ssn.charAt(i));
			if(!isValid)
			{
				return isValid;
			}
		}
		
		return isValid;
	}
	
	public static boolean checkDashes(String ssn)
	{
		if(ssn.charAt(3) == '-' && ssn.charAt(6) == '-')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public static void print(String p)
	{
		System.out.print(p);
	}
	
	public static boolean isValidChar(char c) 
	{
	    return (c >= '0' && c <= '9')||(c == '-');
	}

}
