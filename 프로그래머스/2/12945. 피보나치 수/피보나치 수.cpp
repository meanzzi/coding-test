#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    const int MOD = 1234567;
    vector<int> f(n+1);
    
    f[0] = 0, f[1] = 1;
    for(int i=2; i<=n; i++){
        f[i] = (f[i-1] + f[i-2]) % MOD;
    }
    
    
    return f[n];
}