function solution(arr)
{
    const answer = [];
    
    answer.push(arr[0]);
    for(let i=1; i<arr.length; i++){
        if(answer[answer.length-1] === arr[i]) continue;
        else{
            answer.push(arr[i]);
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    console.log('Hello Javascript')
    
    return answer;
}