#include <iostream>
#include <vector>

using namespace std;

int N;
int ans = 1;
vector<int> v;

int main() {
    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back(tmp2);
    }
    int preS = v[N-1];
    for(int i = N-2; i >= 0; i--){
        if(preS < v[i]) continue;
        else ans++;
        preS = v[i];
    }

    cout << ans;

    return 0;
}