#include <iostream>

using namespace std;

int arr[11];


int f(int a, int b){
    int r = a % b;
    if(r == 0) return b;
    else return f(b,r);
}

int main() {
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ans = arr[0];

    for(int i = 1; i < n; i++){
        ans = ans * arr[i] / f(ans, arr[i]);
    }

    cout << ans;

    return 0;
}