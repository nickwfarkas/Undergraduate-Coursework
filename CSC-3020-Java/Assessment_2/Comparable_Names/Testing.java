package exam;

public class Testing {
	
	public static void main(String[] args) 
	{
		ComparableName nameOne = new ComparableName("Nick");
		ComparableName nameTwo = new ComparableName("Nick");
		
		if(nameOne.compareTo(nameTwo) == 1)
		{
			System.out.println("Same");
		}
		else
		{
			System.out.println(nameOne.name);
			System.out.println(nameTwo.name);
		}
	}

}
