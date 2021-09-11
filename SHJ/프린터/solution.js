function solution(priorities, location) {
    let answer = 0;
    let sortedPriorities = priorities.slice().sort((a,b)=>b-a);
    let i = 0; // priority의 index
    let j = 0; // cp의 index
    while(1) {
        if(i == priorities.length)
            i = 0;
        if(sortedPriorities[j] != priorities[i]) {
            i++;
            continue;
        }
        else if(sortedPriorities[j] == priorities[i] && i == location) {
            answer++;
            break;
        }
        else {
            j++;
            priorities[i] = -1;
            answer++;
        }
    }
    return answer;
}