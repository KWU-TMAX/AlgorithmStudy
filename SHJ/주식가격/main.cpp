#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> answer;

vector<int> solution(vector<int> prices) {
    for(int i =0 ; i<prices.size(); i++) {
        int a = 0;
        for(int j = i+1 ; j<prices.size(); j++)
        {
            a++;
            if(prices[i] > prices[j]) {
                break;
            }
        }
        answer.push_back(a);
    }
    answer[answer.size()] = 0;
    return answer;
}