#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct BinTree {
	int v;     //value
	BinTree* l; // leftChild;
	BinTree* r; //rightChild;
} BT, *PBT;

//Create binary tree
PBT CreateBinTree(char *str);

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
/*
1
/ \
/   \
2     3
/ \   / \
4  5  13  8
/ \    /  \
6  7  9   10
/ \
11  12
*/
PBT CreateBinTree(char *str)
{
	PBT root = NULL;
	if (str == nullptr)
		return nullptr;
	root->v = str[0];

	PBT left = nullptr;
	PBT right = nullptr;
	
	
	




	return root;
}
void PreorderPath(PBT root,vector< vector<int>> results,vector<int> onePath)
{
	if (root == nullptr)
		return;
	if(root->l==nullptr&&root->r==nullptr)
	{
		if(onePath.size()==0)
		{
			onePath.push_back(root->v);
		}
		
		results.push_back(onePath);
	}
	
		onePath.push_back(root->v);
	
		PreorderPath(root->l, results, onePath);
		PreorderPath(root->r, results, onePath);


}

bool IsBranch(BinTree* root, int nodeList[], int nodeListSize)
{
	bool bIsBranch = false;
	vector< vector<int>> results; 
	vector<int> onePath;

	PreorderPath(root, results, onePath);


	return bIsBranch;
}

int main(int argc, char* argv[])
{
	PBT root = NULL;
	int nodeListSize = 0;

	//input node list size
	cin >> nodeListSize;
	int* NodeList = new int[nodeListSize];
	if (NodeList == NULL)
		return 0;

	//input each node
	for (int i = 0; i < nodeListSize; i++)
		cin >> NodeList[i];
	root = CreateBinTree(strBinTree);
	bool bIsBranch = IsBranch(root, NodeList, nodeListSize);
	if (bIsBranch)
		printf("true");
	else
		printf("false");

	if (NodeList)
		delete[]NodeList, NodeList = NULL;
	return 0;
}