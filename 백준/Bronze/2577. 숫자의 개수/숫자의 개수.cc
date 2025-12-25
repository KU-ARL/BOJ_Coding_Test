#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;
	int arr[10] = {};
	int dec = 10;
	arr[mul%dec]++;
	while(mul>=dec) {
		arr[(mul/dec)%10]++;
		dec *= 10;
	}

	for(int i=0;i<10;i++) cout << arr[i] << '\n'; 
}