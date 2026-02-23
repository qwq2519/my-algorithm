class Solution {
  int n, i;

public:
  string decodeString(string s) {
    n = s.size();
    i = 0;
    //    return parse(s);
    return decodeWithStack(s);
  }

  string parse(string &s) {
    string out;
    while (i < n && s[i] != ']') {
      if (isalpha(s[i])) {
        out.push_back(s[i++]);
      } else {
        int num = 0;
        while (i < n && isdigit(s[i])) {
          num = num * 10 + s[i] - '0';
          i++;
        }
        i++; // skip [
        string inner = parse(s);
        i++; // skip ]
        while (num--)
          out += inner;
      }
    }
    return out;
  }

  string decodeWithStack(string s) {
    stack<pair<string, int>> st;
    string cur;
    int num = 0;

    for (char c : s) {
      if (isdigit(c)) {
        num = num * 10 + c - '0';
      } else if (isalpha(c)) {
        cur.push_back(c);
      } else if (c == '[') {
        st.push({cur, num});
        cur.clear();
        num = 0;
      } else { // ']'
        auto [prev, k] = st.top();
        st.pop();
        string rep;
        rep.reserve(cur.size() * k);
        while (k-- > 0)
          rep += cur;
        cur = prev + rep;
      }
    }
    return cur;
  }
};
