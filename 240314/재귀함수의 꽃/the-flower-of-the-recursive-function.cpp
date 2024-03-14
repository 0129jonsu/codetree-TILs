#include <iostream>

using namespace std;

void f(int cnt){
    if(cnt == 0) return;
    cout << cnt << " ";
    f(cnt -1);
    cout << cnt << " ";
}

int main() {
    int N;
    cin >> N;

    f(N);

    return 0;
}