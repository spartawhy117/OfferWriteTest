#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	vector<int> prm;
	prm.push_back(2);
	prm.push_back(3);
	prm.push_back(5);

	for(int i=2;i<=n;++i)
	{
		if(i%2==0)
			continue;
		else
		{
			int size = prm.size();
			bool isPrm = true;
			for(int j=0;j<size;++j)
			{
				if(i%prm[j]==0)
				{
					isPrm = false;
					break;
				}
			}

			if(isPrm)
			{
				prm.push_back(i);
			}
		}
	}
	int r = 0;
	int size = prm.size();
	for(int i=0;i<size;++i)
	{
		int left = n - prm[i];
		if (left < n / 2)
			break;
		else
		{
			for(int j=i;j<size;++j)
			{
				if(prm[j]==left)
				{
					r++;
					break;
				}
			}
		}

	}


	cout << r;

	system("pause");
}
