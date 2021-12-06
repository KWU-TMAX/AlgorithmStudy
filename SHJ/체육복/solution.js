function solution(n, lost, reserve) {
    let ret = n;
    lost.sort((a,b) => a-b);
    for(let a=0; a<lost.length; a++) {
        let idx = reserve.indexOf(lost[a]);
        if(idx > -1) {
            reserve[idx] = -1;
            lost[a] = -1;
        }
    }
    let newArr = [];
    for(let n of lost) {
        if(n !== -1) {
            newArr.push(n);
        }
    }
    for(let i of newArr) {
        let idx1 = reserve.indexOf(i-1);
        let idx2 = reserve.indexOf(i+1);
        if(idx1 > -1) {
            reserve[idx1] = -1;
        } else if(idx2 > -1) {
            reserve[idx2] = -1;
        } else {
            ret--;
        }
    }
    return ret;
}

console.log(solution(5,[2, 4],[1, 3, 5]));
console.log(solution(5,	[2, 4]	,[3]));
console.log(solution(3,[3],[1]));