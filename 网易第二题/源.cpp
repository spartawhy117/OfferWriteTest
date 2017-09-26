#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct OneResult
{
	pair<string, string> pairs[8];
};
bool IsExist(OneResult & one,vector<OneResult> & results)
{

	if(results.empty())
	{
		return false;
	}
	int size = results.size();
	for(int i=0;i<size;++i)
	{
		OneResult compareOne = results[i];

		for(int j=0;j<8;++j)
		{
			int count=0;
			string X1 = one.pairs[j].first;
			string X2 = one.pairs[j].second;

			for(int k=0;k<8;++k)
			{
				string X3 = compareOne.pairs[k].first;
				string X4 = compareOne.pairs[k].second;

				if (X1 == X3&&X2 == X4)
					count++;
				if (X1 == X4&&X2 == X3)
					count++;
			}

			if (count == 8)
				return true;
		}
	}

	results.push_back(one);
	return false;
}
bool SuccessPair(pair<string,string> & pair1,pair<string,string> pair2)
{
	
	if(pair1.second==pair2.second)
	{
		return false;
	}
	if(pair1.first[1]==pair2.first[1])
	{
		return false;
	}
	if(pair1.first[0]==pair2.first[0])
	{
		return false;
	}
	
	return true;

}
void MakePair(vector<string>& teamName, map<string, string> & In, vector<OneResult> & results)
{
	int size = teamName.size();
	if (size == 16)
	{
		OneResult one;
		int count = 0;
		string team1, team2;
		string local1, local2;
		for (int i = 0; i < 14; i += 2)
		{
			team1 = teamName[i];
			team2 = teamName[i + 1];
			local1 = In[team1];
			local2 = In[team2];

			pair<string, string> pair1, pair2;
			pair1 = make_pair(team1, local1);
			pair2 = make_pair(team2, local2);

			if(SuccessPair(pair1,pair2))
			{
				one.pairs[count] = make_pair(team1, team2);
				count++;
			}
			else
			{
				return;
			}
		}
		if(count==8)
		{
			if(IsExist(one,results))
			{
				return;
			}
			
		}


	}

}

void Permutation(vector<string> teamNames,int start,int length, map<string, string> & In, vector<OneResult> & results)
{
	if(start==length-1)
	{
		MakePair(teamNames, In, results);
	}
	else
	{
		for(int i=start;i<=length-1;++i)
		{
			swap(teamNames[start], teamNames[i]);
			Permutation(teamNames, start + 1, length,In,results);
			swap(teamNames[start], teamNames[i]);
		}
	}
}
int Slove(map<string,string> & In,vector<string> & teamNames)
{
	vector<OneResult> results;
	Permutation(teamNames,0,16,In,results);
	return  results.size();
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;
	
	while (T--)
	{
		map<string, string> teams;
		vector<string> teamNames;
		string teamName;
		string localName;
		for (int i = 0; i < 16; ++i)
		{
			cin >> teamName >> localName;
			teamNames.push_back(teamName);
			teams.insert(make_pair(teamName, localName));
		}

		cout << Slove(teams,teamNames) << endl;
	}
	
}
