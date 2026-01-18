#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> used;
    
    used.insert(words[0]);
    for(int i = 1; i< words.size(); i++){
        // 끝말잇기 실패 or 중복되면
        if(words[i-1].back() != words[i].front() || used.count(words[i])>0){
            int num = (i%n)+1;
            int turn = ceil((double)(i+1)/n);
            return {num, turn};
        }
        else {
            used.insert(words[i]);
        }
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << "Hello Cpp" << endl;

    return {0,0};
}