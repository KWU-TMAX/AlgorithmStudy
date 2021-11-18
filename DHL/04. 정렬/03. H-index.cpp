#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 생각해볼것1 [0,0,0,0,0,0,0, 1000,0,0] 평균 1000/10 100;
// 생각해볼것2 [1,1,1,1,1,1,1] 평균 7/7 1;
// 생각해볼것3 [100,90,95,110,105,0,0,0,0,0] 평균 500/10 50;

int solution(vector<int> citations) {
    int answer = 0;
    int avg = 0;
    
    for(int i =0; i < citations.size(); i++)
    {
        avg+=citations[i];
    }
    avg= avg/citations.size(); 
    // 평균 값을 구한다. 
    // 모든 수는 평균값 보다 큰수가 많을 수가 없음 평균이니까 그럼 평균값이 올라감
    // 평균만큼 골고루 분포되어 있어서 인용횟수의 평균이 h인게 h만큼 있으면 개이득
    // 하지만 생각해볼것 1과 같은 상황이 있어서 평균 h를 -- 해간다.
    // 평균 h-1이 h-1 이상이면 그게 H-index가 됨 
    
    answer = avg;
    while(true){
        int count=0;
        for(int i = 0;i <citations.size(); i++)
        {
            if(citations[i] >= answer) count++;
        }
        if(count>=answer) return answer;
        answer--;
    }
}

int main()
{
    vector<int> a; 
    // 6,5,2,1,0
    a.push_back(6);
    a.push_back(5);
    a.push_back(2);
    a.push_back(1);
    a.push_back(0);
    
    std::cout << solution(a) ; //2
    return 0;
}
