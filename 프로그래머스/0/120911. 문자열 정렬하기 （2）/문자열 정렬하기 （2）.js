function solution(my_string) {
    const answer = [];
    for(let i=0; i<my_string.length; i++){
        answer.push(my_string[i].toLowerCase()); //배열에서만 push 가능
    }
    answer.sort(); //문자 정렬
    return answer.join(''); //문자열 반환
}