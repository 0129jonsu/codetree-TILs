#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> v;

int main() {
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string tmp = "";
        getline(cin, tmp);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(v[i].find("Rain") != string::npos){
            cout << v[i];
            break;
        }
    }

    return 0;
}