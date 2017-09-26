#include <iostream>
#include <vector>
using namespace std;
int Slove(int N,vector<int> & rows,vector<int> & cols)
{
	int index1 = 0;
	int index2;
	int result = 0;
	for(;index1<N-1;++index1)
	{
		for(index2=index1+1;index2<N;++index2)
		{
			int rowDiff = rows[index1] - rows[index2];
			if(rowDiff==0)
			{
				result++;
				continue;
			}
			int colDiff = cols[index1] - cols[index2];
			if(colDiff==0)
			{
				result++;
				continue;
			}
			if(rowDiff==colDiff||-rowDiff==colDiff)
			{
				result++;
			}
		}
	}

	return  result;

}


int main(int argc, char* argv[])
{
	int N;
	while (cin>>N)
	{
		int row, col;
		vector<int> rows;
		vector<int> cols;
		for(int i=0;i<N;++i)
		{
			cin >> row >> col;
			rows.push_back(row);
			cols.push_back(col);
		}

		cout << Slove(N,rows,cols)<<endl;
	}
}
