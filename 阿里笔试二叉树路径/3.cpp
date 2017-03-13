#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct BinTree {

	BinTree(int v):v(v),l(nullptr),r(nullptr)
	{
		
	}
	//Éî¿½±´
	BinTree(const BinTree* node)
		:v(node->v),l(nullptr),r(nullptr)
	{
			if (node->l != nullptr)
			{
				this->l = new BinTree(node->l);
			}	
			if (node->r != nullptr)
			{
				this->r =new BinTree(node->r);
			}
	}
	int v;     //value
	BinTree* l; // leftChild;
	BinTree* r; //rightChild;
} BT, *PBT;



char strBinTree[] =
"+1\n"
" -2\n"
"  -4\n"
"  -5\n"
"   -6\n"
"   -7\n"
" -3\n"
"  -13\n"
"  -8\n"
"   -9\n"
"   -10\n"
"    -11\n"
"    -12\n";

char* paternN = "\n";

void CreateCore(map<int, PBT>& blank_value,char* str)
{

	if(str==nullptr|| *str == '\0')
		return;
		
	int blank_nums=0;
	while (*str==' ')
	{
		blank_nums++;
		str++;
	}

	auto digitsChar = [&]()->int
	{
		int i = 1;
		for (;; i++)
		{
			if (!isdigit(str[i]))
			{
				break;
			}
		}
		int dititals = i - 1;
		char *num = new char[dititals + 1];
		for (i = 0; i <= dititals - 1; i++)
			num[i] = str[i + 1];

		num[dititals] = '\0';
		 i = atoi(num);
		 delete[] num;
		 num == nullptr;
		return i;
	};
	int value = digitsChar();

	PBT node = new BinTree(value);

	map<int, PBT>::iterator iter;
	
	iter=blank_value.lower_bound(blank_nums - 1);
	PBT parentNode = iter->second;

	if(parentNode->l==nullptr)
	{
		parentNode->l = node;
		
	}
	else if(parentNode->r == nullptr)
	{
		parentNode->r = node;
	}
	
	if(parentNode->l!=nullptr&&parentNode->r!=nullptr)
	{
		blank_value.erase(blank_nums - 1);
	}

	blank_value[blank_nums] = node;
	

	char* leftChar = nullptr;
	auto splitChar = [=](char **ch)
	{
		char*p;
		p = strtok_s(str, "\n", ch);

	};

	splitChar(&leftChar);

	CreateCore(blank_value, leftChar);
}

PBT CreateBinTree(char *str)
{
	PBT root = NULL;
	if (str == nullptr)
		return nullptr;
	
	
	map<int, PBT> blank_value;
	auto splitChar = [=](char **ch,char** patrten)
	{
		char*p;
		p = strtok_s(strBinTree, *patrten, ch);


	};
	auto digitsChar = [&]()->int
	{
		int i = 1;
		for(;;i++)
		{
			if (!isdigit(str[i]))
			{
				break;
			}
		}
		int dititals = i-1;
		char *num = new char[dititals + 1];
		for (i = 0; i <= dititals - 1; i++)
			num[i] = str[i+1];

		num[dititals] = '\0';

		i = atoi(num);
		delete[] num;
		num == nullptr;
		return i;
	};

	root = new BinTree(digitsChar());

	blank_value[0]= root;
	

	char* leftChar = nullptr;
	
	splitChar(&leftChar,&paternN);
	CreateCore(blank_value, leftChar);

	return root;
}
void PreorderPath(PBT root,vector< vector<int>>& results,vector<int> onePath)
{
	if (root == nullptr)
		return;
	if(root->l==nullptr&&root->r==nullptr)
	{
		onePath.push_back(root->v);
		
		results.push_back(onePath);

		return;

	}
	
		onePath.push_back(root->v);
	
		PreorderPath(root->l, results, onePath);
		PreorderPath(root->r, results, onePath);

}

bool IsBranch(BinTree* root, int nodeList[], int nodeListSize)
{
	bool bIsBranch = false;
	vector< vector<int> > results; 
	vector<int> onePath;

	PreorderPath(root, results, onePath);

	for(int i=0;i<results.size();i++)
	{
		int size = results[i].size();
		if(size!=nodeListSize)
			continue;
		else
		{
			vector<int>::iterator it;
			int j = 0;
			for(;j<nodeListSize;j++)
			{
				it = find(results[i].begin(), results[i].end(), nodeList[j]);
				if(it==results[i].end())
				{
					break;
				}
			}
			if (j == nodeListSize)
				return true;

		}
	}

	return bIsBranch;
}

int main(int argc, char* argv[])
{
	PBT root = NULL;
	int nodeListSize = 0;

	root = CreateBinTree(strBinTree);

	
	
	cin >> nodeListSize;
	int* NodeList = new int[nodeListSize];
	if (NodeList == NULL)
		return 0;

	for (int i = 0; i < nodeListSize; i++)
		cin >> NodeList[i];


	bool bIsBranch = IsBranch(root, NodeList, nodeListSize);
	if (bIsBranch)
		printf("true\n");
	else
		printf("false\n");

	if (NodeList)
		delete[]NodeList, NodeList = NULL;

	return 0;

	
}