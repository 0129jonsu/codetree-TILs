#include <iostream>

using namespace std;

int n;
long long arr[36];

long long f(int a) {
    if (arr[a] != 0) return arr[a];
    else {
        for (int i = 0; i < a; i++) {
            arr[a] += f(i) * f(a - i - 1);
        }
    }
    return arr[a];
}

int main() {
    cin >> n;
    arr[0] = 1;
    f(n);
       
    cout << arr[n];

    return 0;
}