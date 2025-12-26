#include <iostream>
using namespace std;

int strfry(string a, string b) {
	int arr[26]={};
	for(auto c : a) arr[c-'a']++;
	for(auto c : b) arr[c-'a']--;
	for(int i=0; i<26; i++) {
		if(arr[i]!=0) return 0;
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string a, b;
	

	for(int i=0; i<N; i++) {
		cin >> a >> b;
		if(strfry(a, b)) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
	}
}