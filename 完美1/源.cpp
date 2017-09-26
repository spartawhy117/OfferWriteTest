#include <iostream>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	set<int> result;
	while (cin >> n)
	{
		result.insert(n);
	}

	set<int>::iterator iter;
	iter = result.cbegin();
	iter++;
	for (; iter != result.cend(); iter++)
	{
		cout << *iter << " ";
	}


	system("pause");

}