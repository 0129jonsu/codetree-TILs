#include <iostream>
#include <queue>

using namespace std;

int N, T;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans = 0;

int map[100][100];
string command;

int main() {
    cin >> N >> T;
    cin >> command;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    int curr_x = N/2;
    int curr_y = N/2;
    int d = 3;
    ans += map[curr_y][curr_x];
    int next_x = curr_x;
    int next_y = curr_y;

    for(int i = 0; i < T; i++){
        if(command[i] == 'L'){
            if(d == 0) d = 3;
            else d--;
        }
        else if(command[i] == 'R'){
            if(d == 3) d = 0;
            else d++;
        }
        else if(command[i] == 'F'){
            if(next_x+dx[d] < 0 || next_y+dy[d] < 0 || next_x+dx[d] >= N || next_y+dy[d] >= N) continue;
            else{
                next_x = next_x+dx[d];
                next_y = next_y+dy[d];
                ans += map[next_y][next_x];
            }
        }
    }

    cout << ans;

    return 0;
}

// 초기상태: 정중앙에서 북쪽을 향한 상태 l = 1;
// L = 왼쪽 90도,
// R = 오른쪽 90도,
// F = 직진