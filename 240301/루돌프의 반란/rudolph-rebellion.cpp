#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, P, C, D;
int rr, rc;
int map[51][51];
int score[31] = { 0, };

int dxR[8] = { 0,1,-1,0,1,-1,1,-1 };
int dyR[8] = { 1,0,0,-1,1,1,-1,-1 };

int dxS[4] = { 0,1,0,-1 };
int dyS[4] = { -1,0,1,0 };


class santas {
public:
    int num;
    int r;
    int c;
    int score;
    bool alive;
    int stun;

    void setInfo(int _num, int _r, int _c) {
        num = _num;
        r = _r;
        c = _c;
        score = 0;
        alive = true;
        stun = 0;
    }
};
vector<santas> v;

bool cmp(santas& v1, santas& v2) {
    return v1.num < v2.num;
}

bool visited[51][51];
pair<int, int> rL;
queue<pair<int, int>> q;

void initVisited() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = false;
        }
    }
}

bool checkEnd() {
    for (int q = 1; q <= P; q++) {
        if (v[q].alive) return false;
    }
    return true;
}

void interaction(int r, int c, int dr, int dc, int sNum) {
    if (r + dr <= 0 || r + dr > N || c + dc <= 0 || c + dc > N) {
        v[map[r][c]].alive = false;
        return;
    }

    else if (map[r + dr][c + dc] != 0) {
        interaction(r + dr, c + dc, dr, dc, map[r + dr][c + dc]);
        map[r + dr][c + dc] = sNum;
        v[sNum].r = r + dr;
        v[sNum].c = c + dc;
    }

    else if (map[r + dr][c + dc] == 0) {
        map[r + dr][c + dc] = sNum;
        v[sNum].r = r + dr;
        v[sNum].c = c + dc;
    }
    map[r - dr][c - dc] = 0;

}

void rMove(int r, int c) {
    initVisited();
    int calC = 0;
    int calR = 0;
    while (!q.empty()) q.pop();
    q.push({ r, c });
    visited[r][c] = true;

    while (!q.empty()) {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int next_r = curr_r + dyR[i];
            int next_c = curr_c + dxR[i];

            if (map[next_r][next_c] > 0) {
                int minL = (r - next_r) * (r - next_r) + (c - next_c) * (c - next_c);

                for (int w = 0; w < 8; w++) {
                    int tmpR = r + dyR[w];
                    int tmpC = c + dxR[w];
                    int tmpL = (next_r - tmpR) * (next_r - tmpR) + (next_c - tmpC) * (next_c - tmpC);
                    if (tmpR <= 0 || tmpR > N || tmpC <= 0 || tmpC > N) continue;
                    if (minL > tmpL && map[tmpR][tmpC] >= 0) {
                        calR = dyR[w];
                        calC = dxR[w];
                        minL = tmpL;
                    }
                }
                while (!q.empty()) q.pop();
                break;
            }
            if (next_r > N || next_r <= 0 || next_c > N || next_c <= 0) continue;
            if (!visited[next_r][next_c] && map[next_r][next_c] == 0) {
                q.push({ next_r, next_c });
                visited[next_r][next_c] = true;
            }
        }
    }
    if (map[r + calR][c + calC] > 0) {
        v[map[r + calR][c + calC]].stun = 1;
        score[v[map[r + calR][c + calC]].num] += C;

        if (r + calR + (calR * C) <= 0 || r + calR + (calR * C) > N || c + calC + (calC * C) <= 0 || c + calC + (calC * C) > N) {
            v[map[r + calR][c + calC]].alive = false;
            map[r][c] = 0;
            map[r + calR][c + calC] = -1;
            rL = { r + calR , c + calC };
        }
        else if (map[r + calR + (calR * C)][c + calC + (calC * C)] == 0) {
            map[r + calR + (calR * C)][c + calC + (calC * C)] = map[r + calR][c + calC];
            v[map[r + calR][c + calC]].r = r + calR + calR * C;
            v[map[r + calR][c + calC]].c = c + calC + calC * C;
            map[r + calR][c + calC] = -1;
            rL = { r + calR , c + calC };
            map[r][c] = 0;
        }
        else if (map[r + calR + (calR * C)][c + calC + (calC * C)] > 0) {
            int tmpS = map[r + calR][c + calC];
            interaction(r + calR + (calR * C), c + calC + (calC * C), calR, calC, map[r + calR + (calR * C)][c + calC + (calC * C)]);
            map[r + calR + (calR * C)][c + calC + (calC * C)] = tmpS;
            v[tmpS].r = r + calR + (calR * C);
            v[tmpS].c = c + calC + (calC * C);
            map[r + calR][c + calC] = -1;
            rL = { r + calR , c + calC };
            map[r][c] = 0;

            /*            
            interaction(r + calR + (-calR * D), c + calC + (-calC * D), -calR, -calC, map[r + calR + (-calR * D)][c + calC + (-calC * D)]);
            map[r + calR + (-calR * D)][c + calC + (-calC * D)] = sNum;
            v[sNum].r = r + calR + (-calR * D);
            v[sNum].c = c + calC + (-calC * D);
            map[r][c] = 0;
            */
        }

    }
    else if (map[r + calR][c + calC] == 0) {
        map[r][c] = 0;
        map[r + calR][c + calC] = -1;
        rL = { r + calR , c + calC };
    }
}

