#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int max = 0;
	int idx = 0;
	int arr[9]; 

	for ( int i = 0 ; i < 9 ; i++) {
		cin >> arr[i];
	}

	for (int i=0 ; i<9 ; i++) {
		if(arr[i]>max) { 
			max = arr[i];
			idx = i+1;
		}	
	}
	cout << max << '\n' << idx;
}