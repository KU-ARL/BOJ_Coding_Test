#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;

	string a, b;
	cin >> a >> b;

	int arr[26] = {};

	for(auto c : a) arr[c-'a']++;
	for(auto c : b) arr[c-'a']--;

	for(int i : arr) if(i!=0) cnt += abs(i);

	cout << cnt;

}