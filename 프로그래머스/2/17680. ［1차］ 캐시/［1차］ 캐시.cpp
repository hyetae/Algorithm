#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++)
            if (cities[i][j] < 'a')
                cities[i][j] += 32;
    }
    
    int cnt = 0;
    vector<string> cache;
    
    for (int i = 0; i < cacheSize; i++) {
        if (cache.empty()) {
            cnt += 5;
            cache.push_back(cities[i]);
            continue;
        }
        
        bool flag = false;
        for (int j = 0; j < cache.size(); j++) {
            if (cache[j] == cities[i]) {
                cnt++;
                cache.erase(cache.begin() + j);
                cache.push_back(cities[i]);
                flag = true;
                break;
            }
        }
        
        if (!flag) {
                cnt += 5;
                cache.push_back(cities[i]);
        }
    }

    for (int i = cacheSize; i < cities.size(); i++) {
        bool flag = false;
        for (int j = 0; j < cache.size(); j++) {
            if (cache[j] == cities[i]) {
                cnt++;
                cache.erase(cache.begin() + j);
                cache.push_back(cities[i]);
                flag = true;
                break;
            }
        }
        
        if (!flag) {
                cnt += 5;
                cache.push_back(cities[i]);
        }
        
        if (cache.size() > cacheSize)
            cache.erase(cache.begin());
    }
    
    return cnt;
}