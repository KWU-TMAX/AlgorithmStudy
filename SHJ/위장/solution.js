function solution(clothes) {
    var answer = 1;
    let closet = {};
    for(const cloth of clothes) {
        if(!closet[cloth[1]]) {
            closet[cloth[1]] = [cloth[0]];
        } else {
            closet[cloth[1]].push(cloth[0]);
        }
    }
    for(const temp in closet) {
        let cur = closet[temp].length + 1;
        answer *= cur;
    }
    answer--;
    return answer;
}