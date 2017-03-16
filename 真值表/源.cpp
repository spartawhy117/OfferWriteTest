#include <iostream>
#include <string>
#include "BoolVaraible.h"
using namespace std;

void Permutation(bool** table,int rows,int cols)
{
	int row = 0;
	int k = 0;
	for(;row<rows;row++)
	{
		for(int col=0;col<cols;col++)
		{
			table[row][col] = (k >>(cols-col-1))&1;
		}
		k += 1;
	}

}


bool ParseExpression(bool** truth,int row,char*v,int n ,const string&e)
{
	bool result = false;
	int size = e.size();
	BoolVaraible v1;
	BoolVaraible v2;
	int index = 0;
	string newStr;

	auto IsNotOperator = [&]()->BoolVaraible
	{
		   BoolVaraible newValue;
		    int notCount = 0;
			while (e[index]=='~')
			{
				notCount++;
				index++;
			}
			//is 2 power
			if((notCount&notCount-1)&&notCount>1)
			{
				for(int j=0;j<n;j++)
				{
					if(e[index]==v[j])
					{
						newValue.value=truth[row][j];
						break;						
					}
				}
				index++;
				return newValue;
			}
			else
			{
				
				for (int j = 0; j<n; j++)
				{
					if (e[index] == v[j])
					{
						newValue.value = !truth[row][j];
						break;
					}
				}
				index++;
				return newValue;
			}
	};

	auto GetBoolValue = [&]()->BoolVaraible
	{
		BoolVaraible newValue;
		for (int j = 0; j<n; j++)
		{
			if (e[index] == v[j])
			{
				newValue.value = truth[row][j];
				break;
		     }
		}
		index++;
		return newValue;
	};
	while (index<size)
	{
		if(e[index]=='~')
		{
		   v1 = IsNotOperator();
			
		}
		else if(e[index]=='*')
		{
			if(e[index+1]=='~')
			{
				index++;
				v2 = IsNotOperator();
			}
			else
			{
				index++;
				v2 = GetBoolValue();
			}
			
			v1 = v1*v2;
		}
		else if(e[index]=='+')
		{
			if (e[index + 1] == '~')
			{
				index++;
				v2 = IsNotOperator();
			}
			else
			{
				index++;
				v2 = GetBoolValue();
			}

			
			v1 = v1 + v2;
		}
		else if(e[index]=='%')
		{
			if (e[index + 1] == '~')
			{
				index++;
				v2 = IsNotOperator();
			}
			else
			{
				index++;
				v2 = GetBoolValue();
			}
			v1 = v1 % v2;
		}
		else if(e[index]=='>')
		{
			if (e[index + 1] == '~')
			{
				index++;
				v2 = IsNotOperator();
			}
			else
			{
				index++;
				v2 = GetBoolValue();
			}
			v1 = v1 > v2;
		}
		else if(e[index]=='^')
		{
			if (e[index + 1] == '~')
			{
				index++;
				v2 = IsNotOperator();
			}
			else
			{
				index++;
				v2 = GetBoolValue();
			}
			v1 = v1 ^ v2;
		}
		else
		{
			v1 = GetBoolValue();

		}
		
	}
	result = v1.value;
	return  result;
	
}
void Resolve(const int n,char*v,const string&e)
{
	
	int rows = pow(2, n);
	bool **truthPermutation = new bool*[rows];
	for(int i=0;i<rows;++i)
	{
		truthPermutation[i] = new bool[n]{true};
	}

	Permutation(truthPermutation,rows,n);

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (truthPermutation[i][j])
			{
				cout << "T" ;
			}
			else
			{
				cout << "F" ;
			}
		}
		cout << endl;
	}
	cout << endl;


	for(int i=0;i<rows;++i)
	{
		if (ParseExpression(truthPermutation,i,v,n,e))
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}

	for(int i=0;i<rows;i++)
	{
		delete[] truthPermutation[i];
	}
	delete[] truthPermutation;
	
}


int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	char *variables = new char[n+1];
	for(int i=0;i<n;++i)
	{
		cin >> variables[i];
	}
	variables[n] = '\0';
	string expression;
	cin >> expression;
	Resolve(n,variables,expression);
	delete[] variables;

	system("pause");
}
