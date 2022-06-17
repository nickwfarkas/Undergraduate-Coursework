package package1;

public class Circle extends Point
{
   	private double radius; // radius of the circle

   			//Default constructor
   	public Circle()
   	{
   		super(0.0, 0.0);
		this.radius = 0;
   	}

   		//Constructor with parameters
   	public Circle(double xValue, double yValue, double r )
   	{
   		super(xValue,yValue);
      	this.radius = r;
   	}


   		// convert Circle into String representation
   	public String toString()
   	{
      	return super.toString() + String.format(", %.2f", radius);
   	}


   	public double area()
   	{
       	return Math.PI * radius * radius;
   	}

   	public double circumference()
   	{
    	 return 2 * Math.PI * radius;
   	}
}  // end class Point


