/* Math.ceil()  - 올림
Math.floor()  - 내림
Math.round()  - 반올림 */

function solution(progresses, speeds) {
    var answer = [];
    let task = [];
    
    for(let i=0; i<progresses.length; i++) {
        let progress = Math.ceil((100-progresses[i]) / speeds[i]);
        task.push(progress);
    }
    
    let cur = task[0];
    let index = 1;
    for(let j=1; j<task.length; j++) {
        if(task[j] > cur) {
            cur = task[j];
            answer.push(index);
            index = 1;
        } else {
            index++;
        }
    }
    answer.push(index);
    return answer;
}