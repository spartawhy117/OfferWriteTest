#include <string>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

unsigned int getResult(int*a ,int length)
{
	
	set<int> collector;
	for(int i=0;i<length;++i)
	{
		collector.insert(a[i]);
	}

	set<int>::iterator iter=collector.cbegin();
	while (*iter<0&&iter!=collector.cend())
	{
		iter++;
	}
	int index = 1;
	if(iter==collector.cend())
	{
		return 1;
	}
	else
	{
		while (iter!=collector.cend())
		{
			if (index != *iter)
				return index;
			else
			{
				index++;
				iter++;
			}
		}
		return index++;
		
	}
	
}

