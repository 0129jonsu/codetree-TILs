#include <iostream>

using namespace std;

int arr[101];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        int sum = 0;
        cin >> tmp1 >> tmp2;

        for(int j = tmp1-1; j <= tmp2-1; j++) sum += arr[j];
        cout << sum << "\n";
    }

    return 0;
}