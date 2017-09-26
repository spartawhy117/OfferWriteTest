#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int maxNum(int k) {

	if (k == 1)
		return 1;
	if (k == 2)
		return 2;
	if (k == 3)
		return 3;
	if (k == 4)
		return 3;

	int result = 1;
	int max = (-1 + sqrt(1 + 8 * k)) / 2;
	int index = 2;
	int remain=0;
	vector<int> arry;
	while (index<=max)
	{
		k -= index;
		arry.push_back(index);
		index++;
	}
	remain = k ;
	int size = arry.size();
	for(int i=0;i<k;++i)
	{
		arry[size - 1 - i] +=1;
	}
	for(int i=0;i<size;++i)
	{
		result = result*arry[i];
	}
	return result;
	
}
int main() {
	int res;
	int _k;
	cin >> _k;
	res = maxNum(_k);
	cout << res << endl;
	system("pause");
	return 0;
}