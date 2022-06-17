package package1;

public class Cylinder extends Circle 
{
	private double height;
	
	Cylinder()
	{
		super(0,0,1);
		this.height = 1;
	}
	
	Cylinder(double height, double x, double y, double r)
	{
		super(x,y,r);
		this.height = height;
	}
	
	@Override
	public String toString()
   	{
      	return super.toString() + String.format(", %.2f", height);
   	}
	
	@Override
   	public double area()
   	{
       	return (height*super.circumference())+(2*super.area());
   	}
}
