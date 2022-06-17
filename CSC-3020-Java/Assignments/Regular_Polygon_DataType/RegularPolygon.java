package norm;

public class RegularPolygon 
{
	private int _n = 3;
	private double _side = 1;
	private double _x = 0;
	private double _y = 0;
	
	RegularPolygon(){}
	
	RegularPolygon(int n, double side)
	{
		_n = n;
		_side = side;
	}
	
	RegularPolygon(int n, double side, double x, double y)
	{
		_n = n;
		_side = side;
		_x = x;
		_y = y;
	}
	
	int getN() {return _n;}
	double getSide() {return _side;}
	double getX() {return _x;}
	double getY() {return _y;}
	
	void setN(int n) {_n = n;}
	void setSide(double side) {_side = side;}
	void setX(double x) {_x = x;}
	void setY(double y) {_y = y;}
	
	double getPerimeter()
	{
		return _side*_n;
	}
	
	double getArea()
	{
		return(_n*Math.pow(_side, 2))/(4*Math.tan(Math.PI/_n));
	}
	
}
