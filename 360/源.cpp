#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
bool IsEvenStr(const string&str)
{
	int array[26] = { 0 };

	int size = str.size();
	for (int i = 0; i < size; ++i)
	{
		array[str[i] - 'a']++;
	}

	bool result = true;
	for(int i=0;i<26;++i)
	{
		if(!(array[i]%2==0))
		{
			return false;
		}
	}

	return result;
}
int Permuatation(string& str)
{
	int count = 0;
	int size = str.size();
	if(size<2)
	{
		return count;
	}

	for(int i=2;i<=size;++i)
	{
		for(int j=0;j<size&&j+i<=size;++j)
		{
			string tmp = str.substr(j, i);
			if(IsEvenStr(tmp))
			{
				count++;
			}
		}
	}
	return  count;
}

int main(int argc, char* argv[])
{

	unsigned int N;
	unsigned int M;
	unsigned int T1;
	unsigned int Q1;



	while (cin >> N>>M)
	{
		vector<unsigned int> T;
		vector<unsigned int> Q;
		vector<unsigned int> Empty;
		for(unsigned int i=0;i<N;++i)
		{
			
			cin >> T1;
			T.push_back(T1);
			if (i != T1)
			{
				Empty.push_back(i);
			}
			
		}
		for (unsigned int i = 0; i<M; ++i)
		{
			cin >> Q1;
			Q.push_back(Q1);
		}
		for (unsigned int i = 0; i<M; ++i)
		{
			for(unsigned int j=0;j<Empty.size();++j)
			{
				if(Q[i]<Empty[j])
				{
					cout << Empty[j]<<endl;
				}
				else
				{
					cout << T[T.size() - 1]++;
				}
			}
		}
	}

	
	
}
