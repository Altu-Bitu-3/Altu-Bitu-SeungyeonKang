#include <iostream>
#include <map>

using namespace std;
map<int, int> s;

void add(int x) {
	s[x] = x;
}

void remove(int x) {
	s[x] = 0;
}

void check(int x) {
	if (s[x] == x) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
}

void toggle(int x) {
	if (s[x] == x) {
		s[x] = 0;
	}
	else {
		s[x] = x;
	}
}

void all() {
	for (int i = 1; i <= 20; i++) {
		s[i] = i;
	}
}

void empty() {
	for (int i = 1; i <= 20; i++) {
		s[i] = 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(null);
	cout.tie(null);

	int n, x;
	string cmd;

	cin >> n;

	while (n--) {
		cin >> cmd;


		if (cmd == "add") {
			cin >> x;
			add(x);
		}
		if (cmd == "remove") {
			cin >> x;
			remove(x);
		}
		if (cmd == "check") {
			cin >> x;
			check(x);
		}
		if (cmd == "toggle") {
			cin >> x;
			toggle(x);
		}
		if (cmd == "all") {
			all();
		}
		if (cmd == "empty") {
			empty();
		}
	}

	return 0;
}