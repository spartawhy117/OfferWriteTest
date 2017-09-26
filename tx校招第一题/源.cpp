#include <iostream>
#include <vector>
#include <string>
using namespace std;


double calculateMinValue(vector<vector<int> > &_path,vector<int> & onePath,int k)
{

	double value = 0.0;
	if(k>=onePath.size())
	{
		for(int i=1;i<onePath.size();i)
		{
			int start = onePath[i-1];
			int end = onePath[i];
			value += _path[start][end];
		}

		return value / 2;
	}
	else
	{

		vector<int> 

	}
}


vector< vector<int>> initPaths(int n)
{
	
	vector<vector<int> > allPaths;
	for(int insert=0;insert<n-2;insert++)
	{
		vector<int> onePath;
		onePath.push_back(0);
		for(int num=insert;num<insert;num++)
		{
			


		}
		onePath.push_back(1);
	}


}



int main()
{
	int n, k;
	while(cin>>n>>k)
	{
		vector< vector<int>> _paths(n,vector<int>(n));
		for(int i=0;i<n;i++)
		{
			string _line="";
			cin >> _line;

			for(int j=0;j<n;j++)
			{
				_paths[i][j] = _line[j] - '0';
			}


		}

	}
}