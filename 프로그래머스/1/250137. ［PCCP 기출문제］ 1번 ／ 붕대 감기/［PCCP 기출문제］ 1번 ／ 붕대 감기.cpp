#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int continuous = 0;
    int currentTime = 1;
    int maxHealth = health;
    
    for (vector<int> attack: attacks) {
        while (currentTime < attack[0]) {
            health += bandage[1];
            continuous++;
            if (continuous == bandage[0]) {
                health += bandage[2];
                continuous = 0;
            }
            health = health > maxHealth ? maxHealth : health;
            currentTime++;
        }

        currentTime++;
        continuous = 0;        
        health -= attack[1];
        
        if (health <= 0)
            return -1;
    }
    
    return health;
}