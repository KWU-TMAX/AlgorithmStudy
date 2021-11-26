function solution(answers) {
    const user = {
        1: [1,2,3,4,5],
        2: [2,1,2,3,2,4,2,5],
        3: [3,3,1,1,2,2,4,4,5,5]
    }
    let ret = [];
    let answer = [];
    let max = 0;
    for(let i =1; i<4; i++) {
        let correct = 0;
        for(let j=0; j<answers.length; j++) {
            let currentUser = user[i];
            if(answers[j] === currentUser[j%currentUser.length]) correct++;
        }
        ret.push([i,correct]);
    }
    ret.sort((a,b) => b[1]-a[1]);
    answer.push(ret[0][0]);
    max = ret[0][1];
    for(let i=1; i<3; i++) {
        if(max === ret[i][1]) answer.push(ret[i][0]);
    }
    return answer;
}
