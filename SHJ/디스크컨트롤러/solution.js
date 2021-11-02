// 생각보다 간단했다
// waiting 하는 배열을 두고 reading 중인 변수를 선언
// wating하는 애들 중에서 소요시간이 짧은 애들을 먼저 실행 시키면 됨

function solution(jobs) {
    let job_cnt = jobs.length;
    let sum = 0;
    let waiting = [];
    let time = -1;
    let reading = null;
    let reading_endTime = 0;
    let need_sort = false;
    jobs.sort((a,b) => {
        return a[0] - b[0];
    });
    while(jobs.length > 0 || waiting.length > 0 || reading) {
        time++;
        if(reading_endTime === time) reading = null;
        while(1) {
            if(jobs.length > 0 && time === jobs[0][0]) {
                waiting.push(jobs[0]);
                jobs.shift();
                need_sort = true;
            } else {
                break;
            }
        }
        if(need_sort) {
            waiting.sort((a,b) => {
                return a[1] - b[1]; 
            });
            need_sort = false;
        }
        if(!reading && waiting.length > 0) {
            reading = waiting.shift();
            reading_endTime = time + reading[1];
            sum += (reading_endTime - reading[0]);
        }
    }
    return Math.floor(sum/job_cnt);
}