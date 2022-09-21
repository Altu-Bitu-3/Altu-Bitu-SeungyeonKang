#include <iostream>

using namespace std;

int main() {

	int R, B;

	cin >> R >> B;

	int scale = R + B; //바닥의 넓이

	int L, W;

 //갈색 타일의 수가 (L-2)(W-2)이면 조건 만족
	for (int i = 1; i < scale; i++) {
		L = i;
		if (scale % L == 0) {
			W = scale / L;
			if ((L - 2) * (W - 2) == B) {
				break;
			}
		}
	}
	//크기 다를 시 Swap
	if (L < W) {
		swap(L, W);
	}


	cout << L << ' ' << W;

	return 0;
}