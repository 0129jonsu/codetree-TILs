#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int black = 0;
    int white = 0;
    for(int i = 0; i < n; i++){
        int tmp1;
        char tmp2;
        cin >> tmp1 >> tmp2;

        if(tmp2 == 'R'){
            black += tmp1;
            white -= tmp1;
        }
        else{
            black -= tmp1;
            white += tmp1;
        }

        if(black < 0) black = 0;
        if(white < 0) white = 0;
    }

    cout << white << " "<< black;

    return 0;
}