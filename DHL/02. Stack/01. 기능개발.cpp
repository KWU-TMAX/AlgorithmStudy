// 앞에 값을 가지고 비교하므로 queue를 사용
// max값과 비교해야되는데 이전 front와 비교하여 문제가 됨
// queue를 사용한다고 한아이디어에 집착하는 바람에 문제의 본질을 놓쳤었다.


#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int i=0;
   
    queue<int> order;
    

    for(int i=0; i<progresses.size();i++)
    {
        int count =0;
        while(true){
            progresses.at(i) += speeds.at(i);
            count++;
            if(progresses.at(i) >= 100){
                order.push(count);
                break;
            }
        }
    }
    // 작업마다 걸리는 날짜에 대한 정보를 가진 vector 
  
    int j = 0;
    int maxNum = order.front();
    // 초기의 max값은 첫번재 원소
    answer.push_back(1);
    // 첫번째는 무조건 1을 넣어준다.
    // 5 10 1 1 20 1
    while(order.size() != 1)
    {
        order.pop();
        int nextValue = order.front();
        if(maxNum < nextValue) {
            // 현재의 max값 보다 크다면 그작업이 끝나더라도 뒤에작업이 안끝난 것이다.
            answer.push_back(1);
            maxNum = nextValue;
            // max를 바꿔준다
            j++;
        }else 
        {
            answer.at(j)++;
            // 먼저작업이 더 커서 뒤의 작업이 따라오는 경우 ++ 해준다.
        }
    }
    
    return answer;
}
