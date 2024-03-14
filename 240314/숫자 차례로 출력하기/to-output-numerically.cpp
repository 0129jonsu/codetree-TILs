#include <iostream>

using namespace std;

int n;

void f1(int cnt){
    cout << cnt << " ";
    if(cnt == n) return;
    f1(cnt + 1);
}

void f2(int cnt){
    cout << cnt << " ";
    if(cnt == 1) return;
    f2(cnt - 1);
}

int main() {
    cin >> n;

    f1(1);
    cout << "\n";
    f2(n);

    return 0;
}