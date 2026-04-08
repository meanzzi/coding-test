function solution(s){
    var answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    console.log('Hello Javascript')
    let pCount = 0, yCount = 0;
    for(let i=0; i<s.length; i++){
        if(s[i] === 'p' || s[i] === 'P') pCount ++;
        else if(s[i] === 'y' || s[i] === 'Y') yCount++;
    }
    if(pCount !== yCount) return false;

    return answer;
}