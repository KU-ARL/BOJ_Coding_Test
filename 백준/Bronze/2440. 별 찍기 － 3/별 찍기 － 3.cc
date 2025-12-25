#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for(int i=1 ; i<N+1 ; i++) {
		for(int k=N-i+1 ; k>0 ; k--) cout << "*";
		cout << '\n';
	}
}