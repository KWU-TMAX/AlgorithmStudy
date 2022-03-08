function solution(numbers, target) {
    let ret = 0;
    dfs(0, 0);
    function dfs(idx, num) {
        if(idx < numbers.length) {
            dfs(idx + 1, num + numbers[idx]);
            dfs(idx + 1, num - numbers[idx]);
        } else {
            if(target === num)
                ret++;
        }
    }
    return ret;
}