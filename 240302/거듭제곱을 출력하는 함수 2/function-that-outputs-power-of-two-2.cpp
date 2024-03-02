#include <iostream>

using namespace std;

int a, b;

int f1(int p,int q) {
    if (q == 1) return p;
    return f1(p * a, q - 1);
}
int f2(int p, int q) {
    if (q == 1) return p;
    return f2(p * b, q - 1);
}

int main() {
    cin >> a >> b;

    int tmp1 = f1(a, b);
    int tmp2 = f2(b, a);

    if (tmp1 >= tmp2) cout << tmp1 - tmp2;
    else cout << tmp2 - tmp1;

    return 0;
}