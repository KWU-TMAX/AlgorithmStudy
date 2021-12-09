#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> numVector;
    // 문자열을 숫자로 만들어서 벡터에 넣는다.
    for(int i = 0; i < number.size(); i++) {
        int tmp = 0;
        tmp= number[i] - '0';
        numVector.push_back(tmp);
    }
    
    // 람다를 활용하여 내림 차순으로 sorting
    sort(numVector.begin(),numVector.end(),[](int a, int b) {	
			return a > b;
		});
    
    // k만큼 pop
    for(int i = 0; i < k; i++) {
        numVector.pop_back();
    }
    
		// 남은수 그대로 이어 붙이면 최대값
    for(int i=0; i < numVector.size();i++){
        answer += to_string(numVector[i]);
    }
    
    return answer;
}
