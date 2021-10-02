#include <string>
#include <vector>
#include <queue>

using namespace std;
int cur_weight = 0;
int answer = 0;
queue<int> onBridge;
queue<int> rest;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    while(1) {
        int _size = rest.size();
        for(int i =0; i<_size; i++) {
            int restLength = rest.front();
            rest.pop();
            if(restLength <= 1) {
                cur_weight -= onBridge.front();
                onBridge.pop();
                continue;
            }
            rest.push(restLength - 1);                
        }
        
        if(truck_weights.size() > 0 && truck_weights.at(0) + cur_weight <= weight) {
            cur_weight += truck_weights.at(0);
            onBridge.push(truck_weights.at(0));
            rest.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if(cur_weight == 0 && truck_weights.size() == 0)
            break;
    }
    return answer;
}