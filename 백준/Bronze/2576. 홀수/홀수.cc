#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	int min=200;
	int sum=0;

	for (int i=0; i<7; i++) {
		cin >> num;
		if (num%2 != 0) {
			sum += num;
			if(min > num) min = num;
		}
	}
	if (min == 200) cout << "-1";
	else {
		cout << sum << '\n';
		cout << min;
	}
}