/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<bits/stdc++.h>
#include <vector>
#include <utility>
using namespace std;

int N;

int max_core = 0;
int min_wire = 0;

int board[12][12];
vector<pair<int, int>> core;


bool canConnect(int x, int y, int dir, int num) {
    if (dir == 0) {
     	while(y!=0) {
            y -= 1;
         	if (board[x][y] != 0) return false;
        }
        return true;
    } else if (dir == 1) {
     	while(x!=N-1) {
            x += 1;
         	if (board[x][y] != 0) return false;
        }
        return true;
    } else if (dir == 2) {
     	while(y!=N-1) {
            y += 1;
         	if (board[x][y] != 0) return false;
        }
        return true;
    } else if (dir == 3) {
     	while(x!=0) {
            x -= 1;
         	if (board[x][y] != 0) return false;
        }
        return true;
    }
}

int connect(int x, int y, int dir, int num) {
    int len = 0;
    if (dir == 0) {
        int dy = y;
     	while(dy!=0) {
            dy -= 1;
         	board[x][dy] = num;
            len++;
        }
        return len;
    } else if (dir == 1) {
        int dx = x;
     	while(dx!=N-1) {
            dx += 1;
         	board[dx][y] = num;
            len++;
        }
        return len;
    } else if (dir == 2) {
        int dy = y;
     	while(dy!=N-1) {
            dy += 1;
         	board[x][dy] = num;
            len++;
        }
        return len;
    } else if (dir == 3) {
        int dx = x;
     	while(dx!=0) {
            dx -= 1;
         	board[dx][y] = num;
            len++;
        }
        return len;
    }
    
    return 0;
}

void dfs(int index, int coreCount, int wireLen) {
    if(coreCount + (core.size() - index) < max_core) return;
    if (index == core.size()) {
    	if (max_core == coreCount) {
        	min_wire = min(min_wire, wireLen);
        } else if (max_core < coreCount) {
         	max_core = coreCount;
            min_wire = wireLen;
        }
        return;
    }
    
    int x = core[index].first;
    int y = core[index].second;
    
    for (int dir=0; dir<4;dir++) {
		if(canConnect(x, y, dir, 2)) {
            int len = connect(x, y, dir, 2);
            dfs(index+1, coreCount+1, wireLen+len);
            connect(x, y, dir, 0);
        }
    }
    dfs(index+1, coreCount, wireLen);
    return;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
       	core.clear();
		max_core = 0;
		min_wire = 0;
        
        cin >> N;
        
		for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin >> board[i][j];
                if (i == 0 || i == N-1 || j == 0 || j == N-1) continue;
                if (board[i][j] == 1) core.push_back({i, j});
            }
        }
        
        dfs(0, 0, 0);
        
        cout << '#' << test_case << " " << min_wire << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}