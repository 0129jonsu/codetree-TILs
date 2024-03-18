#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(0);

    for(int i = 0 ; i < n; i++){
        string tmpstr;
        cin >> tmpstr;
        if(tmpstr == "push_back"){
            int tmpint;
            cin >> tmpint;
            v.push_back(tmpint);
        }
        if(tmpstr == "pop_back") v.pop_back();
        if(tmpstr =="size") cout << v.size()-1 << "\n";
        if(tmpstr =="get"){
            int tmpint;
            cin >> tmpint;
            cout << v[tmpint] << "\n";
        }
    }
    
    return 0;
}