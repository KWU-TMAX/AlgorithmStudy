function solution(numbers) {
    let answer = "";
    let convertArr = [];
    for(let num1 of numbers) {
        let str = String(num1);
        let idx = Math.ceil(6/str.length);
        for(let i=0; i<idx; i++) str += num1;
        str = str.substr(0,6);
        str += String(num1).length;
        convertArr.push(str);
    }
    convertArr.sort((a,b) => b-a);
    for(let num2 of convertArr) {
        let itos = String(num2);
        let first = Number(itos[itos.length-1]);
        answer += itos.substr(0,first);
    }
    if(answer[0] === "0") return "0";
    return answer;
}

solution([6, 10, 2]);
solution([3001, 30, 4, 5, 6]);