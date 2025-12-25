#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;

	int freq[10] ={};

	while(num>0) {
		freq[num%10]++;
		num /= 10;
	}

	int max = (freq[6]+freq[9]+1)/2;
	for(int i=0; i<10 ; i++) {
		if(i!=6 && i!=9) {
			if(freq[i]>max) max = freq[i];
		}
	}
	cout << max;
}