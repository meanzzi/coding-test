#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> campus(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> campus[i][j];
		}
	}

	int count = 0;
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0,0,1,-1 };

	queue<pair<int, int>> q; // 좌표를 저장할 BFS 큐
	vector<vector<bool>> visited(n, vector<bool>(m, false)); // 방문을 확인할 벡터
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (campus[y][x] == 'I') {
				q.push({ x,y }); //시작점 넣기
				visited[y][x] = true;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); //현재위치
		q.pop();

		for (int i = 0; i < 4; i++) {
			//상하좌우 탐색
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			//조건 체크
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위체크
			if (visited[ny][nx]) continue; // 방문 체크
			if (campus[ny][nx] == 'X') continue; // 벽 체크

			//조건 만족하면
			visited[ny][nx] = true;
			q.push({ nx, ny });
			if (campus[ny][nx] == 'P') count++;
			
			/*if (ny < n && ny >= 0 && nx < m && nx >= 0) {
			 if (visited[ny][nx] == false) {  
				 if (campus[ny][nx] != 'X') {  
					 visited[ny][nx] = true; q.push({ nx, ny }); 
					 if (campus[ny][nx] == 'P') count++; 
				 } 
			 } 
			}*/
		}

	}

	if (count == 0) cout << "TT";
	else cout << count;

	return 0;
}