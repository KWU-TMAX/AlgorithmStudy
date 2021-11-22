// 풀이 시간은 5분이었지만
// 하나의 솔루션이 통과하지 못했었다 그 경우가 경우의 가짓수를 7
#include <string>
#include <vector>
#include <algorithm>
/*
  이 문제에서 조심해야 할것은 하나도 맞추지 못했거나 하나만 맞췄거나에 대한 것을 잘 이해해야한다. 경우의 수는 1,2,3,4,5,6이 아니라, 0,1,2,3,4,5,6 
  하나만 맞추거나 하나도 못맞춘 경우는 모두 6등이다. 
*/
using namespace std;

int score[7] = {6,6,5,4,3,2,1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int numOfUndifined = 0;
    int numOfCorrect = 0;
    
    for(int i = 0; i < lottos.size(); i++)
    {
        if(lottos[i] == 0) {
            numOfUndifined++;
            // 맞출수도 있는 경우의 수를 주는 0을 count
            continue;
        }
        for(int j = 0; j < win_nums.size(); j++)
        {
            if(lottos[i] == win_nums[j]) {
                numOfCorrect++;
                // 일치하는 숫자에 대한 count
                win_nums.erase(win_nums.begin()+j);
                // 맞춘 정답수를 삭제하여 for문의 효율을 높인다.
            }
        }
    }
    // 맞은 갯수 + 0의 갯수(무조건 맞을수도있다는것)
    answer.push_back(score[numOfCorrect+numOfUndifined]);
    // 맞은 갯수만 count 0이 모두 틀렸다고 가정해버리는 것이다. 
    answer.push_back(score[numOfCorrect]);
    
    return answer;
}
