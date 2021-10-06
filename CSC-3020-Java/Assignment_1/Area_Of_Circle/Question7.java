package package1;
import java.util.*;
import java.text.DecimalFormat;

public class Question7 
{

	public static void main(String[] args) 
	{
		double a,b,c;
		Scanner scanner= new Scanner(System.in);
		
		print("Enter the first side of the triangle: ");
		a = scanner.nextDouble();
		
		print("Enter the second side of the triangle: ");
		b = scanner.nextDouble();
		
		print("Enter the third side of the triangle: ");
		c = scanner.nextDouble();
		scanner.close();
		
		solveForArea(a,b,c);
		
		circleCalc();
		
	}
	
	public static void solveForArea(double a, double b, double c)
	{
		double s = (a+b+c)/2;
		print("Area: "+Math.sqrt(s*(s-a)*(s-b)*(s-c))+"\n");
	}
	
	public static void circleCalc()
	{
		Random rand = new Random(); 
		  
        int r = rand.nextInt(20)+1;
        int h = rand.nextInt(20)+1;

        DecimalFormat f = new DecimalFormat("##.00");
        
        print("Radius: "+r+"\n");
        print("Height: "+h+"\n");
        
        print("Volume: "+f.format(Math.PI*Math.pow(r, 2)*h)+"\n");
        print("Suface Area: "+f.format(2*Math.PI*r*h)+"\n");
	}
	
	public static void print(String p)
	{
		System.out.print(p);
	}

}
