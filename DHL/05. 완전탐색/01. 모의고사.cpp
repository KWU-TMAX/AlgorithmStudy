#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 점수가 동점인 경우를 생각해야한다. 결국 인원모두의 대소비교가 이루어져야한다. 
// 점수를 리턴하는것이 아니라 학생 number들을 리턴해야한다. 

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int firstStudent[5] = { 1, 2, 3, 4, 5 };
	int secondStudent[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int thirdStudent[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	// 각각 학생들의 규칙들
	int score[3] = {0,0,0};
	int maxScore = 0;
	for (int i = 0; i < answers.size(); i++) {
        	// 찍신 강림했을때 각 score배열의 원소를 ++ 한다. 
		if (firstStudent[i % 5] == answers[i]) score[0]++;
		if (secondStudent[i % 8] == answers[i]) score[1]++;
		if (thirdStudent[i % 10] == answers[i]) score[2]++;
	}
    	maxScore = max(max(score[0],score[1]),score[2]);
    	// 점수의 최댓값을 찾는다. 
    	for(int i = 0; i < 3; i++) {
        	// 최댓값을 가지는 모두를 push_back한다. 
        	if(maxScore == score[i]) answer.push_back(i+1);       
    	}
	return answer;
}
