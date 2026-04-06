#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    getline(cin, str);

    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int others = 0;

    // write your code here......
    for (char ch : str) {
        if (isdigit(ch))
            ++digits;
        else if (isalpha(ch))
            ++chars;
        else if (isblank(ch))
            ++whitespace;
        else
            ++others;
    }

    cout << "chars : " << chars << " whitespace : " << whitespace
         << " digits : " << digits << " others : " << others << endl;

    return 0;
}
