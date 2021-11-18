#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    // 610,106중 
	return b + a < a + b;
		return true; // 610
	return false; // 106
}


string solution(vector<int> numbers) {
	string answer = "";

	vector<string> temp;
	for (int i = 0; i < numbers.size(); i++)
	{
		// 문자열로 담아둠 
		temp.push_back(to_string(numbers[i]));
	}

	sort(temp.begin(), temp.end(), comp);
    
    
	for (int i = 0; i < temp.size();i++)
	{
		answer += temp[i];
	}

	if (answer[0] == '0')
		answer = "0";

	return answer;
}
