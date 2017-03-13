#include <iostream>
#include <string>
#include <vector>

using namespace std;
int T;

string m_beAdded;
string m_add;
string m_result;
int StringToInt(const string & s)
{
	int r = atoi(s.c_str());
	return r;
}
int BlankNumber(const string &s,int num,vector<int>& index)
{
	int count = 0;
	for(int i=0;i<num;i++)
	{
		if (s[i] == 'X')
		{
			count++;
			index.push_back(i);
		}
	}
	return count;
}

int Resolve(string beadd,string add ,string r)
{
	if (beadd == "" || add == "" || r == "")
		return 0;

	int result = StringToInt(r);
	int beaddedNum = beadd.size();
	int addNum = add.size();
	//todo handle permutation
	vector<int> index1;
	vector<int> index2;
	int beadd_blanks = BlankNumber(beadd, beaddedNum,index1);
	int add_blanks = BlankNumber(add, addNum,index2);

	vector<int> p1;
	if(beadd_blanks==1)
	{
		for(int j=1;j<=9;j++)
		{
			beadd[index1[0]] = j+'0';
			int v = StringToInt(beadd);
			p1.push_back(StringToInt(beadd));
		}
	}
	if(beadd_blanks==2)
	{
		for (int j = 1; j <= 9; j++)
		{
			beadd[index1[0]] = j + '0';
			for(int m=1;m<=9;m++)
			{
				beadd[index1[1]] = m + '0';
				p1.push_back(StringToInt(beadd));
			}
		}
	}
	if (beadd_blanks == 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			beadd[index1[0]] = j + '0';
			for (int m = 1; m <= 9; m++)
			{
				beadd[index1[1]] = m + '0';
				for(int n=1;n<=9;n++)
				{
					beadd[index1[2]] = n + '0';
					p1.push_back(StringToInt(beadd));
				}
			}
		}
	}
	
	vector<int> p2;
	if (add_blanks == 1)
	{
		for (int j = 1; j <= 9; j++)
		{
			add[index2[0]] = j + '0';
			p2.push_back(StringToInt(add));
		}
	}
	if (add_blanks == 2)
	{
		for (int j = 1; j <= 9; j++)
		{
			add[index2[0]] = j + '0';
			for (int m = 1; m <= 9; m++)
			{
				add[index2[1]] = m + '0';
				p2.push_back(StringToInt(add));
			}
		}
	}
	if (add_blanks == 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			add[index2[0]] = j + '0';
			for (int m = 1; m <= 9; m++)
			{
				add[index2[1]] = m + '0';
				for (int n = 1; n <= 9; n++)
				{
					add[index2[2]] = n + '0';
					p2.push_back(StringToInt(add));
				}
			}
		}
	}
	int count=0;
	for(int i=0;i<p1.size();i++)
	{
		for(int j=0;j<p2.size();j++)
		{
			if(p1[i]+p2[j]==result)
			{
				count++;
				break;
			}
		}
	}
	return count;
}


int main(int argc, char* argv[])
{
	cin >> T;
	while (T--)
	{
		
		cin >> m_beAdded >> m_add >> m_result;
		int r = Resolve(m_beAdded, m_add, m_result);
		cout << r << endl;

	}

}

