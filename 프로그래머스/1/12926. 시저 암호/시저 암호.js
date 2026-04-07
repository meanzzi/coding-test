function solution(s, n) {
    var answer = '';
    
    for(let i=0; i<s.length; i++){ 
        if(s[i] === ' '){
            answer += ' ';
            continue;
        }
        
        let code = s[i].charCodeAt(0) // code - 65
        if(code >= 65 && code <= 90){
            answer += String.fromCharCode((code - 65 + n) % 26 + 65);
        }
        else if(code >= 97 && code <= 122) {
            answer += String.fromCharCode((code - 97 + n) % 26 + 97);
        }   
    }
    
    return answer;
}