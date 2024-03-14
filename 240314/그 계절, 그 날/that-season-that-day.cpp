#include <iostream>

using namespace std;

int arr[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31 ,30, 31 , 30, 31};
string w[13] ={"","Winter","Winter","Spring","Spring","Spring","Summer","Summer","Summer","Fall","Fall","Fall","Winter"};
bool check(int year){
    if(year % 400 == 0) return true;
    else if (year % 4 == 0){
        if(year % 100 == 0) return false;
        else return true;
    }
    else return false;
}

int main() {
    int y, m ,d;
    cin >> y >> m >> d;

    if(m == 2 && check(y)){
        arr[2] = 29;
    }
    else arr[2] = 28;

    if(arr[m] < d || d < 0) cout << -1;
    else cout << w[m];
    
    return 0;
}