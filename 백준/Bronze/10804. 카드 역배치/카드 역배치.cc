#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num[21];
	for (int i=1 ; i<21 ; i++) {
		num[i] = i;
	}

	int a, b;
	for (int i=0 ; i<10 ; i++) {
		cin >> a >> b;
		int arr[21];
		for (int j=a ; j<b+1; j++) {
			arr[a+b-j] = num[j];
		}
		for (int k=a ; k<b+1; k++) {
			num[k] = arr[k];
		}
	}

	for (int i=1 ; i<21 ; i++) cout << num[i] << " ";

}