package project2;

public class SubstitutionCipher extends Cipher implements MessageDecoder, MessageEncoder 
{
	int _shift;
	
	public SubstitutionCipher(int shift) 
	{
		_shift = shift;
	}
	
	private char encode(char c)
	{
		return (char) (c + _shift);
	}
	
	private char decode(char c)
	{
		return (char) (c - _shift);
	}
	
	@Override
	public String encode(String plainText) 
	{	
		String encoded = "";
		
		for(int i = 0; i < plainText.length(); i++)
		{
			encoded+=encode(plainText.charAt(i));
		}
		return encoded;
	}

	@Override
	public String decode(String ciperText) 
	{
		String decoded = "";
		
		for(int i = 0; i < ciperText.length(); i++)
		{
			decoded+=decode(ciperText.charAt(i));
		}
		
		return decoded;
	}

	@Override
	public String cipherText() 
	{
		return "SubstitutionCipher";
	}

	public static void main(String[] args) 
	{
		SubstitutionCipher s = new SubstitutionCipher(27);
		String test = "To Be Or Not To Be";
		test = s.encode(test);
		System.out.println(test);
		test = s.decode(test);
		System.out.println(test);
	}

}
