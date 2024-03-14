#include <iostream>

using namespace std;

int n;

void f(int cnt){
    if(cnt == 0) return;
    cout << "HelloWorld" << "\n";
    f(cnt-1);
}

int main() {
    cin >> n;
    f(n);    
    return 0;
}