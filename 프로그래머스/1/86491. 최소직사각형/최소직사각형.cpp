#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0, maxW = 0, maxH = 0;
    
    for(int i=0; i<sizes.size(); i++){
        int w = sizes[i][0];
        int h = sizes[i][1];
        
        if(w < h) {
            int idx = w;
            w = h;
            h = idx;
        }
        
        if(maxW < w) maxW = w;
        if(maxH < h) maxH = h;
    }
    answer = maxW * maxH;
    
    return answer;
}