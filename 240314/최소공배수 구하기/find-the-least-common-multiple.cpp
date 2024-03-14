#include <iostream>

using namespace std;

int f(int a, int b){
    int r = a % b;
    if(r == 0) return b;
    else return f(b, r);
}

int main() {
    int n, m;

    cin >> n >> m;

    cout << n * m / f(n, m);

    return 0;
}