package package1;

public class Saving extends Account 
{
	protected double interestRate;
	
	Saving(double interestRate)
	{
		this.interestRate = interestRate;
	}
	
	Saving(int newId, double newBalance, double interestRate) 
	{
		setId(newId);
		setBalance(newBalance);
		this.interestRate = interestRate;
	}
	
	@Override
	public String toString() 
	{
		return "\nInterest Rate: "+interestRate+"\n"+super.toString();
	}
}
