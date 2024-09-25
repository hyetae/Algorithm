#include <string>
#include <vector>
#include <map>

using namespace std;

struct Info {
    int time, acc;
    bool isDone;
};

vector<int> solution(vector<int> fees, vector<string> records) {
    map<int, Info> parking;
    for (auto record: records) {
        int car = stoi(record.substr(6, 4));
        int time = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
        switch(record[11]) {
            case 'I':
                parking[car].time = time;
                parking[car].isDone = false;
                break;
            case 'O':
                parking[car].acc += time - parking[car].time;
                parking[car].isDone = true;
                break;
        }
    }

    vector<int> answer;
    for (auto p: parking) {
        int car = p.first;
        if (!parking[car].isDone)
            parking[car].acc += 24 * 60 - 1 - parking[car].time;

        int fee = fees[1];
        parking[car].acc -= fees[0];
        if (parking[car].acc > 0) {
            fee += parking[car].acc / fees[2] * fees[3];
            if (parking[car].acc % fees[2])
                fee += fees[3];
        }

        answer.push_back(fee);
    }

    return answer;
}