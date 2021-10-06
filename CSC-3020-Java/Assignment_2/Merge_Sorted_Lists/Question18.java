package package1;

import java.util.*;

public class Question18 
{

	public static void main(String[] args) 
	{
		String stringList1 = "";
		String stringList2 = "";
		
		Scanner scanner = new Scanner(System.in);
		
	    System.out.println("Enter the first string: ");
	    stringList1 = scanner.nextLine();
	    stringList1 = stringList1.substring(2);
	    
	    System.out.println("Enter the first string: ");
	    stringList2 = scanner.nextLine();
	    stringList1 = stringList1.substring(2);
	    
		int[] list1 = createArray(stringList1);
		
		int[] list2 = createArray(stringList2);
		
		printArray("list1 is ",list1);
		
		printArray("list2 is ",list2);
		
		int[] merged = merge(list1,list2);
		
		merged = sort(merged);
		
		printArray("The merged list is ",merged);
		
		scanner.close();
	}
	
	public static void printArray(String pre,int[] ar)
	{
		System.out.print(pre);
		for(int i = 0; i < ar.length; i++)
		{
			System.out.print(ar[i]+" ");
		}
	}
	
	
	void q()
	{
		int[] myList;
		myList = new int[10];
		// Sometime later you want to assign a new array to myList
		myList = new int[20];

	}
	
	
	public static int[] createArray(String input)
	{
		int ar[] = new int[input.length()];
		String sub;
		int j = 0;
		for(int i = 0; i < input.length(); i++)
		{
			sub = "";
			while(input.charAt(i) != ' ' && i <= 10)
			{
				sub +=input.charAt(i);
				i++;
			}
			
			ar[j] = Integer.valueOf(sub);
			j++;
		}
		
		return ar;
	}
	
	
	public static int[] merge(int[] list1, int[] list2)
	{
		int[] mergedList = new int[list1.length+list2.length];
		
		for(int i = 0; i < list1.length; i++)
		{
			mergedList[i] = list1[i];
		}
		
		for(int i = 0; i < list2.length; i++)
		{
			mergedList[list1.length + i] = list2[i];
		}
		
		return mergedList;
	}
	
	public static int[] sort(int merged[]) 
    { 
        for (int i = 0; i < merged.length; i++) 
        { 
            int m = i; 
            for (int j = i+1; j < merged.length; j++)
            {
                if (merged[j] < merged[m])
                {
                	m = j;
                }              
            }
            
            int temp = merged[m]; 
            merged[m] = merged[i]; 
            merged[i] = temp; 
        } 
        return merged;
    } 

}
