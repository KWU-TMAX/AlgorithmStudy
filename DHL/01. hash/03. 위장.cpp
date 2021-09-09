#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
옷의 가짓수는 중복이 아니고
첫번째 인자는 그냥 형태 두번째 인자는 옷의종류(모자, 아우터, 바지) 큼직한 카테고리
사실 두번째 인자가 몇개가 중복인지가 중요하다.

따라서 모자가 몇개인지, 아우터가 몇개인지가 중요하다.
모자가 2개이고 아우터가 2개라면 벗는 경우 포함해서 모두 모자1, 모자2, 모자안쓴거 이렇게 3가지 경우고 
이 경우의 수를 모두 곱하고 벌거벗는 경우만 -1 하면 답이다.
*/
int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<string, int> clothes_map;

	for (int i = 0; i < clothes.size(); i++)
	{
		clothes_map[clothes.at(i).at(1)]++;
    // 벡터의 두번째 요소가 맵에 있다면 +1을 해준다.
	}
	unordered_map <string, int> ::iterator it;
	// 반복자를 사용하여 순회해서 map의 value에 +1 한 결과를 곱해준다.
  for (it = clothes_map.begin(); it != clothes_map.end(); it++) {
		answer = answer * (it->second + 1);
	}
	return answer-1;
  // 벌거벗는 경우의 수를 제외시킨다.
}
