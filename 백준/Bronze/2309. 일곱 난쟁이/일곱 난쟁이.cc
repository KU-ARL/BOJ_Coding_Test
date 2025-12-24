#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num[9];
	int sum = 0;
	for (int i=0;i<9;i++) {
		cin >> num[i];
	}

	sort(num, num+9);

	for( int i=0 ; i<9 ; i++) {
		for (int j=0;j<9;j++) {
			if (i != j) {
				for (int k=0; k<9; k++ ) {
					if (k != i && k !=j) {
						sum += num[k];
					}
				}

				if (sum == 100) {
					for (int l=0; l<9;l++) {
						if (l != i && l !=j) {
							cout << num[l] << '\n';
						}
					}
					return 0;
				}

				sum=0;
			}
		}
	}
}