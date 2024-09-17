#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Music {
    int idx;
    int genre;
    int play;
};

bool cmp(Music a, Music b) {
    if (a.genre == b.genre) {
        if (a.play == b.play)
            return a.idx < b.idx;
        return a.play > b.play;
    }
    return a.genre > b.genre;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int size = genres.size();
    map<string, int> genre_cnt;
    for (int i = 0; i < size; i++)
        genre_cnt[genres[i]] += plays[i];
    
    vector<Music> musics;
    for (int i = 0; i < size; i++) 
        musics.push_back({i, genre_cnt[genres[i]], plays[i]});
    
    sort(musics.begin(), musics.end(), cmp);
    
    int pre = -1;
    int cnt = 0;
    vector<int> answer;
    for (auto m: musics) {
        if (m.genre == pre)
            cnt++;
        else {
            cnt = 1;
            pre = m.genre;
        }
        
        if (cnt > 2)
            continue;
        
        answer.push_back(m.idx);
    }
    return answer;
}