#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int arr[101] = {};
	int num[201] = {};
	int target;
	int temp;
	
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> temp;
		arr[i] = temp + 100;
		num[temp+100]++;
	}
	cin >> target;

	cout << num[target+100];

}