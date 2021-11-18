function solution(array, commands) {
    return commands.map(commands =>{
        var newArr = array.slice(commands[0]-1, commands[1]).sort((a,b)=>a-b);
        return newArr[commands[2]-1];
    });
}