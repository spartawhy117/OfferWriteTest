#include <iostream>
#include <string>
#include <set>
using namespace std;

int GetLargeOne(const set<int>& value,int v)
{
	set<int>::iterator it;
	it = value.find(v);
	it++;
	if (it != value.end())
	{
		return *it;
	}
	else
		return -1;
}
 
int GetMinAdd(const set<int>& value,int _time,int id)
{

	set<int>::iterator it;
	int last = _time % 10;
	int first = _time / 10;
	int result;
	it = value.cbegin();
	int min = *it;



	if(id==0)
	{
		int r = GetLargeOne(value, last);
		if (r != -1)
		{
			last = r;
		}
		else
		{
			r = GetLargeOne(value, first);
			if (r != -1)
			{
				first = r;
				last = min;
			}
			else
			{
				first = last = min;
			}
		}

		result = first * 10 + last;
		if(result>23)
		{
			
			result = min * 10 + min;
		}

		return result;

	}
	if(id==1)
	{
		int r = GetLargeOne(value, last);
		if (r != -1)
		{
			last = r;
		}
		else
		{
			r = GetLargeOne(value, first);
			if (r != -1)
			{
				first = r;
				last = min;
			}
			else
			{
				first = last = min;
			}
		}

		result = first * 10 + last;
		if (result>59)
		{
			result = min * 10 + min;
		}
		return result;
	}

}

string GetMinTime( string& time)
{
	set<int> value;
	set<int>::iterator it;

	value.insert(time[0] - '0');
	value.insert(time[1] - '0');
	value.insert(time[3] - '0');
	value.insert(time[4] - '0');
	value.insert(time[6] - '0');
	value.insert(time[7] - '0');
	

	int hour, min,sec;
	hour = (time[0] - '0') * 10 + (time[1] - '0');
	min = (time[3] - '0') * 10 + (time[4] - '0');
	sec = (time[6] - '0') * 10 + (time[7] - '0');


	int s=GetMinAdd(value, sec, 1);
	if(s>sec)
	{
		time[6] = '0' + s / 10;
		time[7] = '0' + s % 10;

		return time;
	}
	else
	{
		int m = GetMinAdd(value, min, 1);
		if(m>min)
		{
			time[6] = '0' + s / 10;
			time[7] = '0' + s % 10;

			time[3] = '0' + m / 10;
			time[4] = '0' + m % 10;


			return time;
		}
		else
		{
			int h = GetMinAdd(value, hour, 0);			
				time[6] = '0' + s / 10;
				time[7] = '0' + s % 10;

				time[3] = '0' + m / 10;
				time[4] = '0' + m % 10;

				time[0] = '0' + h / 10;
				time[1] = '0' + h % 10;

				return time;
		}
	}

}




int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	while (n--)
	{
		string time;
		cin >> time;

		cout << GetMinTime(time)<<endl;
	}
}

