function solution(genres, plays) {
    var answer = [];
    let obj = {};
    for(let i=0; i<genres.length; i++) {
        if(obj[genres[i]] === undefined) {
            let data = {
                value : plays[i],
                arr : [[i, plays[i]]]
            };
            obj[genres[i]] = data;
        } else {
            obj[genres[i]].value += plays[i];
            obj[genres[i]].arr.push([i, plays[i]]);
        }
    }
    let sortable = [];
    for(let key in obj) {
        sortable.push([key, obj[key].value]);
    }
    sortable.sort((a,b) => b[1] - a[1]);
    for(let sorted of sortable) {
        obj[sorted[0]].arr.sort((a,b) => b[1] - a[1]);
        let min = Math.min(obj[sorted[0]].arr.length, 2);
        for(let a=0; a<min; a++) {
            answer.push(obj[sorted[0]].arr[a][0]);
        }
    }
    return answer;
}