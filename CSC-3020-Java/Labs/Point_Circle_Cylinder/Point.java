package package1;

public class Point
{      
	private double x, y; // coordinates of the Point            
	//Default constructor      
	public Point()      
	{            
		setPoint(0, 0);      
	}
	
	//Constructor with parameters      
	public Point(double xValue, double yValue )     
	{            
		setPoint(xValue, yValue );      
	}            
	// set x and y coordinates of Point      
	public void setPoint(double xValue, double yValue )      
	{            
		x = xValue;            
		y = yValue;      
	}            
	// convert point into String representation      
	public String toString()      
	{            
		return "[" + String.format("%.2f", x)+ ", " + String.format("%.2f", y) + "]";      
	}
}  // end class Point

