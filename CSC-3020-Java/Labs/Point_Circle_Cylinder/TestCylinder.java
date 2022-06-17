package package1;

public class TestCylinder 
{

	public static void main(String[] args) 
	{
		Object c1 = new Cylinder(6,0,0,2);
		Point c2 = new Cylinder(9,5,5,3);
		Circle c3 = new Cylinder(12,10,10,4);
		
		System.out.println(c1.toString());
		
		System.out.println("Cylinder 1 Area: referenced by Object variable: "+((Cylinder) c1).area());
		
		System.out.println(c2.toString());
		
		System.out.println("Cylinder 1 Area: referenced by Point variable: "+((Cylinder) c2).area());
		
		System.out.println(c3.toString());
		
		System.out.println("Cylinder 1 Area: referenced by Circle variable: "+c3.area());
	}

}
