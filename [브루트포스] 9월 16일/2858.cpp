#include <iostream>

using namespace std;

int main() {

	int R, B;

	cin >> R >> B;

	int scale = R + B; //�ٴ��� ����

	int L, W;

 //���� Ÿ���� ���� (L-2)(W-2)�̸� ���� ����
	for (int i = 1; i < scale; i++) {
		L = i;
		if (scale % L == 0) {
			W = scale / L;
			if ((L - 2) * (W - 2) == B) {
				break;
			}
		}
	}
	//ũ�� �ٸ� �� Swap
	if (L < W) {
		swap(L, W);
	}


	cout << L << ' ' << W;

	return 0;
}