#include<iostream>
#include<string>
#include<stack>
using namespace std;


int postfixCalc(const char* input)
{

	stack<int> num;
	int result = 0,v1;
	for (int i = 0; input[i] != '\0'; ++i)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			num.push(input[i] - 'A'+10);
		}
		else if (input[i] >= '1' && input[i] <= '9')
		{
			num.push(input[i] - '0');
		
		}
		else
		{
			v1 = num.top();
			num.pop();
			result = num.top();
			num.pop();
			switch (input[i]) 
			{
				case '+':
					result += v1;
					break;
				case '-':
					result -= v1; 
					break;
				case '*':
					result *= v1; 
					break;
			}
			num.push(result);
		}
	}
	return num.top();
}
int main(int argc, char* argv[])
{
	string str;
	
	while (cin >> str)
	{
		cout << postfixCalc(str.c_str()) << endl;;
	}
	

}

	