#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<bool> check;

const int SIZE = 26;

bool checker(string word) { //�׷� �ܾ����� �ƴ��� üũ�ϴ� �Լ�
	char checkBefore = -1; //���� ���ڸ� �����ϴ� ����
	check = vector<bool>(SIZE, false);


	for (int i = 0; i < word.length(); i++) {
		if (checkBefore != word[i]) { //���� ���ڿ� ���� ���ڰ� �ٸ���
			if (check[(int)word[i] - 97] == false) { //������ ���� ���ڰ� ������ �ʾҴٸ�
				check[(int)word[i] - 97] = true; //���� ���ڰ� ���Դٴ� ����� ����
			}
			else {
				return false; //������ ���� ���ڰ� ���Դٸ� false ��ȯ
			}
		}

		checkBefore = word[i];
	}

	return true;
}

int main() {

	int n, cnt = 0;
	cin >> n;

	while (n--) {
		string word;
		cin >> word;
		if (checker(word) == true) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}