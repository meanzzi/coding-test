function solution(array, commands) {
    const answer = [];
   
    
    for(let x=0; x<commands.length; x++){
        let i = commands[x][0];
        let j = commands[x][1];
        let k = commands[x][2];
        
        let slice_array = array.slice(i-1,j);
        slice_array.sort((a,b) => a-b);
        
        answer.push(slice_array[k-1]);
    }
    return answer;
}