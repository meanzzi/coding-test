function solution(my_string, s, e) {
    let arr = my_string.slice(s, e+1);
    let reversed = arr.split('').reverse().join('');
    let answer = my_string.slice(0,s) + reversed + my_string.slice(e+1, my_string.length+1);

    return answer;
}