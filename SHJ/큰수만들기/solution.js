// function eraseArr(str, cnt) {
//     const headArr = str.split('').sort((a,b) => a-b);
//     const cpHeadArr = str.split('');
//     let ret = "";
//     let a = 0;
//     for(const h of headArr) {
//         let idx = cpHeadArr.indexOf(h);
//         if(idx > -1) {
//             a++;
//             cpHeadArr[idx] = -1;
//         }
//         if(cnt === a) break;
//     }
//     for(const cp of cpHeadArr) {
//         if(cp>-1) ret += cp;
//     }
//     return ret;
// }

// function solution(number, k) {
//     // 4177252  841로 나눔
//     let firstStr = number.substr(0, number.length - k + 1);
//     let lastStr = number.substr(number.length - k + 1);
//     let largestNumInFirstStr = firstStr.split('').sort((a,b) => b-a)[0];
//     let largestNumIndex = number.indexOf(largestNumInFirstStr);

//     let headStr = firstStr.substr(0, largestNumIndex);
//     let middleStr = firstStr.substr(largestNumIndex);
    
//     if(largestNumIndex <= k) {  // headStr 안쓰는 파트
//         k -= largestNumIndex;
//         return eraseArr(middleStr, k) + lastStr;
//     } else {
//         return eraseArr(headStr, k) + middleStr;
//     }
// }

// 테스트 1 〉	실패 (0.16ms, 30.3MB)
// 테스트 2 〉	실패 (0.18ms, 30.3MB)
// 테스트 3 〉	실패 (0.18ms, 30.3MB)
// 테스트 4 〉	실패 (0.75ms, 30.3MB)
// 테스트 5 〉	실패 (0.95ms, 30.3MB)
// 테스트 6 〉	실패 (53.27ms, 32MB)
// 테스트 7 〉	실패 (1318.59ms, 35.6MB)
// 테스트 8 〉	실패 (6627.54ms, 35.3MB)
// 테스트 9 〉	실패 (207.36ms, 60.3MB)
// 테스트 10 〉	실패 (시간 초과)
// 테스트 11 〉	통과 (0.16ms, 30.2MB)
// 테스트 12 〉	통과 (0.17ms, 30.4MB)
function calculate(ret, str, count) {
    if(count < 1 || str.length === 0) return ret+str;
    let checkStr = str.substr(0, count+1);
    let biggestNum = checkStr.split('').sort((a,b)=>b-a)[0];
    ret += biggestNum;
    let idx = str.indexOf(biggestNum);
    return calculate(ret, str.substr(idx+1), count-idx);
}

function solution(number, k) {
    let cal = "";
    if(number.length <= k) return -1;
    let ret = calculate(cal, number, k);
    if(ret.split('').sort((a,b)=>b-a)[0] === "0") return "0";
    return ret;
}

console.log(solution("1924", 2));
console.log(solution("1231234", 3));
console.log(solution("4177252841", 4));
console.log(solution("4177252841", 1));
console.log(solution("0000", 3));

// 테스트 1 〉	통과 (0.11ms, 30.2MB)
// 테스트 2 〉	통과 (0.14ms, 30MB)
// 테스트 3 〉	통과 (0.19ms, 30.3MB)
// 테스트 4 〉	통과 (0.52ms, 30MB)
// 테스트 5 〉	통과 (3.78ms, 32MB)
// 테스트 6 〉	통과 (1267.13ms, 38MB)
// 테스트 7 〉	통과 (2699.32ms, 38.9MB)
// 테스트 8 〉	실패 (시간 초과)
// 테스트 9 〉	통과 (89.55ms, 40.6MB)
// 테스트 10 〉	실패 (시간 초과)
// 테스트 11 〉	통과 (0.13ms, 30.2MB)
// 테스트 12 〉	실패 (0.13ms, 30.2MB)