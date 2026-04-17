class MedianFinder {
  priority_queue<int> maxq; // 默认大根堆
  priority_queue<int, vector<int>, greater<int>> minq;

  // 对顶堆，小根堆的最小元素大于大根堆的最大元素

public:
  MedianFinder() {}

  void addNum(int num) {
    maxq.push(num);
    minq.push(maxq.top());
    maxq.pop();
    if (minq.size() > maxq.size() + 1) {
      maxq.push(minq.top());
      minq.pop();
    }
  }

  double findMedian() {
    if (minq.size() > maxq.size())
      return minq.top();
    return (minq.top() + maxq.top()) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
