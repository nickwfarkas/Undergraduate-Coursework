package assignment_4;

public class MyString2 
{
	private char[] myString;
	
	public MyString2(String s)
	{
		myString = new char[s.length()];
		for(int i = 0; i < s.length(); i++)
		{
			myString[i] = s.charAt(i);
		}
	}
	
	public String getArray()
	{
		String s = "";
		for(int i = 0; i < this.myString.length; i++)
		{
			s += myString[i];
		}
		return s;
	}
	
	public MyString2 substring(int begin)
	{
		String s = "";
		
		for(int i = begin; i < this.myString.length; i++)
		{
			s += this.myString[i];
		}
		return new MyString2(s);
	}
	
	public MyString2 toUpperCase()
	{
		String s = "";
		
		for(int i = 0; i < myString.length; i++)
		{
			s += Character.toUpperCase(myString[i]);
		}
		return new MyString2(s);
	}
	
	public static MyString2 valueOf(boolean b)
	{
		if(b)
		{
			return new MyString2("true");
		}
		else
		{
			return new MyString2("false");
		}
	}
}
