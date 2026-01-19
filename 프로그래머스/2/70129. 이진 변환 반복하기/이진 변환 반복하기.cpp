#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {  
    int zeroSum = 0, count = 0;  
    while(s != "1"){
        int zeroCount = 0;
         // 제거할 0 개수
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') zeroCount ++;
        }

        int len = s.size() - zeroCount; // 0제거 후 길이

        //이진 변환 결과
        string result = "";
        while(len > 0){
            if(len % 2 == 0) result += '0';
            else result += '1';
            len /= 2;
        }
        reverse(result.begin(), result.end());
        s = result;
        
        count ++;
        zeroSum += zeroCount;
    }
    return {count, zeroSum};
}