void sMove(int r, int c, int sNum) {
    if (v[sNum].stun > 0) return;
    initVisited();
    int calC = 0;
    int calR = 0;
    while (!q.empty()) q.pop();
    q.push({ r, c });
    visited[r][c] = true;


    while (!q.empty()) {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();


        for (int i = 0; i < 4; i++) {
            int next_r = curr_r + dyS[i];
            int next_c = curr_c + dxS[i];

            if (map[next_r][next_c] == -1) {
                int minL = (r - next_r) * (r - next_r) + (c - next_c) * (c - next_c);

                for (int w = 0; w < 4; w++) {
                    int tmpR = r + dyS[w];
                    int tmpC = c + dxS[w];
                    int tmpL = (next_r - tmpR) * (next_r - tmpR) + (next_c - tmpC) * (next_c - tmpC);
                    if (tmpR <= 0 || tmpR > N || tmpC <= 0 || tmpC > N) continue;
                    if (minL > tmpL && map[tmpR][tmpC] <= 0) {
                        calR = dyS[w];
                        calC = dxS[w];
                        minL = tmpL;
                    }
                }
                while (!q.empty()) q.pop();
                break;
            }
            if (next_r > N || next_r <= 0 || next_c > N || next_c <= 0) continue;
            if (!visited[next_r][next_c]) {
                q.push({ next_r, next_c });
                visited[next_r][next_c] = true;
            }
        }
    }

    if (calR == 0 && calC == 0) return;

    if (map[r + calR][c + calC] == -1) {
        v[sNum].stun = 1;
        score[sNum] += D;
        if (r + calR + (-calR * D) <= 0 || r + calR + (-calR * D) > N || c + calC + (-calC * D) <= 0 || c + calC + (-calC * D) > N) {
            v[map[r][c]].alive = false;
        }
        else if (map[r + calR + (-calR * D)][c + calC + (-calC * D)] > 0 && map[r + calR + (-calR * D)][c + calC + (-calC * D)] != sNum) {
            interaction(r + calR + (-calR * D), c + calC + (-calC * D), -calR, -calC, map[r + calR + (-calR * D)][c + calC + (-calC * D)]);
            map[r + calR + (-calR * D)][c + calC + (-calC * D)] = sNum;
            v[sNum].r = r + calR + (-calR * D);
            v[sNum].c = c + calC + (-calC * D);
            map[r][c] = 0;
        }

        else {
            v[sNum].r = r + calR + (-calR * D);
            v[sNum].c = c + calC + (-calC * D);
            map[r + calR + (-calR * D)][c + calC + (-calC * D)] = sNum;
        }
        map[r][c] = 0;
    }

    else if (map[r + calR][c + calC] == 0) {
        v[sNum].r = r + calR;
        v[sNum].c = c + calC;
        map[r][c] = 0;
        map[r + calR][c + calC] = sNum;
    }
}

int main() {
    cin >> N >> M >> P >> C >> D;
    cin >> rr >> rc; // 루돌프 초기 위치
    rL = { rr, rc };
    map[rr][rc] = -1;
    for (int i = 0; i <= P; i++) {
        int tmpN, tmpR, tmpC;
        santas tmpSanta;
        if (i == 0) {
            tmpSanta.setInfo(-1, -1, -1);
            v.push_back(tmpSanta);
        }
        else {
            cin >> tmpN >> tmpR >> tmpC;
            tmpSanta.setInfo(tmpN, tmpR, tmpC);
            v.push_back(tmpSanta);
            map[tmpR][tmpC] = tmpN;
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int z = 1; z <= M; z++) {
        rMove(rL.first, rL.second);
        if (checkEnd()) break;
        for (int i = 1; i <= P; i++) {
            if (v[i].alive && v[i].stun == 0) sMove(v[i].r, v[i].c, v[i].num);
        }
        for (int i = 1; i <= P; i++) {
            if (v[i].alive) score[i]++;
            if (v[i].stun > 0) {
                if (v[i].stun == 2) v[i].stun = 0;
                else v[i].stun++;
            }
        }
        if (checkEnd()) break;
    }

    for (int i = 1; i <= P; i++) {
        cout << score[i] << " ";
    }

    return 0;
}