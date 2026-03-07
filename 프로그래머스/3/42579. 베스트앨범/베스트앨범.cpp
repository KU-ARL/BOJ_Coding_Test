// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>

// using namespace std;

// vector<int> solution(vector<string> genres, vector<int> plays) {
//     vector<int> answer;
    
//     unordered_map<string, int> genre_total;
//     unordered_map<string, vector<pair<int, int>>> genre_songs;
    
//     for(int i=0; i<genres.size(); i++) {
//         if(genre_total.find(genres[i]) == genre_total.end()) {
//             genre_total[genres[i]] = plays[i];
//         } else {
//             genre_total[genres[i]] += plays[i];
//         }
//     }
    
//     vector<pair<string, int>> v(genre_total.begin(), genre_total.end());
//     sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
//         return a.second > b.second;
//     });
    
    
//     for(int i=0; i<genres.size(); i++) {
//             genre_songs[genres[i]].push_back({i, plays[i]});
//     }
    
//     for(int i=0; i<2; i++) {
//         string top = v[i].first;
//         vector<pair<int, int>> songs(genre_songs[top].begin(), genre_songs[top].end());
//         sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
//             return a.second > b.second;
//         });
            
//         for(int j=0; j<2; j++) {
//             answer.push_back(songs[j].first);
//         }
//     }
//     return answer;
// }

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genre_total;
    unordered_map<string, vector<pair<int, int>>> genre_songs;
    
    for(int i=0; i<genres.size(); i++) {
        genre_total[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> v(genre_total.begin(), genre_total.end());
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second; // 장르 총합 내림차순
    });
    
    // 수정 1: i < 2가 아니라 v.size()만큼 돌려야 모든 장르를 처리합니다.
    for(int i=0; i < v.size(); i++) {
        string top = v[i].first;
        vector<pair<int, int>> songs = genre_songs[top];
        
        // 수정 2: 정렬 조건에 '고유번호 오름차순' 추가
        sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) { // 재생 횟수가 같다면
                return a.first < b.first; // 고유 번호 낮은 순 (오름차순)
            }
            return a.second > b.second; // 기본은 재생수 높은 순 (내림차순)
        });
            
        // 수정 3: j < 2 조건과 함께 songs.size()를 반드시 체크해야 합니다.
        for(int j=0; j < songs.size() && j < 2; j++) {
            answer.push_back(songs[j].first);
        }
    }
    
    return answer;
}