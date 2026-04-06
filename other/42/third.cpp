#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (!isalpha(s[i]))
            continue;
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (s[i] == 'a')
                s[i] = 'z';
            else
                s[i]--;
        } else {
            if (s[i] == 'A')
                s[i] = 'Z';
            else
                s[i]--;
        }
    }
    cout << s;
}
