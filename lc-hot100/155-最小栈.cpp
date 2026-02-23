class MinStack {
  stack<int> number;
  stack<int> minVal;

public:
  MinStack() {}

  void push(int val) {
    number.push(val);
    if (!minVal.empty())
      minVal.push(min(val, minVal.top()));
    else
      minVal.push(val);
  }

  void pop() {
    if (number.empty() || minVal.empty())
      return;
    number.pop();
    minVal.pop();
  }

  int top() { return number.top(); }

  int getMin() { return minVal.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
