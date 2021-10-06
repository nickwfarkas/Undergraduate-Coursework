package lab;

import java.util.Scanner;

public class Lab_01 {

	public static void main(String[] args) 
	{
		String sent = "y";
		String input;
		int letters[];
		Scanner scanner= new Scanner(System.in);
		while(sent != "n")
		{
			print("Enter a line of text: ");
			input = scanner.nextLine();
			letters = letterCount(input.toLowerCase());
			
			printContents(letters);
			
			print("Would you like to enter another line? (y or n)\n");
			sent = scanner.nextLine();
		}
		
	}
	
	public static int[] letterCount(String input)
	{
		int letterCount[] = new int[26];
		for(int i =  0; i < input.length();  i++)
		{
			if(isLetter(input.charAt(i)))
			{
				letterCount[getValue(input.charAt(i))] += 1;
			}
		}
		
		return letterCount;
	}
	
	public static void printContents(int ar[])
	{
		for(int i = 0; i <  ar.length; i++)
		{
			if(ar[i] != 0)
			{
				print((Character.toUpperCase((char)(i+97)))+" = "+ar[i]+"\n");
			}
		}
	}
	
	public static boolean isLetter(char c)
	{
		if(((int)c) < 97 || ((int)c) > 123)
		{
			return false;
		}
		else return true;
	}
	
	public static int getValue(char c)
	{
		return ((int)c)-97;
	}
	
	public static void print(String s)
	{
		System.out.print(s);
	}
	
	public static void print(int i)
	{
		System.out.print(i);
	}
	
	public static void print(char c)
	{
		System.out.print(c);
	}

}
