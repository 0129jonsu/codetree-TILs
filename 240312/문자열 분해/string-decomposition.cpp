#include <iostream>
#include <queue>

using namespace std;

string str;
queue<int> q;
int ans = 0;
int idx = 1;
bool check = false;

char ap[5] = { 'a','b','c','d','e' };

int main() {
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '\0') continue;
        if (str[i] != 'a') {
            check = true;
            break;
        }
        idx = 1;
        str[i] = '\0';
        for (int j = i+1; j < str.size(); j++) {
            if (str[j] == ap[idx]) {
                idx++;
                q.push(j);
            }
            if (idx == 5) {
                idx = 0;
                while (!q.empty()) {
                    str[q.front()] = '\0';
                    q.pop();
                }
            }
        }
        if (idx == 0) ans++;
        else {
            check = true;
            break;
        }
    }

    if (check) cout << -1;
    else cout << ans;

    return 0;
}