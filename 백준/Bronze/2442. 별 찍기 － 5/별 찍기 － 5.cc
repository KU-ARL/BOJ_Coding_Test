#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for(int i=1 ; i<N+1 ; i++) {
		for(int j=N-i ; j>0 ; j--) cout << " ";
		for(int k=1 ; k<2*i ; k++) cout << "*";
		cout << '\n';
	}
}