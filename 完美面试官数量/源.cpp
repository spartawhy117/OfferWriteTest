#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	vector<int> inList;
	vector<int> outList;
	cin >> n;
	int c1,c2;
	c1 = c2 = n;
	while (c1--)
	{
		int temp;
		cin >> temp;
		inList.push_back(temp);
	}
	while (c2--)
	{
		int temp;
		cin >> temp;
		outList.push_back(temp);
	}
	
	set<int> notLeave;
	notLeave.insert(outList[0]);
	int max = 1;
	int current = 1;
	int setSize = 1;
	set<int>::iterator it;
	for(int i=1;i<n;++i)
	{

		int notMax, notMin;

		if(!notLeave.empty())
		{
			int comeTime = inList[i];
			notMax = *notLeave.rbegin();
			notMin = *notLeave.begin();

			if(comeTime<notMin)//任然有没有退出的
			{
				current = current + 1;
				if (current > max)
				{
					max = current;
				}
					
			}else if(comeTime>notMax)
			{
				notLeave.clear();
				current = 1;

			}
			else
			{
				it = notLeave.begin();
				while (it!=notLeave.end()&& comeTime>=*it)
				{
					it = notLeave.erase(it);
					current = current - 1;
				}
				current += 1;
			}
			notLeave.insert(outList[i]);
		}
	}

	std::cout << max << endl;
	system("pause");


}
