#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    vector<int> check(201, 0); //음수 값 없어서 
    for(int i = lines[0][0]; i<lines[0][1]; i++){
        check[i+100]++;
    }
    for(int i = lines[1][0]; i<lines[1][1]; i++){
        check[i+100]++;
    }
    for(int i = lines[2][0]; i<lines[2][1]; i++){
        check[i+100]++;
    }

    for(int i = 0; i<=200; i++){
        if(check[i] >= 2) answer++;
    }
    
    return answer;
}