#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;

	if (a == b || b - a == 1) {
		cout << 0;
		return 0;
	}

	cout << abs(a-b) - 1 << '\n';

	for (long long i=min(a, b)+1;i<max(a, b);i++) {
		cout << i << " ";
	}
}