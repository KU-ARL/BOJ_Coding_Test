#include <iostream>
using namespace std;

int arr[2000001]; 
int num[100001]; 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> num[i];
        arr[num[i]]++;
    }
    
    int target;
    cin >> target;
    
    int cnt = 0;
    for(int i=0; i<N; i++) {
        if (target - num[i] < 0 || target - num[i] > 2000000) continue;

        if(num[i]*2 != target && arr[target-num[i]]) cnt++;
    }
    cout << cnt/2;
}