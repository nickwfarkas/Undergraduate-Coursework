package lab04;

class Course 
{  
	private String courseName;  
	private String[] students = new String[3];  
	private int numberOfStudents;  
	public Course(String courseName) 
	{    
		this.courseName = courseName;  
	}  
	
	public String getCourseName() 
	{    
		return courseName;  
	}  
	
	public int getNumberOfStudents() 
	{    
		return numberOfStudents;  
	}    
	//Revise the getStudents method to return an array whose length is the same   
	//as the number of students in the course.   
	public String[] getStudents() 
	{
		String[] temp = new String[numberOfStudents];
		System.arraycopy(students, 0, temp, 0, numberOfStudents);
		return temp;  
	}  
	//Revise the addStudent method to automatically increase the array size   
	public void addStudent(String student) 
	{
		if(numberOfStudents == students.length)
		{
			String[] temp = new String[numberOfStudents];
			System.arraycopy(students, 0, temp, 0, numberOfStudents);
			students = new String[numberOfStudents*2];
			System.arraycopy(temp, 0, students, 0, numberOfStudents);
		}
		students[numberOfStudents] = student;    
		numberOfStudents++;
		
		
	}  
	//Implement the dropStudent method.  
	public void dropStudent(String student) 
	{  
		int pos = -1;
		for(int i = 0; i < students.length; i++)
		{
			if(students[i] == student)
			{
				pos = i;
			}
		}
		
		for(int j = pos; j < students.length-1; j++)
		{
			students[j] = students[j+1];
		}
		numberOfStudents--;
	}
}
