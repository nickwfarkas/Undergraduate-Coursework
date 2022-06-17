package assignment7;
import java.io.*;
import java.util.*;

public class Question5 
{

	public static void main(String[] args) 
	{
		File in = new File("numbers.txt");
		File out = new File("output.txt");
		int[] nums = fileRead(in);
		fileWrite(frequency(nums),out);
	}
	
	public static void fileWrite(int[] freq, File file)
	{	
		try 
		{
			PrintWriter pw = new PrintWriter(file);
			pw.printf("Rating Frequency\n");
			for(int i = 0; i < freq.length; i++)
			{
				pw.printf("%d       %d\n",(i+1),freq[i]);
			}
			System.out.print("File created!");
			pw.close();
		} 
		catch (FileNotFoundException e) 
		{
			System.out.print("File does not exist");
		}
	}
	
	public static int[] fileRead(File file)
	{
		int i = 0;
		int[] nums = new int[20];
		
		try 
		{
			Scanner scanner = new Scanner(file);
			while(scanner.hasNext())
			{
				nums[i] = scanner.nextInt();
				i++;
			}
			
			scanner.close();
		} 
		catch (FileNotFoundException e) 
		{
			System.out.print("File does not exist");
		}
		catch (NoSuchElementException e) 
		{
			System.out.print("File is empty");
		}
		return nums;
	}
	
	public static int[] frequency(int[] nums)
	{
		int [] freq = new int[5];
		for(int i = 0; i < nums.length; i++)
		{
			freq[nums[i]-1] += 1;
		}
		return freq;
	}

}
