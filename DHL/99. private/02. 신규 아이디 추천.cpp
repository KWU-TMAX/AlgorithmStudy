/*
  특별한 알고리즘이 있는것인지 알고 한참 찾아보았지만 결국엔 주어진 조건에 대한 것을 정리한 후 하나씩 해결해 나가면 되는 쉬운문제였다.
  풀이시간은 30분 
  1. 이런 시뮬레이션 문제는 조건을 제대로 파악해야한다. 
  2. 시뮬레이션 문제에서 주어지는 조건에 대한 모든 경우를 번호를 적어 나열한다. 
  3. 나열한 조건에서 선행되어야하는것에 대해서 다시 순서를 바꾼다.
  4. 같이 해결할 수 없는지에 대해서 생각한다. 모든 조건에 대한 if문이 아니라 같은 아이디어로 줄일순 없는지 생각한다. 
  5. 가지치기할수 있는 경우의 수
*/

#include <string>
#include <vector>

using namespace std;


string solution(string new_id) {
    string answer = "";
    vector<char> process_1;
    vector<char> process_3;
    vector<char> process_4;

    int lengthOfID = new_id.length();

    // 첫번째 조건 & 두번째 조건
    for (int i = 0; i < lengthOfID; i++)
    {
        if ((int)new_id[i] > 64 && (int)new_id[i] < 91)
        {
            new_id[i] = (char)((int)new_id[i] + 32);
        }
        if (((int)new_id[i] > 96 && (int)new_id[i] < 123) || ((int)new_id[i] > 47 && (int)new_id[i] < 58) || (new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.'))
        {
            process_1.push_back(new_id[i]);
        }
    }
    // 세번째 조건
    process_3.push_back(process_1.at(0));
    for (int k = 1; k < process_1.size(); k++)
    {
        if ((process_1.at(k-1) != '.') || (process_1.at(k) != '.'))
        {
            process_3.push_back(process_1.at(k));
        }
    }
    // 네번째 조건
    for (int p = 0; p < process_3.size(); p++)
    {
        if (process_3.front() == '.' && p == 0)
        { }
        else if (process_3.back() == '.' && p == process_3.size() - 1)
        {}
        else
        {
            process_4.push_back(process_3.at(p));
        }
    }
    // 다섯번째 조건
    if (process_4.size() == 0)
    {
        process_4.push_back('a');
    }
    // 여섯번째 조건
    if (process_4.size() >= 16)
    {
        int popBackCount = process_4.size() - 15;
        for (int q = 0; q < popBackCount; q++)
        {
            process_4.pop_back();
        }
    }

    if (process_4.back() == '.')
    {
        process_4.pop_back();
    }
    // 마지막 조건
    if (process_4.size() <= 2)
    {
        int pushBackCount = 3 - process_4.size();
        for (int r = 0; r < pushBackCount; r++)
        {
            process_4.push_back(process_4.at(process_4.size()-1));
        }
    }
    // string을 resize를 해주어야 한다.
    answer.resize(process_4.size());
    for (int s = 0; s < process_4.size(); s++)
    {
        answer.at(s) = process_4.at(s);
    }

    return answer;
}
