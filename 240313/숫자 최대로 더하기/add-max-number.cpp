#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<double> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        double tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    double sum = 0;
    for(int i = 0; i < n-1; i++){
        sum += v[i];
    }

    sum /= 2.0;

    cout.precision(1);
    cout << fixed << v[n-1] + sum;

    return 0;
}