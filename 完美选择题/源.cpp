

#include<iostream>
using namespace std;

struct st
{
	unsigned int c : 2;
	unsigned int sd : 1;
};

int main(int argc, char** argv)
{
	
	cout << sizeof(st)<< endl;
	system("pause");
}


