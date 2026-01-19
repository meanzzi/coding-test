#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int left=0, right=0, sum=0;
    int n = sequence.size();
    int Min = n+1;
    
    while(right < n){
        sum += sequence[right];
        
        while(sum > k){ //합이 크다면 범위 줄여야함
            sum -= sequence[left];
            left ++;
        }
        
        if(sum == k) {
            int len = right - left;
            if(len < Min) {
                Min = len;
                answer = {left, right};
            }
            
        }
        right ++;
    }    
    
    return answer;
}