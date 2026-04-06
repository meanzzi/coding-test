function solution(my_string) {
    var answer = [];
    for(let i=0; i<my_string.length; i++){
        if(my_string[i] >= '0' && my_string[i] <='9'){
            answer.push(Number(my_string[i]));
        }
    }
    answer.sort((a,b) => a-b); //배열일때만 sort 가능
    return answer;
}