#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0, y = 0;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'p' || s[i] == 'P') p++;
        if(s[i] == 'y' || s[i] == 'Y') y++;
    }
    
   if(p!=y) answer = false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}