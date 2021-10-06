package package1;

public class TestAccount 
{
	public static void main(String[] args) 
	{
		Saving save = new Saving(1,15,.05);
		Checking check = new Checking(2,35,25);
		System.out.print("Checking Account: ");
		System.out.println(check.toString());
		System.out.println();
		
		System.out.print("Saving Account: ");
		System.out.println(save.toString());
		System.out.println();
		
		System.out.print("Checking Account after withdrawing $10: ");
		check.withdraw(10);
		System.out.println(check.toString());
		System.out.println();
		
		System.out.print("Saving Account after withdrawing $10: ");
		save.withdraw(10);
		System.out.println(save.toString());
		System.out.println();
	}

}
