package first;
import java.util.*;

public class Exam1 {

	public static void main(String[] args) 
	{
		int rows, columns, randInt;
		double rand;
		
		Scanner scanner = new Scanner(System.in);
	    System.out.println("Enter the number of rows: ");
	    rows = scanner.nextInt();
	    rows+=1;
	    
	    System.out.println("Enter the number of columns: ");
	    columns = scanner.nextInt();
	    columns+=1;
	    
	    scanner.close();
	    
	    int[][] matrix = new int[rows][columns];
	    
	    for(int i = 0; i < rows-1; i++)
	    {
	    	for(int j = 0; j < columns-1; j++)
	    	{
	    		rand = Math.random();
	    		
	    		if(rand <  .5)
	    		{
	    			randInt = 0;
	    		}
	    		else
	    		{
	    			randInt = 1;
	    		}
	    		
	    		matrix[i][j] = randInt;
	    	}
	    }
	    
	    for(int i = 0; i < matrix[0].length-2; i++)
	    {
	    	for(int j = 0; j < matrix[1].length-1; j++)
	    	{
	    		System.out.print(matrix[i][j]);
	    	}
	    	System.out.print("\n");
	    }
	    
	    sumColumns(matrix);
	}
	
	public static void sumColumns(int[][] matrix)
	{
		int sum = 0;
    	for(int i = 0; i < matrix[1].length-1; i+=2)
    	{
    		sum = 0;
    		if(i < matrix[1].length)
    		{
    			for(int j = 0; j < matrix[0].length-2; j++)
        		{
        			sum += matrix[j][i];
        		}
    		}
    		System.out.print(sum+" ");
    	}
	}
}	
	
	


