#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        sort(v.begin(), v.end());
        if(i % 2 == 0) cout << v[i/2] << " ";
    }

    return 0;
}