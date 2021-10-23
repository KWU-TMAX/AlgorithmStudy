#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> answer;

vector<int> solution(vector<int> prices) {
    for(int i =0 ; i<prices.size(); i++) {
        int a = 0;
        // 현재 가격을 끝까지 순회
        for(int j = i+1 ; j<prices.size(); j++)
        {
            a++;
            // 현재 가격보다 큰 값을 만나면 break;
            if(prices[i] > prices[j]) {
                break;
            }
        }
        answer.push_back(a);
    }
    // 마지막은 무조건 0
    answer[answer.size()] = 0;
    return answer;
}