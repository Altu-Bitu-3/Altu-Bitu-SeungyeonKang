#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> arr;

void BubbleSort(int n) {

	for (int i = 0; i < n - 1; i++) {
		int isSwap = false;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j][1] > arr[j + 1][1]) {
				swap(arr[j], arr[j + 1]);
				isSwap = true;
			}
		}

		if (!isSwap) {
			break;
		}
	}

}

int main() {

	int n = 0;
	cin >> n;

	arr.assign(n, vector<int>(2, 0));

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0];
		cin >> arr[i][1];
	}

	BubbleSort(n);

	for (int i = 0; i < n; i++) {
		cout << arr[i][0] << " " << arr[i][1] << '\n';
	}

	return 0;

}