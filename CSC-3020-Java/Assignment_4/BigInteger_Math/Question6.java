package assignment_4;

import java.math.BigInteger;

public class Question6 
{

	public static void main(String[] args) 
	{
		BigInteger b = new BigInteger(Long.toString(Long.MAX_VALUE));
		int i = 0;
		
		while(i < 10)
		{
			b = b.add(BigInteger.ONE);
			
			if(b.mod(BigInteger.valueOf(5)).compareTo(BigInteger.ZERO) == 0||
					b.mod(BigInteger.valueOf(6)).compareTo(BigInteger.ZERO) == 0)
			{
				System.out.println(b);
				i++;
			}
		}
	}

}
