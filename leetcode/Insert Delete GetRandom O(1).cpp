class RandomizedSet {
    unordered_set<int>s;
public:
    /** Initialize your data structure here. */
    RandomizedSet() 
    {
    }
    
    bool insert(int val) 
    {
        return s.insert(val).second;  
    }
    
    bool remove(int val) 
    {
        if(s.erase(val))
        {
            return 1;
        }
        
        return 0;
    }
    
    int getRandom() 
    {
        int a = (int)s.size();
        
        int n = rand() % a;  
        
        auto it = s.begin();
        while(n--)
        {
            it++;
        }
        return *it;
    }
};