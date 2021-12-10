const alpha = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"];
const alphaNum = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1]; // B-Z

function solution(name) {
    let answer = 0;
    for(let i=0; i<name.length; i++) {
        const idx = alpha.indexOf(name[i]);
        answer += alphaNum[idx];
    }
    let notA = [];
    for(let i=0; i<name.length; i++) {
        if(name[i] !== 'A') notA.push(i);
    }
    let min = notA[notA.length -1];    // 오른쪽으로 다이렉트로 이동했을 때 ->입력하는 횟수
    for(let j=notA.length-1; j>=0; j--) {    // 여기 for문은 되돌아갔을 때 좌우 키 입력하는 횟수 계산
        let left = notA[j-1] ? notA[j-1] * 2 : 0;   // A가 아닌 j번째 index로 갈때 j-1까지 ->하다가 <-하고
        let right = name.length - notA[j];          // <-해서 j번째 index로 도착하는 거리 계산
        if(left+right < min) {
            min = left+right;                   // 총 거리 계산했을 때 다이렉트로 간 거리보다 적으면 min값 변경
        }
    }
    return answer + min;            // 위 아래 움직인 횟수 + 좌우 움직인 횟수
}

console.log(solution("JEROEN"));     // 56
console.log(solution("JAN"));        // 23
console.log(solution("JAAAAAABC"));  // 14
console.log(solution("AAAAAAAAAB")); // 2
console.log(solution("ABAAAAAAAAABB")); // 7

// 테스트 1 〉	통과 (0.08ms, 30.1MB)
// 테스트 2 〉	통과 (0.11ms, 30.3MB)
// 테스트 3 〉	통과 (0.07ms, 30.4MB)
// 테스트 4 〉	통과 (0.09ms, 30.2MB)
// 테스트 5 〉	통과 (0.09ms, 30.3MB)
// 테스트 6 〉	통과 (0.09ms, 30.2MB)
// 테스트 7 〉	통과 (0.09ms, 30.2MB)
// 테스트 8 〉	통과 (0.07ms, 30MB)
// 테스트 9 〉	통과 (0.08ms, 30MB)
// 테스트 10 〉	통과 (0.11ms, 30.3MB)
// 테스트 11 〉	통과 (0.12ms, 30.4MB)
