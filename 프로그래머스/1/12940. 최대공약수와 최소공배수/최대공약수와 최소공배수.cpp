#include <string>
#include <vector>

using namespace std;

int GCD(int n, int m){
    if(m == 0) return n;
    else return GCD(m, n%m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(GCD(n,m));
    
    int LCM = n / GCD(n,m) * m; //오버플로우 막으려고 먼저 나누기
    answer.push_back(LCM);
    return answer;
}