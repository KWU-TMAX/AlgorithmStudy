// const getPermutations= function (arr, selectNumber) {
//     const results = [];
//     if (selectNumber === 1) return arr.map((value) => [value]); // 1개씩 택할 때, 바로 모든 배열의 원소 return
//     arr.forEach((fixed, index, origin) => {
//       const rest = [...origin.slice(0, index), ...origin.slice(index+1)] // 해당하는 fixed를 제외한 나머지 배열 
//       const permutations = getPermutations(rest, selectNumber - 1); // 나머지에 대해 순열을 구한다.
//       const attached = permutations.map((permutation) => [fixed, ...permutation]); // 돌아온 순열에 대해 떼 놓은(fixed) 값 붙이기
//       results.push(...attached); // 배열 spread syntax 로 모두다 push
//     });
//     return results; // 결과 담긴 results return
// };

// function solution(brown, yellow) {
//     let sum = brown + yellow;
//     let max = Math.ceil(sum/2);
//     let cur = 2;
//     let ret = [];
//     let min = 99999999999;
//     let minR = 0;
//     let minL = 0;
//     let answer = [];
//     while(1) {
//         if(cur > max || sum <= 2) break;
//         if(sum % cur === 0) {
//             ret.push(cur);
//             sum /= cur;
//         } else {
//             cur++;
//         }
//     }
//     const per = getPermutations(ret, ret.length);
//     for(let i=1; i<=ret.length; i++) {
//         for(const p of per) {
//             let left = 1;
//             let right = 1;
//             for(let a=0; a<p.length;a++) {
//                 if(a >= i) {
//                     right *= p[a];
//                 } else {
//                     left *= p[a];
//                 }
//             }
//             let ab = Math.abs(left - right);
//             if(min > ab) {
//                 min = ab;
//                 minR = right;
//                 minL = left;
//             }
//         }
//     }
//     answer.push(minR);
//     answer.push(minL);
//     return answer.sort((a,b)=>b-a);
// }

// 테스트 1 〉	실패 (0.38ms, 30.1MB)
// 테스트 2 〉	통과 (0.24ms, 30.2MB)
// 테스트 3 〉	통과 (0.34ms, 30.3MB)
// 테스트 4 〉	실패 (118.22ms, 59.2MB)
// 테스트 5 〉	통과 (0.33ms, 30.3MB)
// 테스트 6 〉	실패 (24.01ms, 40.8MB)
// 테스트 7 〉	실패 (런타임 에러)
// 테스트 8 〉	통과 (0.75ms, 30.6MB)
// 테스트 9 〉	통과 (7.35ms, 34.6MB)
// 테스트 10 〉	통과 (0.41ms, 30.4MB)
// 테스트 11 〉	통과 (0.26ms, 30.3MB)
// 테스트 12 〉	통과 (0.31ms, 30.4MB)
// 테스트 13 〉	통과 (0.68ms, 30.4MB)

function solution(brown, yellow) {
    for(let i=1; i<=Math.ceil(yellow/2); i++) {
        if(yellow % i === 0) {
            let width = yellow/i;
            let height = i;
            if((width+height)*2+4 === brown) {
                return [width+2, height+2];
            }
        }
    }
}

console.log(solution(10, 2));
console.log(solution(8, 1));
console.log(solution(24, 24));