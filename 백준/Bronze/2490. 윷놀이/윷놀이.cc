#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	int front = 0;
	int back = 0;

	for (int i=0 ; i<3 ; i++) {
		for (int j=0 ; j<4 ; j++) {
			cin >> num;
			if (num == 0) front += 1;
		}

		if (front == 1) cout << "A" << '\n';
		else if (front == 2) cout << "B" << '\n' ;
		else if (front == 3) cout << "C" << '\n' ;
		else if (front == 4) cout << "D" << '\n' ;
		else cout << "E" << '\n' ;
		
		front = 0;
		back = 0;
	}
}