#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() == 1){
        arr.pop_back();
        arr.push_back(-1);
        return arr;
    }
    
    int min = arr[0], idx = 1;
    for(int i = 1; i<arr.size(); i++){
        if(min > arr[i]) {
            min = arr[i];
            idx = i;   
        }
    }
    arr.erase(arr.begin() + idx);
    
    return arr;
}