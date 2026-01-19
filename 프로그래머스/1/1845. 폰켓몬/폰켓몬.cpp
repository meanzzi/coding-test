#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    map<int, int> mp;
    
    for(int i=0; i<n; i++){
        int number = nums[i]; // 포켓몬 번호
        mp[number]++;
    }
    if(mp.size() >= n/2) answer = n/2;
    else answer = mp.size();
    
    return answer;
}