#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[1000][1000], arr[1000][1000];
bool visited[1000][1000];

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};


int mazeBFS(int sX, int sY){
	for (int i = 1; i <= 100; ++i) {
        fill_n(d[i], 1001, 0);
        fill_n(visited[i], 1001, false);
    }

    queue<pair<int, int>> maze;
    maze.push({sX, sY});
    visited[sX][sY] = true;

    while(!maze.empty()){
        int keyX = maze.front().first;
        int keyY = maze.front().second;
        maze.pop();

        if(keyX == n || keyX == 1 || keyY == m || keyY == 1) return d[keyX][keyY] + 1;

        for(int i = 0; i <  4; i++){
            int u = keyX + moveX[i];
            int v = keyY + moveY[i];
            if(u > n || u < 1) continue;
            if(v > m || v < 1) continue;

            if(!visited[u][v]){
                if(arr[u][v] == 0){
                    d[u][v] = d[keyX][keyY] + 1;
                    visited[u][v] = true;
                    maze.push({u, v});
                }
            }
        }
    }
    return -1;
}
int main(){
    int r, c;
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    cout << mazeBFS(r, c);
    return 0;
}