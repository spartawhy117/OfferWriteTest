#include <iostream>
#include <string>
#include <vector>
using namespace std;
int T;
int N, V;
//范化背包问题
//f[i][v]=max{f[i-1][v-k*c[i]]+k*w[i]|0<=k<=n[i]}
void Resolve(vector<string>& names, vector<int>& enhancedTime, vector< vector<int> > & fightAndMoney)
{
	
}

int main(int argc, char* argv[])
{
	cin >> T;
	while (T--)
	{

		cin >> N >> V;
		vector<string> names;
		vector<int> enhancedTimes;
		vector< vector<int> > fightAndMoney;
		for (int i = 0; i < N; i++)
		{
			string name;
			int v;
			cin >> name;
			names.push_back(name);
			cin >> v;
			enhancedTimes.push_back(v);
			int other = v * 2;
			
			for(int j=0;j<other;j++)
			{
				cin >> v;
				fightAndMoney[i].push_back(v);
			}
			
		}

		Resolve(names, enhancedTimes, fightAndMoney);
	}

}