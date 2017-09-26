#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int Slove(vector<int>& A, vector<int>& B) {
	bool flag = true;
	int n = A.size();
	int i, j;
	while (flag) {
		flag = false;
		i = 0;
		while (i < n - 1) {
			if (B[i] == 1) {
				j = i + 1;
				while (j < n&&B[j] == 0)
					++j;
				if (j == n)
					break;
				if (B[j] == 1) {
					i = j;
					continue;
				}
				if (A[i] > A[j]) {
					B[j] = 0;
				}
				else {
					B[i] = 0;
					i = j;
				}
				flag = true;
			}
			else {
				++i;
			}
		}
	}
	j = 0;
	for (i = 0; i < n; ++i) {
		j += abs(B[i]);
	}
	return j;
}

int main() {
	int num;
	vector<int> A;
	vector<int> B;
	string str;
	getline(cin, str);
	istringstream iss(str);
	while (iss >> num) {
		A.push_back(num);
	}
	getline(cin, str);
	istringstream iss2(str);
	while (iss2 >> num) {
		B.push_back(num);
	}
	cout << Slove(A, B) << endl;

	return 0;
}
