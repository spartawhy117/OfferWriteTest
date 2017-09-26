#include <iostream>
#include <math.h>
using namespace std;
int Calculate(unsigned int N,unsigned int Q)
{
	int result = 0;
	int currentMachine = 1;


	double notCopyTime =static_cast<double>( N )/ currentMachine;
	double copyOnceTime = Q + static_cast<double>(N )/ (currentMachine*2);

	while (notCopyTime>copyOnceTime)
	{
		result = result + Q;
		currentMachine = currentMachine * 2;

		notCopyTime = static_cast<double>(N) / currentMachine;
		copyOnceTime = Q + static_cast<double>(N) / (currentMachine * 2);
	}

	if(notCopyTime<=copyOnceTime)
	{
		result = result + ceil(static_cast<double>(N)/ currentMachine);
	}
	return result;
}

int main(int argc, char* argv[])
{
	unsigned int N, Q;
	while (cin>>N>>Q)
	{
		   int result = 0;
		    if (N <= Q)
			{
				result = N;
				cout << result<<endl;
			}
			else
			{
				result = Calculate(N, Q);
				cout << result << endl;
			}
	}


}
