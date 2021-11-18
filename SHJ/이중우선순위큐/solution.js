function solution(operations) {
    let arr = [];
    let answer = [];
    for(const oper of operations) {
        if(oper[0] === "I") {
            let num = Number(oper.substr(2));
            arr.push(num);
            arr.sort((a,b) => a-b);
        } else {
            if(arr.length > 0) {
                if(oper[2] === "-") {
                    arr.shift();
                } else {
                    arr.pop();
                }
            }
        }
    }
    if(arr.length > 0) {
        answer.push(arr[arr.length-1]);
        answer.push(arr[0]);
    } else {
        answer = [0,0];
    }
    return answer;
} 

// console.log(solution(["I 16","D 1"]));
// console.log(solution(["I 7","I 5","I -5","D -1"]));
// console.log(solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]));
// console.log(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]));