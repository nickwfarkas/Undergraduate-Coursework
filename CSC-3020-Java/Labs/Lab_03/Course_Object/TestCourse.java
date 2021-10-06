package lab04;

public class TestCourse {

	public static void main(String[] args) 
	{
		Course course = new Course("Course1");
		course.addStudent("Peter Jones");
		course.addStudent("Brian Smith");
		course.addStudent("Anne Kennedy");
		course.addStudent("Susan Kennedy");
		course.addStudent("John Kennedy");
		
		
		System.out.println("Number of students in "+
				course.getCourseName()+": "+course.getNumberOfStudents());
		
		for(int i = 0; i < course.getNumberOfStudents(); i++)
		{
			if(i == course.getNumberOfStudents()-1)
			{
				System.out.print(course.getStudents()[i]+"\n");
			}
			else
			{
				System.out.print(course.getStudents()[i]+", ");
			}
		}
		
		course.dropStudent("Susan Kennedy");
		
		String[] tempStudents = new String[course.getNumberOfStudents()];
		System.out.println("Number of students in "+
				course.getCourseName()+": "+course.getNumberOfStudents());
		
		System.arraycopy(course.getStudents(), 0, tempStudents, 0, course.getNumberOfStudents());
		
		for(int i = 0; i < tempStudents.length; i++)
		{
			if(i == tempStudents.length-1)
			{
				System.out.print(tempStudents[i]+"\n");
			}
			else
			{
				System.out.print(tempStudents[i]+", ");
			}
		}
	}

}
