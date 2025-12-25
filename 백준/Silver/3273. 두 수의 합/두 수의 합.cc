#include <iostream>
using namespace std;

// [수정 1] 전역 변수로 선언하고 크기를 넉넉하게 200만으로 늘림
// (target이 최대 200만이고, 빼기 연산 결과도 인덱스로 써야 하므로)
int arr[2000001]; 
int num[100001]; // n은 최대 10만

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> num[i];
        arr[num[i]]++; // 이제 100만이 들어와도 터지지 않음
    }
    
    int target;
    cin >> target;
    
    int cnt = 0;
    for(int i=0; i<N; i++) {
        // [수정 2] 유효한 인덱스인지 먼저 검사
        // 1. target - num[i]가 0보다 커야 함 (음수 인덱스 방지)
        // 2. target - num[i]가 배열 크기보다 작아야 함 (오버플로우 방지)
        if (target - num[i] < 0 || target - num[i] > 2000000) continue;

        // 서로 다른 수여야 하므로 *2 != target 조건 유지
        if(num[i]*2 != target && arr[target-num[i]]) {
            cnt++;
        }
    }
    
    cout << cnt/2;
}