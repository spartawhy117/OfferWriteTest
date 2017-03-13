#include <iostream>
#include <string>
#include <vector>
using namespace std;

int NumberDigits(string &str)
{
	string one_Head = "0";
	string two_Head = "110";
	string three_Head = "1110";
	string four_Head = "11110";
	int digits = 0;
	if (str.substr(0, 1) == one_Head)
	{

		digits = 1;
		return digits;
	}

	if (str.substr(0, 3) == two_Head)
	{
		digits = 2;
		return digits;
	}

	if (str.substr(0, 4) == three_Head)
	{
		digits = 3;
		return digits;
	}

	if (str.substr(0, 5) == four_Head)
	{
		digits = 4;
		return digits;
	}
}
int HandleOne_Zero(const string&str,int n)
{
	int result = 0;

	auto lambda = [&](int i, int e)
	{
		if (str[i] == '1')
		{
			result += pow(2, e - i);
		}

	};
	if(n==2)
	{
		for(int i=15;i>=10;i--)
		{

			lambda(i,15);
			
		}

		return result;
	}

	if(n==3)
	{
		for (int i = 23; i >= 18; i--)
		{

			lambda(i, 23);
			
		}

		for (int i = 15; i >= 10; i--)
		{
			lambda(i, 21);
			
		}
		return result;
	}

	if(n==4)
	{
		for(int i=31;i >= 26;i--)
		{
			lambda(i, 31);
			
		}

		for (int i = 23; i >= 18; i--)
		{
			lambda(i, 29);
			
		}

		for (int i = 15; i >= 10; i--)
		{
			lambda(i, 27);
		}
		return result;
	}
}
int DecodeString(const string& str,int n)
{
	int result = 0;

	auto lambda = [&](int i,int e)
	{
		if(str[i]=='1')
		{
			result += pow(2,e-i);
		}
		
	};

	if(n==1)
	{

		for(int i=1;i<=7;++i)
		{

			lambda(i, 7);
			
		}
		return result;
	}
	if (n == 2)
	{
		for (int i = 3; i <= 7; ++i)
		{

			lambda(i, 13);
			
		}
		result = result + HandleOne_Zero(str, n);
		return result;
	}
	if (n == 3)
	{
		for (int i = 4; i <= 7; ++i)
		{

			lambda(i, 19);
			
		}
		result = result + HandleOne_Zero(str, n);
		return result;
	}
	if (n == 4)
	{
		for (int i = 5; i <= 7; ++i)
		{
			lambda(i, 25);
		}
		result = result + HandleOne_Zero(str, n);
		return result;
	}
}


void Resolve(string &str,vector<int>& r)
{
	int size = str.length();
	int digts = NumberDigits(str);

	
	string subString = str.substr(0, digts * 8);
	int decodeValue = DecodeString(subString, digts);
	r.push_back(decodeValue);

	int leftSize = size - digts * 8;
	string leftString;
	if(leftSize>0)
	{
		leftString = str.substr(digts * 8);
		digts = NumberDigits(leftString);
		subString = leftString.substr(0, digts * 8);
		decodeValue = DecodeString(subString, digts);
		r.push_back(decodeValue);

		leftSize = leftSize - digts * 8;
	}
	
	while (leftSize>0)
	{
		leftString = leftString.substr(digts * 8);
		digts = NumberDigits(leftString);
		subString = leftString.substr(0, digts * 8);
		decodeValue = DecodeString(subString, digts);
		r.push_back(decodeValue);

		leftSize = leftSize - digts * 8;
	}
}


int main(int argc, char* argv[])
{
	string code;
	cin >> code;
	vector<int> result;
	Resolve(code, result);

	for(int i=0;i<result.size();++i)
	{
		cout << result[i] << endl;
	}

	system("pause");
}

