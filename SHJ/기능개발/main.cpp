#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> task;
    
    for(int i=0; i<progresses.size(); i++) {
        // 정수끼리의 나눗셈은 올림처리가 되지 않기 때문에 double 형변환을 해줘야한다고 한다. (중요!!)
        int progress = ceil((double)(100-progresses[i]) / speeds[i]);
        task.push_back(progress);
    }
    
    int cur = task[0];
    int index = 1;
    for(int j=1; j<task.size(); j++) {
        if(task[j] > cur) {
            cur = task[j];
            answer.push_back(index);
            index = 1;
        } else {
            index++;
        }
    }
    answer.push_back(index);
    return answer;
}