package assignment7;

public class Question4 {

	public static void main(String[] args) 
	{
		String s = null;
		
		try
		{
			s.equals("Hello");
		}
		catch(NullPointerException n)
		{
			//Subclass
			System.out.println(n);
		}
		catch(Exception e)
		{
			//Superclass
			System.out.println(e);
		}

	}

}
