#include <iostream>
#include <list>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		string s;
		cin >> s;

		list<char> L;
		auto cursor = L.begin();

		for(auto i: s) {
			if (i=='<') {
				if (cursor!=L.begin()) cursor--;
			} else if (i=='>') {
				if (cursor!=L.end()) cursor++;
			} else if (i=='-') {
				if (cursor!=L.begin()) {
					cursor--;
					cursor=L.erase(cursor);
				}
			} else {
				L.insert(cursor, i);
			}
		}

		for(auto l: L) cout << l;
		cout << '\n';
	}
}