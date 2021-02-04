class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (v.empty()) v.push_back(num);
        else v.insert(lower_bound(v.begin(), v.end(), num), num); 
    }
    
    double findMedian() {
        int n = v.size();
        double res = n & 1 ? v[n / 2] : ((double) v[n / 2 - 1] + v[n / 2]) * 0.5;
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */