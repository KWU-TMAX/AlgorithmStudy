// 푼 시간 60분
/*
   오래걸린 이유 1: 상협이 형이 알려줬다. 이유는 문제를 똑바로 못읽음 체육복을 여벌로 가져온애가 잃어버린 애가 될수도있다는것
   오래걸린 이유 2: 아무한테도 안빌려줄수도있는데 그경우 그 친구는 체육복의 갯수가 2이다. 따라서 2 나 1인 애들은 모두 수업을 들을 수 있는것
   
   생각지 못한 케이스 처음에 뒤에친구한테 먼저 물어보고 빌리게 되면 앞에서 순차적으로 봤을 경우 아래와 같은 상황이 생긴다
   case 1) 2 0 2 0 2 0 인 경우
       [loop 1] 2 1 1 0 2 0
       [loop 2] 2 1 1 1 1 0
       이렇게 되서 결국 한명이 못받게 되는데
       앞에 친구한테서 부터 가지고오게하면
       [loop 1] 1 1 2 0 2 0
       [loop 2] 1 1 1 1 2 0
       [loop 3] 1 1 1 1 1 1
       이렇게 되서 체육복을 입을 수 있게 된다.
       앞에서부터 비교해 나가니 당연히 2 0 2 0 인경우에 앞에 친구부터 빌리기를 도전해야지만 된다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> studentCloth;
    // 모든 학생이 체육복을 가져왔다고 생각한다
    for(int i = 0; i < n ; i++) {
        studentCloth.push_back(1);
    }
    // 안가져온 애들을 -1
    for(int i = 0; i < lost.size(); i++) {
        studentCloth[lost[i]-1]--;
    }
    // 가져온 애들을 +1
    for(int i = 0; i < reserve.size(); i++) {
        studentCloth[reserve[i]-1]++;
    }
    
    for(int i = 0; i < n; i++) {
        if(studentCloth[i] == 0) {
            // 먼저 앞애 놈이 가져왔는지 본다
            if((i != 0) && (studentCloth[i-1] == 2))
            {
                studentCloth[i-1]--;
                studentCloth[i]++;
            }
            // 그 다음 뒤애 친구한테 빌린다.
            else if((i != studentCloth.size()-1) && (studentCloth[i+1] == 2))
            {
                studentCloth[i+1]--;
                studentCloth[i]++;
            }
        }
    }
    
    for(int i = 0 ; i < n; i++){
        if(studentCloth[i] !=0) answer++;
    }
    
    return answer;
}
