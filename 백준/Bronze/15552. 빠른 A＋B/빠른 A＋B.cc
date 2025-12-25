#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for(int i=0;i<N;i++) {
		int a, b;
		cin >> a >> b;
		cout << a+b << '\n';
	}
}