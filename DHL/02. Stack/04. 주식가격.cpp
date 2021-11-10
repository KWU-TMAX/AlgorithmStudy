#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    // 들어온 가격만큼 일단 0으로 만들어둠
    for(int i=0; i<prices.size(); i++){
        answer.push_back(0);
    }
   
    for(int i=0; i<prices.size(); i++) { 
        for(int j=i+1; j<prices.size(); j++) { 
            // 자기 자신보다 크면 변동된것이 아니니까 변동되지않았어 따라서 + 1
            answer[i]++; 
            // 자기 자신보다 작아진게 나왔어 떨어졌어 break; 다음꺼보기
            if(prices[i] > prices[j]) break; 
        } 
    } return answer; 
}
