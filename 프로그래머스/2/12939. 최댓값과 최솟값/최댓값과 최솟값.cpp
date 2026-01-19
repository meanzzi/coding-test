#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string num;
    vector<int> nums;
    
    while(getline(ss, num, ' ')){
        nums.push_back(stoi(num));
    }
    
    sort(nums.begin(), nums.end());
    int MIN = nums.front();
    int MAX = nums.back();
 
    string mins = to_string(MIN);
    string maxs = to_string(MAX);
    answer = mins + " " + maxs;
    
    return answer;
}