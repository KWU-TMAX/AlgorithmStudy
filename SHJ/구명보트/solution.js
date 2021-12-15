/*function calculate(newPeople, limit, rest, cnt) {
    if(newPeople.length < 1) {
        return ++cnt;
    }
    if(rest < 40) {
        return calculate(newPeople, limit, limit, ++cnt);
    }
    for(let i=0; i<newPeople.length; i++) {
        if(newPeople[i] <= rest) {
            rest -= newPeople[i];
            newPeople.splice(i, 1);
            break;
        }
    }
    return calculate(newPeople, limit, rest, cnt);
}

function solution(people, limit) {
    const sortedPeople = people.sort((a,b) => b-a);
    return calculate(sortedPeople, limit, limit, 0);
}*/

// console.log(solution([70, 50, 80, 50], 100));
// console.log(solution([70, 80, 50], 100));
let answer = 0;

console.log(solution([40, 40, 40,40, 50, 50, 50, 50], 130));  // 여기서 틀림


// 정확성  테스트
// 테스트 1 〉	실패 (런타임 에러)
// 테스트 2 〉	통과 (3.39ms, 31.3MB)
// 테스트 3 〉	실패 (런타임 에러)
// 테스트 4 〉	실패 (런타임 에러)
// 테스트 5 〉	실패 (런타임 에러)
// 테스트 6 〉	실패 (런타임 에러)
// 테스트 7 〉	통과 (6.62ms, 32.5MB)
// 테스트 8 〉	통과 (0.28ms, 30.1MB)
// 테스트 9 〉	실패 (런타임 에러)
// 테스트 10 〉	실패 (런타임 에러)
// 테스트 11 〉	실패 (런타임 에러)
// 테스트 12 〉	실패 (런타임 에러)
// 테스트 13 〉	실패 (런타임 에러)
// 테스트 14 〉	실패 (런타임 에러)
// 테스트 15 〉	통과 (0.30ms, 30.1MB)
// 효율성  테스트
// 테스트 1 〉	실패 (런타임 에러)
// 테스트 2 〉	실패 (런타임 에러)
// 테스트 3 〉	실패 (런타임 에러)
// 테스트 4 〉	실패 (런타임 에러)
// 테스트 5 〉	실패 (런타임 에러)

// function calculate(newPeople, limit, rest, cnt, curBoat) {
//     if(newPeople.length < 1 && curBoat === 1) {
//         answer++;
//         return [];
//     }
//     for(let i=0; i<newPeople.length; i++) {
//         if(newPeople[i] < 40 || newPeople[i] > 240) return -1;
//         if(newPeople[i] <= rest) {
//             rest -= newPeople[i];
//             newPeople.splice(i, 1);
//             break;
//         }
//     }
//     if(rest < 40 || curBoat === 1) {
//         answer++;
//         // return calculate(newPeople, limit, limit, ++cnt, 0);
//         return newPeople;
//     }
//     return calculate(newPeople, limit, rest, cnt, 1);
// }

