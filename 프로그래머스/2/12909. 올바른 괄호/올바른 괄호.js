function solution(s){
    let count = 0;
    
    for(let i=0; i<s.length; i++){
        if(s[i] === '(') count++;
        else count--;
        
        if(count < 0) return false; //중간에 짝 안맞으면 바로 아웃
    }
    
    if(count === 0) return true;
    return false;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    console.log('Hello Javascript')

}