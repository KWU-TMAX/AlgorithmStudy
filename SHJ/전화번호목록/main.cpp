#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	string checkStr = phone_book[0];

	for(int i=1; i<phone_book.size(); i++) {
		auto idx = -1;
		idx = phone_book[i].find(checkStr);
		if(idx == 0) {
			return false;
		} else {
			checkStr = phone_book[i];
		}
	}    
	return answer;
}
