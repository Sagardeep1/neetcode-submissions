class MedianFinder {

    priority_queue<int> pq_desc;
    priority_queue<int,vector<int>,greater<int>> pq_asc;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq_desc.size() == 0) {
            pq_desc.push(num);
            return;
        }
        if(num <= pq_desc.top()) {
            pq_desc.push(num);
        }
        else pq_asc.push(num);
        if(pq_desc.size() - pq_asc.size() == 2) {
            int ele = pq_desc.top();
            pq_desc.pop();
            pq_asc.push(ele);
        }
        else if(pq_asc.size() - pq_desc.size() == 1) {
            int ele = pq_asc.top();
            pq_asc.pop();
            pq_desc.push(ele);
        }
        return;
    }
    
    double findMedian() {
        double ans;
        if(pq_asc.size() == pq_desc.size())
            ans = (double)(pq_asc.top() * 1.0 + pq_desc.top() * 1.0)/2.0;
        else
            ans = pq_desc.top() * 1.0;
        return ans;
    }
};
