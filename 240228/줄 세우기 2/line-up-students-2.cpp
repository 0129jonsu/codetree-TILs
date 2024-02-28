#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int N;
vector<tuple<int,int,int>> v;

bool cmp(tuple<int,int,int> &v1, tuple<int,int,int> &v2){
    if(get<0>(v1) == get<0>(v2)) return get<1>(v1) > get<1>(v2);
    return get<0>(v1) < get<0>(v2);
}


int main() {
    cin >> N;

    for(int i = 1; i <= N; i++){
        int h, w;
        cin >> h >> w;
        v.push_back(make_tuple(h,w,i));
    }
    
    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), cmp);

        for(int i = 0; i < N; i++){
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << "\n";
    }

    return 0;
}