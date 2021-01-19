class LRUCache {
    
    unordered_map<int, list<pair<int,int>>::iterator> m;
    list<pair<int,int>> l;
    int temp;
public:
    LRUCache(int capacity)
    {
        temp = capacity;
    }
    
    int get(int key) 
    {
        auto it = m.find(key); ///O(1)
        
        if (it == m.end())
        {
            return -1;
        }
        //한 목록에서 다른 목록으로 요소를 전송합니다. 
        //요소는 복사 (copy) 되거나 이동(move) 되지 않으며, 목록 내의 포인터만 다시 연결될 뿐입니다.
        //std::list<int> list1{ 1,2,3,4,5 };
        //std::list<int> list2{ 10,20,30,40,50 };
        //auto it = list1.begin();
        //std::advance(it, 2);
        //list1.splice(it, list2);
        //1, 2, 10, 20, 30, 40, 50, 3, 4, 5 -> void splice( const_iterator pos, list& other )
        // 즉 it의 앞부분에 list 전체를 전송시킴
        
        l.splice(l.begin(), l, it->second); //O(1)
        return it->second->second;
    }
    
    void put(int key, int value)
    {
        
        auto it = m.find(key); ///O(1)
  
        if (it != m.end()) 
        {
            it->second->second = value;
            l.splice(l.begin(), l, it->second); //O(1)
            return;
        }
      
        l.insert(l.begin(),{key,value}); //O(1)
      
        m[key] = l.begin();
        int list_size = (int)l.size();
 
        if (list_size > temp) 
        {
            m.erase(l.back().first); //O(1)
            
            l.pop_back();
             return;
        }
         return;
    }
};

