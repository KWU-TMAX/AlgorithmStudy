function solution(citations) {
    let sortedArr = citations.sort((a,b)=> b-a);
    let idx = 0;
    for(let i = sortedArr[0]; i>=0; i--) {
      if(i <= sortedArr[idx]) idx++;     // == 이 되어버리면 중복 체크를 못함
      if(i <= idx) return i;
    }
}