package project2;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class CodeProgram 
{

	public static void main(String[] args) 
	{
		menu();
	}
	
	public static void menu()
	{
		int choice = 0;
		Scanner scanner = new Scanner(System.in);
		System.out.println("Type 1 for Substitution Cipher.");
		System.out.println("Type 2 for Shuffle Cipher.");
		System.out.print("Choice: ");
		choice = scanner.nextInt();
		choiceMapper(choice,scanner);
	}
	
	public static void choiceMapper(int choice, Scanner scanner)
	{
		switch(choice)
		{
		case 1:
			substitutionCipher(scanner);
			break;
		case 2:
			shuffleCipher(scanner);
			break;
		default:
			System.out.println("Not a valid choice please try again!\n");
			menu();
		}
	}
	
	public static void substitutionCipher(Scanner scanner)
	{
		String inputFileName = "";
		String outputFileName = "";
		String input = "";
		String coding = "";
		int key = 0;

		System.out.print("What is the key (shift amount) for your code: ");
		key = scanner.nextInt();
		
		System.out.println("Substitution Cipher\n\t-Shift Amount = "+key);
		System.out.print("Enter input file name: ");
		scanner.nextLine();
		inputFileName = scanner.nextLine();
		
		System.out.print("Enter output file name: ");
		outputFileName = scanner.nextLine();
		
		System.out.print("Encode (E) or Decode (D)");
		coding = scanner.nextLine();
		
		File in = new File(inputFileName);
		File out = new File(outputFileName);
		try 
		{
			if(!in.exists())
			{
				in.createNewFile();
			}
			if(!out.exists())
			{
				out.createNewFile();
			}
		} 
		catch (IOException e) 
		{
			System.out.println("Could not create file");
		}
		SubstitutionCipher cipher = new SubstitutionCipher(key);
		
		input = fileRead(in);
		
		if(coding.toLowerCase().equals("e"))
		{
			fileWrite(cipher.encode(input),out);
			System.out.println("Encoded text is saved in "+outputFileName);
		}
		else if(coding.toLowerCase().equals("d"))
		{
			fileWrite(cipher.decode(input),out);
			System.out.println("Decoded text is saved in "+outputFileName);
		}
		else
		{
			System.out.println("Not a valid entry please try again!");
			menu();
		}
		again(scanner);
	}
	
	public static void shuffleCipher(Scanner scanner)
	{
		String inputFileName = "";
		String outputFileName = "";
		String input = "";
		String coding = "";
		int key = 0;

		System.out.print("What is the key (shift amount) for your code: ");
		key = scanner.nextInt();
		
		System.out.println("Shuffle Cipher\n\t-Shift Amount = "+key);
		System.out.print("Enter input file name: ");
		scanner.nextLine();
		inputFileName = scanner.nextLine();
		
		System.out.print("Enter output file name: ");
		outputFileName = scanner.nextLine();
		
		System.out.print("Encode (E) or Decode (D)");
		coding = scanner.nextLine();
		
		File in = new File(inputFileName);
		File out = new File(outputFileName);
		try 
		{
			if(!in.exists())
			{
				in.createNewFile();
			}
			if(!in.exists())
			{
				out.createNewFile();
			}
		} 
		catch (IOException e) 
		{
			System.out.println("Could not create file");
		}
		ShuffleCipher cipher = new ShuffleCipher(key);
		
		input = fileRead(in);
		
		if(coding.toLowerCase().equals("e"))
		{
			fileWrite(cipher.encode(input),out);
			System.out.println("Encoded text is saved in "+outputFileName);
		}
		else if(coding.toLowerCase().equals("d"))
		{
			fileWrite(cipher.decode(input),out);
			System.out.println("Decoded text is saved in "+outputFileName);
		}
		else
		{
			System.out.println("Not a valid entry please try again!");
			menu();
		}
		again(scanner);
	}
	
	public static void fileWrite(String statement, File file)
	{	
		try 
		{
			PrintWriter pw = new PrintWriter(file);
			pw.print(statement);
			pw.close();
		} 
		catch (FileNotFoundException e) 
		{
			System.out.print("File does not exist");
		}
	}
	
	public static String fileRead(File file)
	{
		String line = "";
		try 
		{
			Scanner scanner = new Scanner(file);
			line = scanner.nextLine();
			scanner.close();
		} 
		catch (FileNotFoundException e) 
		{
			System.out.print("File does not exist");
		}
		return line;
	}
	
	public static void again(Scanner scanner)
	{
		String choice = "";
		System.out.print("Do you want to work on another message (Y or N): ");
		choice = scanner.nextLine();
		if(choice.toLowerCase().equals("y"))
		{
			System.out.println();
			menu();
		}
		else
		{
			System.out.print("Thank you");
		}
	}

}
