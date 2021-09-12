#include <string>
#include <vector>
#include <queue>
using namespace std;

int calc_day(int per, int speed){
    int x = (100 - per) / speed;
    if( (100 - per) % speed){
        return x+1;
    }
    return x;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> day;
    int size = progresses.size();
    for(int i = 0; i < size; i++){
        day.push(calc_day(progresses[i], speeds[i]));
    }
    int count = 1;
    int distrib = day.front();
    day.pop();
    do{
        int ret = day.front();
        if(distrib >= ret)
            count ++;
        else{
            answer.push_back(count);
            distrib = ret;
            count = 1;
        }
        day.pop();
        if(day.empty()){
            answer.push_back(count);
        }
    }while(!day.empty());
    return answer;
}