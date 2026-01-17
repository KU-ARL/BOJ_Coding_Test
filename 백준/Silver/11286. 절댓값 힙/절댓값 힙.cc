#include <bits/stdc++.h>
using namespace std;


int pos[100000];
int neg[100000];
int pos_start = 0;
int pos_last = -1;
int neg_start = 0;
int neg_last = -1;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int input;
        cin >> input;

        if(input>0) {
            int temp = pos_start;
            while(pos[temp] != 0 && input >= pos[temp]) temp++;
            for(int i=pos_last;i>=temp;i--) {
                pos[i+1] = pos[i];
            }
            pos[temp]=input;
            pos_last++;
        } else if (input<0) {
            int temp = neg_start;
            while(neg[temp] != 0 && input <= neg[temp]) temp++;
            for(int i=neg_last;i>=temp;i--) {
                neg[i+1] = neg[i];
            }
            neg[temp]=input;
            neg_last++;
        } else {


            if (pos_start>pos_last && neg_start>neg_last) { // 둘 다 없어
                cout << 0 << '\n';
            } else if (neg_start<=neg_last) {
                if (pos_start<=pos_last) {  // 둘 다 존재
                    if (pos[pos_start] < neg[neg_start]*(-1)) {
                        // cout << "pos_start: "  << pos_start << '\n'; 
                        cout << pos[pos_start] << '\n';
                        pos_start++;
                    } else {
                        cout << neg[neg_start] << '\n';
                        // cout << "here??";

                        neg_start++;
                    }

                } else {  // neg만 존재
                    cout << neg[neg_start] << '\n';
                    neg_start++;
                }

                
            } else { 
                // if(pos_start<=pos_last) {
                    cout << pos[pos_start] << '\n'; 
                    pos_start++;
                    // cout << "here!";
                // } else cout << 0 << '\n';
            }


        }
    }

    // for(int i=pos_start;i<pos_last;i++) {
    //     cout << pos[i];
    // }
    // cout << '\n';
    // for(int i=neg_start;i<neg_last;i++) {
    //     cout << neg[i];
    // }

}