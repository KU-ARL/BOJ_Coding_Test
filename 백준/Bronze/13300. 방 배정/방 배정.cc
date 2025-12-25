#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int student[6][2]={};

	int N, max;
	int sex, grade;
	cin >> N >> max;
	for(int i=0;i<N;i++) {
		cin >> sex >> grade;
		student[grade-1][sex]++;
	}

	int cnt=0;
	for(int i=0;i<6;i++) {
		for(int j=0;j<2;j++) {
			cnt += (student[i][j]+max-1)/max;
		}
	}
	cout << cnt;
}