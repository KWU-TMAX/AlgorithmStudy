#include <string>
#include <vector>
#include <unordered_map>
// 해쉬 맵 사용

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> temp;
    for (string name : participant)
    {
        //해쉬테이블에 key값으로 name을 주고 값을 더함
        temp[name]++;
    }
    for (string name : completion)
    {
        //name key로 접근하여 값을 감소
        temp[name]--;
    }
    //처음부터 해쉬테이블 순회
    for (auto pair : temp)
    {
        //해쉬테이블의 2번째값이 0보다 크다면
        if (pair.second > 0)
        {
            //answer에 해쉬테이블 key값을 넣음
            answer = pair.first;
            break;
        }
    }
    return answer;
}
