#include <string>
#include <vector>
#include <queue>
using namespace std;

// priority_queue는 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저 나오는 것
priority_queue<int, vector<int>, greater<int>> cp;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool result = false;
    for(int i = 0; i<scoville.size(); i++) {
        // priority queue 에 넣는 과정
        cp.push(scoville[i]);
    }   
    
    while(cp.top() < K && cp.size() > 1) {
        int first, second;
        answer++;
        first = cp.top();
        cp.pop();
        second = cp.top();
        cp.pop();
        cp.push(first+ second *2);
    }
    if(cp.top() < K)
        return -1;
    return answer;
}