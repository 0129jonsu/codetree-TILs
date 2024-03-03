#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string str;
string a = "";
string b = "";
bool checkDot = false;

int main() {

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            checkDot = true;
            continue;
        }
        if (!checkDot)a += str[i];
        else {
            b += str[i];
        }
    }
    unsigned int ai = stoi(a);
    const int n = 8;
    string bit_1 = bitset<n>(ai).to_string();
    bit_1 = bit_1.substr(bit_1.find('1'));
    
    string bit_2 = "";

    double bi = stod(b);
    while(bi > 1){
        bi/=10;
    }

    for(int i = 0; i < 4; i++){
        bi *= 2;
        if(bi > 1){
            bi -= 1;
            bit_2 += "1";
        }
        else if(bi < 1)bit_2 += "0";
        else {
            bit_2 += "1";
            break;
        }
    }
    
    
    cout << bit_1 << "." << bit_2;
;
    return 0;
}