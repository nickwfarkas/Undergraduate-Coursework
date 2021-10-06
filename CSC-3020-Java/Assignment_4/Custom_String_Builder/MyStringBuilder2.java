package assignment_4;

public class MyStringBuilder2 
{
	private char[] myString;
	private int size;
	private int capacity;
	
	MyStringBuilder2(String s)
	{
		myString = new char[s.length()];
		for(int i = 0; i < s.length(); i++)
		{
			myString[i] = s.charAt(i);
		}
		size = getSize();
		capacity = myString.length;
	}
	
	public int getSize()
	{
		int size = 0;
		for(int i = 0; i < myString.length; i++)
		{
			if(myString[i] != 0)
			{
				size++;
			}
		}
		return size;
	}
	
	public int getCapacity()
	{
		return myString.length;
	}
	
	public String getMyString()
	{
		String s  = "";
		for(int i = 0; i < myString.length; i++)
		{
			s += myString[i];
		}
		return s;
	}
	
	public MyStringBuilder2 append(MyStringBuilder2 s)
	{
		String org = this.getMyString();
		
		this.myString = new char[org.length()+this.size];
		for(int i = 0; i < s.size; i++)
		{
			org += s.myString[i];
		}
		
		for(int i = 0; i < org.length(); i++)
		{
			this.myString[i] = org.charAt(i);
		}
		
		return this;
	}
	
	public MyStringBuilder2 substring(int begin, int end)
	{
		String s = "";
		for(int i = begin; i < end; i++)
		{
			s += myString[i];
		}
		return new MyStringBuilder2(s);
	}
}
