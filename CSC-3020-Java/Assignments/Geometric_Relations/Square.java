package package1;

public class Square extends GeometricObject implements Colorable 
{
	private double _side;
	
	Square(double side)
	{
		_side = side;
	}
	
	public void setSide(double side){_side = side;}
	
	public double getSide() {return _side;}
	
	@Override
	public void howToColor()
	{
		System.out.println("Color all four sides");
	}

	@Override
	public double getArea() 
	{
		return Math.pow(_side,2);
	}

	@Override
	public double getPerimeter() 
	{
		return _side*4;
	}
}
