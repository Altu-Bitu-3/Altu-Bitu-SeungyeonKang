#include <iostream>
#include <set>

using namespace std;


int main() {

	int n, m;
	int count;
	string input;

	set<string> str_N;

	set<string> ::iterator iter;

	cin >> n;
	cin >> m;

	while (n--) {
		cin >> input;
		str_N.insert(input);
	}

	while (m--) {
		cin >> input;
		iter = str_N.find(input);
		if (iter != str_N.end()) {
			count++;
		}
	}

	cout << count;

	return 0;
}