#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while(a>0 && b>0){
        if(a%2 != 0){
            if(a+1 == b) return answer;
        }
        if(b%2 != 0){
            if(b+1 == a) return answer;
        }
        a = ceil((double)a/2);
        b = ceil((double)b/2); 
        answer ++;
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}