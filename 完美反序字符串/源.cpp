#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char* argv[])
{
	string str;
	stack<int> stack;
	while (cin>>str)
	{
		stack.push(atoi(str.c_str()));
	}
	string rstr;
	for (int i = 0; i<stack.size() - 1; i++)
	{
		rstr += std::to_string(stack.top());
		rstr += " ";
		stack.pop();
	}

	rstr += std::to_string(stack.top());

	cout << rstr << endl;
}
