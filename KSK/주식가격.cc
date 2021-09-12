#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int length = prices.size();
    vector<int> answer(length, 0);
    answer[length-1] = 0;
    for(int i = 0 ; i < length-1; i++)
    {
        int p_time = 0;
        for(int j = i; j < length; j++){
            if(prices[i] > prices[j] || j == (length-1)){
                answer[i] = p_time;
                break;
                }
               p_time ++;
            }
    }
    return answer;
}