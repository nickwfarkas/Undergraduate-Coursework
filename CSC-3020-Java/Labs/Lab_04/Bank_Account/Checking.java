package package1;

public class Checking extends Account 
{
	protected double fee;
	
	Checking(double fee)
	{
		this.fee = fee;
	}
	
	Checking(int newId, double newBalance, double fee) 
	{
		setId(newId);
		setBalance(newBalance);
		this.fee = fee;
	}
	
	@Override
	public String toString() 
	{
		return "\nMonthly Fee: "+String.format("%.2f",fee)+"\n"+super.toString();
	}
}
