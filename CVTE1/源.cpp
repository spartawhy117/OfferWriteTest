#include <string>
#include <iostream>
#include <stack>
using namespace std;
int ConvertToTen(const string& number,int N)
{
	int sum=0;
	int tmp=0;
	int size = number.length();
	for(int i=0;i<size;++i)
	{
		if(number[i]<='9'&&number[i]>=0)
		{
			tmp = (number[i] - '0')*pow(N, size - i - 1);
		}
		else
		{
			tmp = (number[i] - 'a')*pow(N, size - i - 1);
		}
		sum += tmp;
	}
	return sum;
}

 string ConvertToM( int num,int M)
{
	 stack<int> m_stack;
	while (num>0)
	{
		m_stack.push(num%M);
		num = num / M;
	}

	int count =0;
	int top = 0;
	string result;
	while (!m_stack.empty())
	{
		top = m_stack.top();
		m_stack.pop();
		if(top<10)
		{
			result += top + '0';
		}
		else
		{
			result += top - 10 + 'a';
		}
		
	}

}

 bool Check(const string &number,int N,int M)
{
	 if (N < 2 || N>36 || M < 2 || M>36)
		 return false;
	 if (number == "")
		 return false;
	 if (number[0] == '-')
		 return false;
	 int size = number.length();
	
	 for(int i=0;i<size;++i)
	 {

		 if (number[i] <= '9'&&number[i] >= 0)
		 {
			 if (number[i] > (N - 1) + '0')
				 return false;
		 }
		 else
		 {
			 if (number[i] > (N - 11) + 'a')
				 return false;
		 }
	 }
	 return  true;
}
string radixConver(const string &number,const int N,const int M)
{
	if (Check(number, N, M))
	{
		int ten = ConvertToTen(number, N);
		return ConvertToM(ten, M);
	}
	else
		return "Error";
}

int main(int argc, char* argv[])
{
	string str;
	int n, m;
	while (cin>>str>>n>>m)
	{
		cout<<radixConver(str, n, m)<<endl;
	}
}
