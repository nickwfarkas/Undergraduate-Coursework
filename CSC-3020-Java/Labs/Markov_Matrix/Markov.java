package org;

import java.util.Scanner;

public class Markov {

	public static void main(String[] args) 
	{
		double[][] matrix = new double[3][3];
		Scanner scanner = new Scanner(System.in);
	    double input;
		System.out.println("Enter a 3-by-3 matrix row by row: ");
		
		for(int i = 0; i < 3; i++)
	    {
	    	for(int j = 0; j < 3; j++)
	    	{
	    	    input = scanner.nextDouble();
	    		matrix[i][j] = input;
	    	}
	    }
		scanner.close();
		
		if(isMarkovMatrix(matrix))
		{
			System.out.print("It is a Markov matrix");
		}
		else
		{
			System.out.print("It is not a Markov matrix");
		}
	}
	
	public static boolean isMarkovMatrix(double[][] m)
	{
		double[] sum = new double[3];
		for(int i = 0; i < 3; i++)
	    {
	    	for(int j = 0; j < 3; j++)
	    	{
	    	    sum[i] += m[j][i];
	    	}
	    }
		for(int i = 0; i < 3; i++)
		{
			if(sum[i] != 1.0)
			{
				return false;
			}
		}
		
		return true;
	}

}
