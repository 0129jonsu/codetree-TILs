#include <iostream>

using namespace std;

int arr[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
string months[7] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
int ans= 0;
int main() {
    int m1, m2, d1, d2;
    int idx = 0;
    string mon = "";
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> mon;

    while(m1 != m2 || d1 != d2){
        if (months[idx] == mon) ans++;
        idx++;
        if(idx == 7) idx = 0;
        if(arr[m1] == d1){
            d1 = 1;
            m1++;
            continue;
        }
        d1++;
    }

    cout << ans;
    return 0;
}