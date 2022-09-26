#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<bool> check;

const int SIZE = 26;

bool checker(string word) { //그룹 단어인지 아닌지 체크하는 함수
	char checkBefore = -1; //이전 문자를 저장하는 변수
	check = vector<bool>(SIZE, false);


	for (int i = 0; i < word.length(); i++) {
		if (checkBefore != word[i]) { //이전 문자와 현재 문자가 다른데
			if (check[(int)word[i] - 97] == false) { //이전에 현재 문자가 나오지 않았다면
				check[(int)word[i] - 97] = true; //현재 문자가 나왔다는 사실을 저장
			}
			else {
				return false; //이전에 현재 문자가 나왔다면 false 반환
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