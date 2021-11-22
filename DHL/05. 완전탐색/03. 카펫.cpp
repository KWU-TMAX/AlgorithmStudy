#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 갈색으로 노란색을 둘러싸야한다. 
// 노란색의 높이가 1보다 클때, 부터 시작한다. 
// yellow height가 1인경우 부터 늘리는데 만약 yellow%i == 0인 경우에만 비교가 가능하다. 


vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i <= yellow; i++)
    {
        if(yellow%i != 0) continue;
        // 나눈수가 != 0 이면 해당 case 계산안해도됨
        if(((i+2)*2+(yellow/i)*2) == brown) {
            // 노란색으로 배열한거 테두리만큼의 갯수가 갈색의 갯수와 같다면 
            if((i+2) >= (yellow/i+2)){
                answer.push_back(i+2);
                answer.push_back(yellow/i+2);
                return answer;
            } else {
                answer.push_back(yellow/i+2);
                answer.push_back(i+2);
                return answer;
            }
        }
    }
}

