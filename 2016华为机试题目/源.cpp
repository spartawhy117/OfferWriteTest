#include<iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
void PraseCommnd(char *str,int v1,int v2,map<int,int>& map,vector<int>&r)
{
	if(*str=='U')
	{
		map[v1] = v2;
	}
	if(*str=='Q')
	{
		int max=0;
		if (v1 == v2)
		{
			max = map[v1];
			r.push_back(max);
			
		}
		
		else
		{
			if (v1 > v2)
				swap(v1, v2);

			for (int i = v1; i <= v2; ++i)
			{
				max = map[i] > max ? map[i] : max;
			}
			r.push_back(max);
		}
		
	}
}


int main(int argc, char* argv[])
{
	int n, m;
	while (cin >> n >> m)
	{
		map<int, int> map;
		int v;
		for (int i = 1; i <= n; i++)
		{
			cin >> v;
			map[i] = v;
		}
		vector<int> result;

		while (m--)
		{
			char str;
			int v1, v2;
			cin >> str >> v1 >> v2;
			PraseCommnd(&str, v1, v2, map, result);
		}
		for (int i = 0; i<result.size(); ++i)
		{
			cout << result[i] << endl;
		}
	}
	
}
