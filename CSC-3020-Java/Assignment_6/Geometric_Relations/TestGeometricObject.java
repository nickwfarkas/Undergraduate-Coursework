package package1;

public class TestGeometricObject {
  /** Main method */
  public static void main(String[] args) 
  {
    GeometricObject[] geometricObjects =
    	{
    			new Square(2),
    			new Square(3),
    			new Square(4),
    			new Circle(5),
    			new Rectangle(6,7)
    	};
    
    ComparableSquare sq1 = new ComparableSquare(8);
    ComparableSquare sq2 = new ComparableSquare(8);
    ComparableSquare sq3 = new ComparableSquare(9);
    
    for(int i = 0; i < geometricObjects.length; i++)
    {
    	System.out.println("Area: "+geometricObjects[i].getArea());
    	if(geometricObjects[i] instanceof Square)
    	{
    		((Square) geometricObjects[i]).howToColor();
    	}
    	System.out.println();
    }
    
    compare(sq1, sq2);
    compare(sq2, sq3);
    compare(sq3, sq1);
    
  }
  
  public static void compare(ComparableSquare sq1,ComparableSquare sq2)
  {
	  switch(sq1.compareTo(sq2))
	  {
	  case 0:
		  System.out.println(sq1.getArea()+" is equal to "+sq2.getArea());
		  break;
	  case 1:
		  System.out.println(sq1.getArea()+" is greater than "+sq2.getArea());
		  break;
	  case 2:
		  System.out.println(sq1.getArea()+" is less than "+sq2.getArea());
		  break; 
	  } 
	  
	  System.out.println();
  }
  
}
