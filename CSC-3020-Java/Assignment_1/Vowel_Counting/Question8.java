package package1;

import java.util.Scanner;

public class Question8 
{

	public static void main(String[] args) 
	{
		char letters[] = {'a', 'e', 'i', 'o', 'u'};
		Scanner scanner= new Scanner(System.in);
		
		print("Enter a string of characters: ");
		String s = scanner.nextLine();
		scanner.close();
		
		printResult(vowels(s), letters);
	}
	
	public static int[] vowels(String s)
	{
		int vowels[] =
		{
			getVowelCount(s, 'a'),
			getVowelCount(s, 'e'),
			getVowelCount(s, 'i'),
			getVowelCount(s, 'o'),
			getVowelCount(s, 'u'),
			getNonVowelCount(s)
		};
		
		return vowels;
	}
	
	public static void printResult(int vowels[], char letters[])
	{
		print("Number  of each lowercase vowel in the string:\n");
		for (int i = 0; i < 6; i++)
		{
			if (i == 5)
			{
				print("other characters: "+vowels[i]);
			}
			else
			{
				print(letters[i]+": "+vowels[i]+"\n");
			}
		}
	}
	
	public static int getVowelCount(String userEntry, char letter)
	{
		
		int count = 0;
	    for (int i = 0; i < userEntry.length(); i++)
	    {
	        if(Character.toLowerCase(userEntry.charAt(i)) == letter)
	        {
	            count++;
	        }
	    }
	    
	    return count;
	}
	
	public static int getNonVowelCount(String userEntry)
	{
		
		int count = 0;
	    for (int i = 0; i < userEntry.length(); i++)
	    {
	    	if
	        (
	        	Character.toLowerCase(userEntry.charAt(i)) != 'a'&&
	        	Character.toLowerCase(userEntry.charAt(i)) != 'e'&&
	        	Character.toLowerCase(userEntry.charAt(i)) != 'i'&&
	        	Character.toLowerCase(userEntry.charAt(i)) != 'o'&&
	        	Character.toLowerCase(userEntry.charAt(i)) != 'u'
	        )
	        {
	            count++;
	        }
	    }
	    
	    return count;
	}
	
	
	public static void print(String p)
	{
		System.out.print(p);
	}

}
