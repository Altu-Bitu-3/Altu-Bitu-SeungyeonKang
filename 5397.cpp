#include <iostream>
#include <list>
#include <string>
using namespace std;

list<char> output;
list<char> ::iterator iter;

void keyLogger(string input) {

	//초기화
	output.clear();
	iter = output.begin();

	//입력에 따른 결과
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '<') {
			if (!(iter == output.begin())) {
				iter--;
			}
		}
		else if (input[i] == '>') {
			if (!(iter == output.end())) {
				iter++;
			}
		}
		else if (input[i] == '-') {
			if (!(iter == output.begin())) {
				iter = output.erase(--iter);
			}
		}
		else {
			output.insert(iter, input[i]);
		}
	}

	for (iter = output.begin(); iter != output.end(); iter++) { //출력
		cout << *iter;
	}
	cout << '\n';
}

int main() {

	int n;
	cin >> n;

	while (n--) {
		string input;
		cin >> input;
		keyLogger(input);
	}

	return 0;
}