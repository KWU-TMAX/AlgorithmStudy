#include <iostream>
#include <string>

using namespace std;

string solution(string name, int k)
{
    string answer = "";
    int position = 0;
    int maxPosition = 0;
    char maxNum = name[0];
    int numLength = name.length()-k;
    
    for (int i = 0; i < numLength; i++)
    {
        for (int j = position + 1; j <= k + position; j++)
        {
            if (name[maxPosition] < name[j])
            {
                maxNum = name[j];
                maxPosition = j;
            } 
        }
        // 뺄 수 있는 위치만큼 보고, 그중 가장 큰 수를 넣는다
        k -= maxPosition-position;
        // max position 만큼 뺐으니까, 뺄수있는 수도 적어져야한다.
        answer += name[maxPosition];
        position = maxPosition+1;
        maxPosition = position;
    }
    return answer;
}
