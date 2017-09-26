#include <iostream>
using namespace std;

int Solve(unsigned long n,unsigned long k)
{
	if (k > n)
		return 0;
	if (k == n)
		return 1;
	int result = 1;
	unsigned left = n - k;
	if(k==1)
	{
		int lastValue = 1;
		int currentValue=0;
		while (left>=1)
		{
			if (lastValue == 1)
			{
				currentValue = 2;
			}
			else
				currentValue = 1;

			if (left >= currentValue)
				result++;

			left = left-currentValue;
		}
		
	}
	else //k>1
	{
		int lastValue = k;
		int currentValue = 0;
		while (left >= 1)
		{
			if (lastValue == k)
			{
				currentValue = 1;
			}
			else
				currentValue = k;

			if (left >= k)
				result++;

			left = left - currentValue;
		}
	}

	return result;
}
int main(int argc, char* argv[])
{
	unsigned long n;
	unsigned long k;
	int result = 0;
	while (cin >> n >> k)
	{
		cout << Solve(n, k) << endl;
	}
}
