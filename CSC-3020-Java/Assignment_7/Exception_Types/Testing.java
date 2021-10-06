package assignment7;
import java.io.*;
public class Testing {

	public static void main(String[] args) 
	{
		String x = null;
		try
		{
			ageRange(12);
		}
		catch(Exception s)
		{
			System.out.println(s);
		}
		
		try
		{
			ageRange(30);
		}
		catch(Exception s)
		{
			System.out.println(s);
		}
		
		try
		{
			x.equals("Hello");
		}
		catch(NullPointerException n)
		{
			System.out.println(n);
		}
		
		File file = new File("test.txt");
		FileInputStream fileInputStream = null;
		try
		{
			fileInputStream = new FileInputStream(file);
			fileInputStream.read();
		}
		catch (IOException e)
		{        
			System.out.println(e);
		}


	}
	
	 static void ageRange(int age)throws ExceptionA,ExceptionB
	 {  
	     if(age < 18)
	     {
	    	 throw new ExceptionA("Too Young!");
	     }
	     else if(age > 21)
	     {
	    	 throw new ExceptionB("Too Old!");
	     }
	     else
	     {
	    	 weirdAgeGroup();
	     }
	   }
	 
	 static void weirdAgeGroup()
	 {
		 System.out.println("Congratulations you're in!");
	 }

}
