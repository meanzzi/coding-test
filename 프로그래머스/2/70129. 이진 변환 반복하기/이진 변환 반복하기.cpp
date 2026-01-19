// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> solution(string s) {
//     vector<int> answer;
//     int change = 0, zeroSum = 0;
    
//     while(s != "1"){
//         int zero = 0; 
        
//         for(int i=0; i<s.size(); i++){
//             if(s[i] == '0') {
//                 zero ++;
//             }
//         }
//         zeroSum += zero;
        
//         int ten = s.size() - zero; // 0초기화 필요
        
//         string two = ""; //문자열 초기화
        
//         while(ten > 0){
//             two += (ten % 2) + '0';
//             ten = ten / 2;         
//         }
        
//         reverse(two.begin(), two.end());
//         change ++;
//         s = two;
//     }
//     answer.push_back(change);
//     answer.push_back(zeroSum);
        
//     return answer;
// }

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int change = 0;
    int zeroSum = 0;

    while (s != "1") {
        int zeroCount = 0;

        // 1. 0의 개수 세기
        for (char c : s) {
            if (c == '0') zeroCount++;
        }

        zeroSum += zeroCount;

        // 2. 0 제거 후 남은 길이
        int len = s.size() - zeroCount;

        // 3. 길이를 2진수로 변환 (문자열 생성 X)
        string next = "";
        while (len > 0) {
            next = (len % 2 ? "1" : "0") + next;
            len /= 2;
        }

        s = next;
        change++;
    }

    return {change, zeroSum};
}
