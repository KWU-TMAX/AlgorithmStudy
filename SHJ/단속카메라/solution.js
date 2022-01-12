// function solution(routes) {
//     let array = [];

//     function check(route) {
//         let ret = false;
//         if(array.length === 0) {
//             array.push(route);
//             return;
//         }
//         for(let i=0; i<array.length; i++) {
//             if(array[i][0] <= route[0] && array[i][1] >= route[0]) {
//                 ret = true;
//                 array[i][0] = route[0];
//             }
//             if(array[i][0] <= route[1] && array[i][1] >= route[1]) {
//                 ret = true;
//                 array[i][1] = route[1];
//             }
//             if(ret) {
//                 return;
//             }
//         }
//         array.push(route);
//     }

//     routes.sort((a,b) => b[0] - a[0]);
//     for(const route of routes) {
//         check(route);
//     }
//     return array.length;
// }

// 정확성  테스트
// 테스트 1 〉	실패 (0.17ms, 30.4MB)
// 테스트 2 〉	실패 (0.26ms, 30.3MB)
// 테스트 3 〉	실패 (0.27ms, 30.1MB)
// 테스트 4 〉	실패 (0.29ms, 30.3MB)
// 테스트 5 〉	실패 (0.31ms, 30.5MB)
// 효율성  테스트
// 테스트 1 〉	실패 (8.80ms, 32.2MB)
// 테스트 2 〉	실패 (4.60ms, 32.2MB)
// 테스트 3 〉	실패 (11.85ms, 32MB)
// 테스트 4 〉	실패 (0.92ms, 30.1MB)
// 테스트 5 〉	실패 (13.28ms, 32.5MB)

function solution(routes) {
    routes.sort((a,b) => a[0] - b[0]);
    let out = routes[0][1];
    let ret = 0;
    for(let i=1; i<routes.length; i++) {
        if(out < routes[i][0]) {
            out = routes[i][1];
            ret++;
        }
        if (out > routes[i][1]) {
            out = routes[i][1];
        }
    }
    return ret+1;
}

/* 정확성  테스트
테스트 1 〉	통과 (0.08ms, 30.3MB)
테스트 2 〉	통과 (0.13ms, 30.1MB)
테스트 3 〉	통과 (0.11ms, 30.1MB)
테스트 4 〉	통과 (0.10ms, 30.2MB)
테스트 5 〉	통과 (0.09ms, 30.3MB)
효율성  테스트
테스트 1 〉	통과 (1.03ms, 30.2MB)
테스트 2 〉	통과 (0.86ms, 29.9MB)
테스트 3 〉	통과 (2.71ms, 31.7MB)
테스트 4 〉	통과 (0.22ms, 30.1MB)
테스트 5 〉	통과 (3.07ms, 31.8MB) */

console.log(solution([[-20,-15], [-14,-5], [-18,-13], [-5,-3]]));
console.log(solution([[1,15], [12,15], [16,17], [16,18], [3, 16], [9,11]]));

/* https://mungto.tistory.com/49
1. 정렬을 합니다. 기준점은 차량이 진입하는 순간입니다.
정렬을 하는 이유는 순서대로 접근하기 쉽게하기 위해서입니다.
2. 처음 차가 나가는 거리를 임시변수에 넣어줍니다.
이 값을 이용해서 비교를 합니다.
3. 다음차가 현재차가 나간후에 들어온다면 카메라를 추가해야합니다.
나가는 순간에 카메라를 설치해도 다음차를 찍지못하기 때문입니다.
4. 현재차보다 다음차가 나가는 거리가 짧다면 변수값을 갱신해줍니다.
현재 차보다 늦게 들어왔지만 더 빨리 나가는 차가 있을때는 둘이 겹치는 부분에
카메라를 두기 위해서 입니다.
5. 위 과정을 반복하면 최종 카메라 -1개가 나옵니다.
마지막 카메라가 추가되지 않기 때문입니다.
따라서 시작할때 카메라 대수를 1대로 설정하거나 반환전에 +1을 해서 리턴합니다. */