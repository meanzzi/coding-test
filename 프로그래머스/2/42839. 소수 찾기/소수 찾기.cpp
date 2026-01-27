#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> result;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i =2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

void dfs(string cur, string numbers, vector<bool> &used){
    if(!cur.empty()){
        int n = stoi(cur);
        if(isPrime(n)) result.insert(n);
    }
    for(int i=0; i<numbers.size(); i++){
        if(!used[i]){
            used[i] = true;
            dfs(cur+numbers[i], numbers, used);
            used[i] =false;
        }
    }
}

int solution(string numbers) {
    vector<bool> used(numbers.size(), false);
    
    dfs("", numbers, used);
    return result.size();
}