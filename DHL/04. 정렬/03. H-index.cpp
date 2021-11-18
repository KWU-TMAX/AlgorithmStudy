#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> citations) {
    int answer = 0;
    int avg = 0;
    sort(citations.begin(),citations.end());
    for(int i =0; i < citations.size(); i++)
    {
        avg+=citations[i];
    }
    avg= avg/citations.size();
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
    
    std::cout << solution(a) ;
    return 0;
}
