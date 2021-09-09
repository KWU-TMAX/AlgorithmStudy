#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map <string, int> ptc_player;
    vector <string>::iterator it;
    
    for(auto it = participant.begin(); it != participant.end(); it++)
    {
        if(ptc_player.end() != ptc_player.find(*it) ){// 명단에 있는 경우
            ptc_player[*it]++;
        }else { //처음이면 등록
            ptc_player[*it] = 1;
        }    
        
    }
    for(auto it = completion.begin(); it != completion.end(); it++){
        if(ptc_player.end() != ptc_player.find(*it) ){
            ptc_player[*it]--;
        }
    }
    for(auto it = participant.begin(); it != participant.end(); it++){
        if(ptc_player[*it] != 0) answer = *it;
    }
    
    return answer;
}
