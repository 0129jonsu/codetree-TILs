#include <iostream>

using namespace std;

void f1(int cnt){
    if(cnt == 0) return;
    f1(cnt - 1);
    cout << cnt << " ";
}

void f2(int cnt){
    if(cnt == 0) return;
    cout << cnt << " ";
    f2(cnt - 1);
}

int main() {
    int n;
    cin >> n;

    f1(n);
    cout << "\n";
    f2(n);

    return 0;
}