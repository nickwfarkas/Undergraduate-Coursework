package exam;

public class ComparableName extends Person implements Comparable<ComparableName> {

	public ComparableName(String name)
	{
		super(name);
	}
	
	@Override
	public int compareTo(ComparableName n)
	{
		if(this.name.equals(n.name))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}
