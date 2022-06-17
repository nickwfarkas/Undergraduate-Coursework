package norm;

public class Time 
{
	private int _hour,_minute,_second;
	
	Time()
	{
		_second = calculateSecond(System.currentTimeMillis());
		_minute = calculateMinute(System.currentTimeMillis());
		_hour = calculateHour(System.currentTimeMillis());
	}
	
	Time(long elapsedTime)
	{
		_second = calculateSecond(elapsedTime);
		_minute = calculateMinute(elapsedTime);
		_hour = calculateHour(elapsedTime);
	}
	
	Time(int hour, int minute, int second)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}
	
	int getSecond() {return _second;}
	int getMinute() {return _minute;}
	int getHour() {return _hour;}
	
	void setTime(long elapseTime)
	{
		_second = calculateSecond(elapseTime);
		_minute = calculateMinute(elapseTime);
		_hour = calculateHour(elapseTime);
	}
	
	
	int calculateSecond(long time)
	{
		return (int)((time/1000)%60);
	}
	
	int calculateMinute(long time)
	{
		return (int)(((time/1000)/60)%60);
	}
	
	int calculateHour(long time)
	{
		return (int)((((time/1000)/60)/60)%24);
	}
}
