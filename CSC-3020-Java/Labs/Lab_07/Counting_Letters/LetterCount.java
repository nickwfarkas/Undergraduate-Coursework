package lab_07;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class LetterCount {

	public static void main(String[] args) 
	{
		String fileName = "";
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Please enter the file name: ");
		fileName = scanner.nextLine();
		
		File in = new File(fileName);
		File out = new File("letterCount.txt");
		int[] count = fileRead(in);
		fileWrite(count,out);
		
		scanner.close();
	}
	
	public static int[] fileRead(File file)
	{
		String temp;
		int[] nums = new int[26];
		
		try 
		{
			Scanner scanner = new Scanner(file);
			while(scanner.hasNext())
			{
				temp = scanner.nextLine().toLowerCase();
				for(int i = 0; i < temp.length(); i++)
				{
					if(Character.isLetter(temp.charAt(i)))
					nums[temp.charAt(i)-'a'] += 1;
				}
			}
			
			scanner.close();
		} 
		catch (FileNotFoundException e) 
		{
			System.out.println("File does not exist");
		}
		catch (NoSuchElementException e) 
		{
			System.out.println("File is empty");
		}
		return nums;
	}
	
	public static void fileWrite(int[] count, File file)
	{	
		try 
		{
			PrintWriter pw = new PrintWriter(file);
			for(int i = 0; i < count.length; i++)
			{
				pw.printf("The occurrence of %c's is %d\n",'A'+i,count[i]);
			}
			System.out.print("File created!");
			pw.close();
		} 
		catch (FileNotFoundException e) 
		{
			System.out.println("File does not exist");
		}
	}

}
