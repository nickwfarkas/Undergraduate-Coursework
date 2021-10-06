package lab;

public class TestGeometricObject {
  /** Main method */
  public static void main(String[] args) 
  {
	  GeometricObject[] g =
		  {
				  new Circle(5),
				  new Circle(6),
				  new Rectangle(3,2),
				  new Rectangle(3,2)
		  };
	  
	  sumArea(g);
  }

  public static void sumArea(GeometricObject[] a)
  {
	  double circleArea = 0;
	  double rectangleArea = 0;
	  double rectangleDiagonal = 0;
	  
	  for(int i = 0; i < a.length; i++)
	  {
		  if(a[i] instanceof Circle)
		  {
			  circleArea += ((Circle)a[i]).getArea();
		  }
		  if(a[i] instanceof Rectangle)
		  {
			  rectangleArea += ((Rectangle)a[i]).getArea();
			  rectangleDiagonal += ((Rectangle)a[i]).calculateDiagonal();
		  }
	  }
	  
	  System.out.println("The total area for Circle is "+circleArea);
	  System.out.println("The total area for Rectangle is "+rectangleArea);
	  System.out.println("The total sum for Rectangle Diagonal is "+rectangleDiagonal);
  }
}
