package norm;

public class MyInteger 
{
	private int _value;
	
	MyInteger(int value)
	{
		_value = value;
	}
	
	int getInteger() {return _value;}
	
	boolean isEven()
	{
		return _value%2 == 0;
	}
	
	boolean isOdd()
	{
		return _value%2 != 0;
	}
	
	boolean isPrime()
	{
		if (_value <= 1)
		{
			return false; 
		}
        
        for (int i = 2; i < _value; i++)
        {
            if (_value % i == 0)
            {
               return false;
            }
        }
        return true; 
	}
	
	public static boolean isEven(int value)
	{
		return value%2 == 0;
	}
	
	public static boolean isOdd(int value)
	{
		return value%2 != 0;
	}
	
	public static boolean isPrime(int value)
	{
		if (value <= 1)
		{
			return false; 
		}
        
        for (int i = 2; i < value; i++)
        {
            if (value % i == 0)
            {
               return false;
            }
        }
        return true;
	}
	
	public static boolean isEven(MyInteger myInteger)
	{
		return myInteger.getInteger()%2 == 0;
	}
	
	public static boolean isOdd(MyInteger myInteger)
	{
		return myInteger.getInteger()%2 != 0;
	}
	
	public static boolean isPrime(MyInteger myInteger)
	{
		if (myInteger.getInteger() <= 1)
		{
			return false; 
		}
        
        for (int i = 2; i < myInteger.getInteger(); i++)
        {
            if (myInteger.getInteger() % i == 0)
            {
               return false;
            }
        }
        return true;
	}
	
	boolean equals(int i)
	{
		return i == _value;
	}
	
	boolean equals(MyInteger myInteger)
	{
		return myInteger.getInteger() == _value;
	}
	
	public static int parseInt(char[] c)
	{
		return Integer.valueOf(String.valueOf(c));
	}
	
	public static int parseInt(String s)
	{
		return Integer.valueOf(s);
	}
	
}
