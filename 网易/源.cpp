#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool Equal(double v1,double v2)
{
	
	if (abs(v1 - v2) < 0.00000001)
		return true;
	else
		return false;
	

}
int Solve(int w,int x,int y,int z)
{

	vector<double> result;
	int count = 0;
	for(int i=w;i<=x;++i)
	{
		for(int j=y;j<=z;++j)
		{
			double index = (double)i /(double)j;
			int size = result.size();
			if(size>0)
			{
				int k = 0;
				for (; k<size; ++k)
				{
					if (!Equal(index, result[k]))
					{
						continue;
					}
						
				}

				if(k==size)
				{
					result.push_back(index);
					count++;
				}
			}
			else
			{
				result.push_back(index);
				count++;
			}
			
			
		}
	}

	return count;
}
int main(int argc, char* argv[])
{
	
	int w, x, y, z;
	while (cin>>w>>x>>y>>z)
	{
		cout<<Solve(w, x, y, z)<<endl;
	}
	system("pause");
}
