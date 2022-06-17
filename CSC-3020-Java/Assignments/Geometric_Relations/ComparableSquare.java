package package1;

public class ComparableSquare extends Square implements Comparable<Square> 
{

	ComparableSquare(double side) 
	{
		super(side);
	}

	@Override
	public int compareTo(Square o) 
	{
		if(this.getArea() > o.getArea())
		{
			return 1;
		}
		else if(this.getArea() < o.getArea())
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
}
