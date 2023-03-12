#include <iostream>
#include <string>
#include <gmpxx.h>

using namespace std;

void validate(string n) {
    if(n.length() == 0) throw 2; // empty parameter case : ""
    else if(n.length()>0 && n[0] == '-') throw 3;
    for (int i = 0; i < n.length(); i++) {
        if(!isdigit(n[i])) throw 4; // invalid cases : "+2" or "0xA" or "1,2" or "3.4" or "5.6e+07" ...
    }
}

string dec2bin(string n) {    
    mpz_class mpz_n;
    mpz_n.set_str(n, 10); // used instead of mpz_n(n) to avoid octal notation, i.e. numbers starting with one or more zeros : "016" ...
    if(mpz_n == 0) return "0"; // zero cases : "0" or "00" ...
    n = "";
    while (mpz_n > 0) {
        n += (mpz_n % 2) == 0 ? "0" : "1";
        mpz_n = mpz_n / 2;
    }
    reverse(n.begin(), n.end());
    return n;
}

int main(int argc, char *argv[]) {
    try
    {
        if(argc > 1) {
            validate(argv[1]);
            cout << dec2bin(argv[1]) << endl;
        } else {
            throw 1;
        }
    } catch (int e) {
        cout << "An exception occurred. (Exception number: " << e << ")" << endl;
        cout << "Usage : " << argv[0] << " <number consisting of digits only>" << endl;
        return e;
    }
    return 0;
}
