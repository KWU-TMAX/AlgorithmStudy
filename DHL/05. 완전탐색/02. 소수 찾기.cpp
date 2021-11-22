// 걸린시간 45분
/*
  1. 에라토스테네스의 체를 알고 있는가?
  2. 모든 부분집합을 구할 수 있는가? 
  3. 벡터에서 중복된 수 를 제외시킬줄 아는가?
*/

#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 모든 경우의 수를 뽑는다
// 소수 인지 검사한다.
// 매번 뽑혀진 수를 가지고 소수인지 알 순 없으니 소수인지 아닌지를 보는 에라토스 테네스의 체를 만든다. 에라토스 테네스의 채를 만든다. 
/* 
    에라토스 테네스의 체란?
    1. 2부터 소수를 구하고자 하는 구간의 모든 수를 나열한다. 그림에서 회색 사각형으로 두른 수들이 여기에 해당한다.
    2. 2는 소수이므로 오른쪽에 2를 쓴다. (빨간색)
    3. 자기 자신을 제외한 2의 배수를 모두 지운다.
    4. 남아있는 수 가운데 3은 소수이므로 오른쪽에 3을 쓴다. (초록색)
    5. 자기 자신을 제외한 3의 배수를 모두 지운다.
    6. 남아있는 수 가운데 5는 소수이므로 오른쪽에 5를 쓴다. (파란색)
    7. 자기 자신을 제외한 5의 배수를 모두 지운다.
    8. 남아있는 수 가운데 7은 소수이므로 오른쪽에 7을 쓴다. (노란색)
    9. 자기 자신을 제외한 7의 배수를 모두 지운다.
    10. 위의 과정을 반복하면 구하는 구간의 모든 소수가 남는다.
*/
// 에라토스 테네스는 정리가 좀 필요하다. 

void Eratos(int n)
{
    /*  만일 n이 1보다 작거나 같으면 함수 종료 */
    if (n <= 1) return;

    /*	2부터 n까지 n-1개를 저장할 수 있는 배열 할당
		배열 참조 번호와 소수와 일치하도록 배열의 크기는
		n+1 길이만큼 할당(인덱스 번호 0과 1은 사용하지 않음)	*/
	bool* PrimeArray = new bool[n + 1];

	/*  배열초기화: 처음엔 모두 소수로 보고 true값을 줌	*/
	for (int i = 2; i <= n; i++)
	    PrimeArray[i] = true;

	/*	에라토스테네스의 체에 맞게 소수를 구함
		만일, PrimeArray[i]가 true이면 i 이후의 i 배수는 약수로 i를
		가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
		PrimeArray[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시
		소수가 아니게 된다. 그러므로 검사할 필요도 없다.
또한 i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2 에서 i*i로 개선할 수 있다.
	*/
	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
			    PrimeArray[j] = false;
	}

	// 이후의 작업 ...
}

bool erose(int n) { 
    if (n < 2) return false; 
    for (int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) return false; 
    return true; 
}


int solution(string numbers) {
    int answer = 0;
    bool primeNumber[9999999] = {};
    for(int i = 0; i < 10000000; i++)
    {
        primeNumber[i] = true;
    }
    vector<char> number;
    // permutation을 돌기 위한 글자 벡터
    vector<int> result;
    // 나오는 모든 경우의 수를 넣기 위한 벡터;
 
    // 에라토스테네스의 채로 범위내의 소수 배열 만들기
    
    for (int i = 2; i * i <= numbers.size()*numbers.size(); i++) {
		  if (primeNumber[i]) continue;
			for (int j = i * i; j <= numbers.size(); j += i) {
                primeNumber[j] = false;
            }
	  }
    
    for(int i = 0; i <numbers.size(); i++) {
        number.push_back(numbers[i]);
    }
    // 모든 순열을 구하기위해선 소팅이 필요하다.
    sort(number.begin(), number.end());
    
    do {
        string temp = "";
        for (int i = 0; i < number.size(); i++) {
            temp.push_back(number[i]);
            result.push_back(stoi(temp));
        }
        
    }while(next_permutation(number.begin(),number.end()));
    
    sort(result.begin(), result.end()); 
    result.erase(unique(result.begin(), result.end()), result.end()); 
    
    for (int i = 0; i < result.size(); i++) {
        // 소수일 경우 answer++ 
        if (erose(result[i])) answer++; 
    }
    return answer;
}
