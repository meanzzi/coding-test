#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(); //행
    int m = maps[0].size(); // 열
    
    int dx[] = {-1, 1, 0, 0}; //상하좌우
    int dy[] = {0, 0, -1, 1}; 
    
    queue<pair<int, int>> q; //y,x 담을 큐
    q.push({0,0}); //시작점 넣기
    
    while(!q.empty()){
        // 큐 맨 앞 데이터 꺼내기
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){ //4방향 탐색
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            // 맵 범위 체크
            if(ny >= 0 && ny < n && nx>=0 && nx < m){
                if(maps[ny][nx] == 1){ //방문하지 않은 길이라면
                    maps[ny][nx] = maps[y][x]+1;
                    q.push({ny,nx});
                }
            }
        }
    }
    answer = maps[n-1][m-1];
    if(answer == 1) return -1;
    else  return answer;
}