// function solution(people, limit) {
//     if(people.length > 50000 || people.length < 1) return -1;
//     if(limit < 40 || limit > 240) return -1;
//     const sortedPeople = people.sort((a,b) => b-a);
//     while(1) {
//         const ret = calculate(sortedPeople, limit, limit, 0, 0);
//         if(ret.length < 1) break;
//     }
//     return answer;
// }
/*
정확성  테스트
테스트 1 〉	통과 (27.39ms, 32.7MB)
테스트 2 〉	통과 (3.32ms, 30.8MB)
테스트 3 〉	통과 (20.84ms, 33.2MB)
테스트 4 〉	통과 (17.50ms, 32.5MB)
테스트 5 〉	통과 (11.14ms, 32.2MB)
테스트 6 〉	통과 (8.10ms, 32.6MB)
테스트 7 〉	통과 (8.38ms, 33.1MB)
테스트 8 〉	통과 (0.31ms, 30MB)
테스트 9 〉	통과 (1.80ms, 32.6MB)
테스트 10 〉	통과 (13.26ms, 32.4MB)
테스트 11 〉	통과 (15.21ms, 32.8MB)
테스트 12 〉	통과 (20.16ms, 31.9MB)
테스트 13 〉	통과 (14.87ms, 32.6MB)
테스트 14 〉	통과 (5.11ms, 31MB)
테스트 15 〉	통과 (0.49ms, 30.2MB)
효율성  테스트
테스트 1 〉	실패 (런타임 에러)
테스트 2 〉	실패 (런타임 에러)
테스트 3 〉	실패 (런타임 에러)
테스트 4 〉	실패 (런타임 에러)
테스트 5 〉	실패 (런타임 에러)
*/
/* 
function solution(people, limit) {
    var answer = 0;
    const sortedPeople = people.sort((a,b) => b-a);
    while(1) {
        if(sortedPeople.length === 1) {
            answer++;
            break;
        }
        if(sortedPeople.length === 0) {
            break;
        }
        if(sortedPeople[0] + sortedPeople[sortedPeople.length-1] > limit) {
            sortedPeople.shift();
            answer++;
        } else {
            sortedPeople.shift();
            sortedPeople.pop();
            answer++;
        }
    }
    return answer;
}

정확성  테스트
테스트 1 〉	통과 (2.81ms, 31.9MB)
테스트 2 〉	통과 (1.46ms, 30.4MB)
테스트 3 〉	통과 (2.57ms, 30.5MB)
테스트 4 〉	통과 (2.19ms, 30.3MB)
테스트 5 〉	통과 (0.82ms, 30.5MB)
테스트 6 〉	통과 (0.70ms, 30.3MB)
테스트 7 〉	통과 (0.74ms, 30.4MB)
테스트 8 〉	통과 (0.16ms, 30MB)
테스트 9 〉	통과 (0.17ms, 30.5MB)
테스트 10 〉	통과 (1.32ms, 30.4MB)
테스트 11 〉	통과 (1.34ms, 30.4MB)
테스트 12 〉	통과 (1.05ms, 30.2MB)
테스트 13 〉	통과 (1.33ms, 30.4MB)
테스트 14 〉	통과 (1.77ms, 30.2MB)
테스트 15 〉	통과 (0.34ms, 30.3MB)
효율성  테스트
테스트 1 〉	실패 (시간 초과)
테스트 2 〉	실패 (시간 초과)
테스트 3 〉	실패 (시간 초과)
테스트 4 〉	실패 (시간 초과)
테스트 5 〉	실패 (시간 초과)
 */
function solution(people, limit) {
    var answer = 0;
    const sortedPeople = people.sort((a,b) => b-a);
    for(let i=0; i<sortedPeople.length; i++) {
        if(sortedPeople[i] + sortedPeople[sortedPeople.length-1] > limit) {
            answer++;
        } else {
            sortedPeople.pop();
            answer++;
        }
    }
    return answer;
}
/* 
여기서 알수 있듯 shift는 메모리 상으로 굉장히 시간을 많이 잡아먹는 동작이다.
정확성  테스트
테스트 1 〉	통과 (2.29ms, 32.1MB)
테스트 2 〉	통과 (1.16ms, 30.2MB)
테스트 3 〉	통과 (1.28ms, 30.3MB)
테스트 4 〉	통과 (1.10ms, 30.1MB)
테스트 5 〉	통과 (0.72ms, 30.1MB)
테스트 6 〉	통과 (0.41ms, 30.5MB)
테스트 7 〉	통과 (0.59ms, 30.2MB)
테스트 8 〉	통과 (0.10ms, 30.3MB)
테스트 9 〉	통과 (0.27ms, 30.2MB)
테스트 10 〉	통과 (1.14ms, 30.4MB)
테스트 11 〉	통과 (1.06ms, 30.3MB)
테스트 12 〉	통과 (0.91ms, 30.4MB)
테스트 13 〉	통과 (1.52ms, 30.4MB)
테스트 14 〉	통과 (2.37ms, 30.6MB)
테스트 15 〉	통과 (0.29ms, 30.1MB)
효율성  테스트
테스트 1 〉	통과 (13.69ms, 33.7MB)
테스트 2 〉	통과 (13.38ms, 33.5MB)
테스트 3 〉	통과 (15.03ms, 33.7MB)
테스트 4 〉	통과 (10.92ms, 33.8MB)
테스트 5 〉	통과 (11.93ms, 33.4MB) */