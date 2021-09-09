
#include <string>
#include <cstring>
#include <vector>

using namespace std;


bool solution(vector<string> phone_book) {


	for (int j = 0; j < phone_book.size() - 1; j++)
	{
		for (int k = j + 1; k < phone_book.size(); k++)
		{
			if (phone_book.at(j).size() < phone_book.at(k).size())
			{
				if (strncmp(phone_book.at(j).c_str(), phone_book.at(k).c_str(), phone_book.at(j).size()) == 0) return false;
			}
			else
			{
				if (strncmp(phone_book.at(j).c_str(), phone_book.at(k).c_str(), phone_book.at(k).size()) == 0) return false;
			}
		}
	}
	return true;
}



// 1번 solution 효율성 테스트 3,4 실패


bool solution(vector<string> phone_book) {

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book.size(); j++) {
            if (i == j)
                continue;

            int answer = phone_book[j].find(phone_book[i]);
            if (answer == 0) {
                return false;
            }
        }
    }
    return true;
}

// 2번 solution 효율성 테스트 3,4 실패

#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    
    bool answer = true;

    unordered_map<string, int> hash_map;
    // 해쉬로 풀어보자
    for(int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;
    // 맵을 구성해보자 
    
    for(int i = 0; i < phone_book.size(); i++) {
        
        string phone_number = "";
        
        for(int j = 0; j < phone_book[i].size(); j++) {
        
            phone_number += phone_book[i][j];
            
            if(hash_map[phone_number] == 1)
                // 이미 map에 있는 건가?
                if(phone_number != phone_book[i]) 
                    // 근데 나자신이 아니다?
                    answer = false;
        
        }
    }

    return answer;
}

// 통과 
