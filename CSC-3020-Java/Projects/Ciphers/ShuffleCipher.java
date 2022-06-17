package project2;

public class ShuffleCipher extends Cipher implements MessageDecoder, MessageEncoder 
{
	private int _n;
	
	public ShuffleCipher(int n) 
	{
		_n = n;
	}

	@Override
	public String encode(String plainText) 
	{
		String split1 = "";
		String split2 = "";
		String full = plainText;
		
		for(int j = 0; j < _n; j++)
		{
			split1 = "";
			split2 = "";
			
			for(int i = 0; i < full.length(); i++)
			{
				if(full.length()%2 == 0)
				{
					if(i < full.length()/2)
					{
						split1+=full.charAt(i);
					}
					else
					{
						split2+=full.charAt(i);
					}
				}
				else
				{
					if(i <= full.length()/2)
					{
						split1+=full.charAt(i);
					}
					else
					{
						split2+=full.charAt(i);
					}
				}
				
			}
			full = "";
			for(int i = 0; i < split1.length(); i++)
			{
				if(i < split2.length())
				{
					full+=split1.charAt(i);
					full+=split2.charAt(i);
				}
				else
				{
					full+=split1.charAt(i);
				}
			}
		}
		return full;
	}

	@Override
	public String decode(String ciperText) 
	{
		String split1 = "";
		String split2 = "";
		String full = ciperText;
		
		for(int j = 0; j < _n; j++)
		{
			split1 = "";
			split2 = "";
			
			for(int i = 0; i < full.length(); i++)
			{
				if(i%2 == 0)
				{
					split1+=full.charAt(i);
				}
				else
				{
					split2+=full.charAt(i);
				}
			}
			full = split1+split2;
		}
		return full;
	}

	@Override
	public String cipherText() 
	{
		return "ShuffleCipher";
	}

}
