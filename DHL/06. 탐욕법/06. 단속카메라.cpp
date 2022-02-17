#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), greater<vector<int>>());
    // 내림 차순 정렬
    /*
        [-5, -3]
        [-14, -5]
        [-18, -13]
        [-20, 15]
    */
    int answer = 0;
    int flag = 30001;
    // 첫비교시 진출점의 최대 
    
    for(size_t i = 0; i < routes.size(); i++){
        if(flag > routes[i][1]){
            flag = routes[i][0];
            // 구간 내 ++
            answer++;
        }
    }
    return answer;
}
