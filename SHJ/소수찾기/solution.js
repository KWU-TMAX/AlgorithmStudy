function solution(numbers) {
    if(numbers.length < 1 || numbers.length > 7) return;
    let str = numbers.split('').sort((a,b)=>b-a); // 정렬된 array
    let max = Number(str.join(''));
    let arr = new Array(max+1).fill(false);
    let answer = [];
    for(let i=2; i*i<=max; i++) {
        if(!arr[i]) {
            for(let j=i*i; j<= max; j+= i) {
                arr[j] = true;
            }
        }
    }
    for(let i=2; i<arr.length; i++) {
        if(arr[i] === false) {
            let temp = String(i).split('');
            let cpStr = str.slice();
            let check = true;
            for(const t of temp) {
                let idx = cpStr.indexOf(t);
                if(idx > -1) {
                    cpStr[idx] = -1;
                } else {
                    check = false;
                    break;
                }
            }
            if(check) answer.push(i);
        }
    }
    return answer.length;
}