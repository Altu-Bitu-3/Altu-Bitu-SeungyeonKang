#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string a, b;

	cin >> a >> b;

	if (a.size() < b.size()) {
		swap(a, b);
	}

	int size = a.size() - b.size();

	vector<int> A, B, Goal;

	for (int i = 0; i < a.size(); i++) A.push_back(a[i] - '0');
	for (int i = 0; i < b.size(); i++) B.push_back(b[i] - '0');

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	while (size--) {
		B.push_back(0);
	}

	//cout << A.size() << B.size();

	int up = 0;
	for (int i = 0; i < a.size(); i++) {

		if (A[i] + B[i] + up >= 10) {
			Goal.push_back(A[i] + B[i] + up - 10);
			up = 1;
		}
		else {
			Goal.push_back(A[i] + B[i] + up);
			up = 0;
		}
	}

	if (up == 1) {
		Goal.push_back(1);
	}

	reverse(Goal.begin(), Goal.end());

	for (int i = 0; i < Goal.size(); i++) {
		cout << Goal[i];
	}

	return 0;
}