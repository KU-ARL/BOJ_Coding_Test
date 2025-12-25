#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int Y=0;
	int M=0;

	cin >> N;
	int arr[N];

	for (int i=0;i<N;i++) cin >> arr[i];

	for (int i=0;i<N;i++) {
		int a = arr[i];
		while(a >= 0) {
			Y += 10;
			a-=30;
		}
	}

	for (int i=0;i<N;i++) {
		int a = arr[i];
		while(a >= 0) {
			M += 15;
			a-=60;
		}
	}

	if(Y<M) cout << "Y " << Y;
	else if (Y>M)  cout << "M " << M;
	else cout << "Y M " << M;

}