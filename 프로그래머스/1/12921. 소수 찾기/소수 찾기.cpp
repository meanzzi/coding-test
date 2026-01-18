#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> check(n+1, true); // 소수 아니면 false
    
    check[0] = check[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(check[i]){
            for(int j = i*i; j<=n; j+=i){
                check[j] = false;
            }
        }
    }
    
    for(int i=2; i<=n; i++){
        if(check[i]) answer++;
    }
    
    return answer;
}