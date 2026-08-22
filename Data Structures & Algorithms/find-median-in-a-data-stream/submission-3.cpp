class MedianFinder {
public:
    priority_queue<int> maxHeap; //for the smaller half, max on top
    priority_queue<int, vector<int>, greater<int>> minHeap; //for the larger half, min on top
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        //resizing so that size diff should not differ more than 1
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()+1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int n = maxHeap.size(), m = minHeap.size();
        if(n == m){
            return (double)(maxHeap.top()+minHeap.top())/2;
        } else if(n > m){
            return (double)maxHeap.top();
        } else return (double) minHeap.top();

    }
};
