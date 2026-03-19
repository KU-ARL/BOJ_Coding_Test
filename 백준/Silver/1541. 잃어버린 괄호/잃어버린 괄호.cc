#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    int sum=0;
    string num="";
    bool is_neg=false;

    for(int i=0; i<=input.size(); i++) {
        if(input[i]=='-'||input[i]=='+'||i==input.size()) {
            if(is_neg) sum -= stoi(num);
            else sum += stoi(num);

            num="";
            if(input[i]=='-') is_neg=true;
        } else {
            num+=input[i];
        }
    }

    cout << sum;
    return 0;
}