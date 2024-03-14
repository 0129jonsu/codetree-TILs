#include <iostream>

using namespace std;

int a, b;
void f(){
    if(a > b){
        a *= 2;
        b += 10;
    }
    else if(a < b){
        a += 10;
        b *= 2;
    }
}

int main() {
    cin >> a >> b;
    f();
    cout << a << " " << b;

    return 0;
}