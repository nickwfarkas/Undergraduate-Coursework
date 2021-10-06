package package1;

import java.util.*;

public class Question11 
{

	public static void main(String[] args) 
	{
		ArrayList<Integer> united = new ArrayList<Integer>();

		ArrayList<Integer> list1 = new ArrayList<Integer>();

		ArrayList<Integer> list2 = new ArrayList<Integer>();
		
		Scanner scanner = new Scanner(System.in);
		
		list1 = getUserList(scanner,1);
		
		list2 = getUserList(scanner,2);
		
		united = union(list1,list2);
		
		printList(united);
	}
	
	public static ArrayList<Integer> union(ArrayList<Integer> list1, ArrayList<Integer> list2)
	{
		ArrayList<Integer> united = new ArrayList<Integer>();
		
		addToUnion(list1,united);
		
		addToUnion(list2,united);
		
		return united;
	}
	
	public static void addToUnion(ArrayList<Integer> original, ArrayList<Integer> newList)
	{
		for(int i = 0; i < original.size(); i++)
		{
			newList.add(original.get(i));
		}
	}
	
	public static void printList(ArrayList<Integer> l)
	{
		System.out.print("The combined list is ");

		for(int i = 0; i < l.size(); i++)
		{
			System.out.print(l.get(i)+" ");
		}
	}
	
	public static ArrayList<Integer> getUserList(Scanner scanner, int num)
	{
		ArrayList<Integer> l = new ArrayList<Integer>();
		
		System.out.print("Enter five integers for list"+num+": ");
		for(int i = 0; i < 5; i++)
		{
			l.add(scanner.nextInt());
		}
		
		return l;
	}

}
