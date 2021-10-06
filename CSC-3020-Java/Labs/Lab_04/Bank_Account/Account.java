package package1;

public class Account 
{
	private int id;
	private double balance;

	public Account() {
	}

	public Account(int newId, double newBalance) {
		id = newId;
		balance = newBalance;
	}

	public int getId() {
		return this.id;
	}

	public double getBalance() {
		return balance;
	}

	public void setId(int newId) {
		id = newId;
	}

	public void setBalance(double newBalance) {
		balance = newBalance;
	}

	public void withdraw(double amount) {
		balance -= amount;
	}

	public void deposit(double amount) {
		balance += amount;
	}

	@Override
	public String toString() {
		return "Account id: "+ id +"\nAccount balance: "+ balance;
	}
}
