#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	set<string> company;

	int n;
	string name;
	string cmd;

	cin >> n;

	//set<string> ::iterator iter;

	while (n--) {

		cin >> name;
		cin >> cmd;

		if (cmd == "enter") {
			company.insert(name);
		}
		if (cmd == "leave") {
			company.erase(name);
		}
	}

	for (auto iter = company.rbegin(); iter != company.rend(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}