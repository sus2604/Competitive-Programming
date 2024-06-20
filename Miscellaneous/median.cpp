// median PQ / using multiset


class MedianFinder {
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
public:
    void addNum(int x) {
        if(right.size()>0 and x>right.top()) right.push(x);
        else left.push(x);

        if(left.size()-right.size()==2){
            right.push(left.top());
            left.pop();
        }
        else if(right.size()-left.size()==2){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()) return left.top();
        else if(right.size()>left.size()) return right.top();
        return (left.top()+right.top())/2.0;
    }
};


// rolling median


class MedianFinder {
    multiset<double> left,right;
public:
    void balance(){
        if(left.size()-right.size()==2){
            auto it=left.rbegin();
            right.insert(*it);
            left.erase(left.find(*it));
        }
        else if(right.size()-left.size()==2){
            auto it=right.begin();
            left.insert(*it);
            right.erase(right.find(*it));
        }
    }
    void addNum(int x) {
        if(!right.empty() and x>*right.begin()){
            right.insert(x);
        }
        else left.insert(x);

        balance();
    }
    void remove(int x){
        auto left_find=left.find(x);
        auto right_find=right.find(x);

        if(left_find!=left.end()) left.erase(left_find);
        else right.erase(right_find);
        balance();
    }
    
    double findMedian() {
        if(left.size()>right.size()) return *left.rbegin();
        else if(right.size()>left.size()) return *right.begin();
        return (*left.rbegin()+*right.begin())/2.0;
    }
};
