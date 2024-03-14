#include <iostream>

using namespace std;

int arr[11];
int w[60];
int cnt = 0;

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
        ans *= arr[i];
    }

    int now = arr[0];

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            w[cnt] = f(arr[i], arr[j]);
            cnt++;
        }
    }


    for(int i = 0; i < cnt; i++){
        ans /= w[i];
    }

    cout << ans;

    return 0;
}