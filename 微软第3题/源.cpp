#include <iostream>
using namespace std;
int Slove(int* A,int* B,int N,int mean)
{
	int index = 0;
	int result = 0;
	bool changeWithOtherLine = true;
	while (index<N)
	{
		
		int currentColSum = A[index] + B[index];
		if(currentColSum==2*mean)
		{
			result += abs(A[index] - mean);
			changeWithOtherLine = false;
			index++;
		}
		else
		{
			
		}


		

	}

	return result;
}
int main(int argc, char* argv[])
{
	int N;
	while (cin>>N)
	{
		int* A = new int[N];
		int* B = new int[N];
		unsigned int total = 0;
		for(int i=0;i<N;++i)
		{
			cin >> A[i];
			total += A[i];
		}
		for (int i = 0; i<N; ++i)
		{
			cin >> B[i];
			total += B[i];
		}

		int mean = total / (2 * N);
		cout<<Slove(A, B, N,  mean)<<endl;

	}
}
