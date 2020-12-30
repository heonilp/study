class NestedIterator {
public:
    vector<int>v;
    int index;
    
    NestedIterator(vector<NestedInteger>&nestedList)
    {
        go(nestedList);
        index=0;
    }
    
    void go(vector<NestedInteger>&nestedList)
    {
        for(int i=0;i<nestedList.size();i++)
        {
            if(nestedList[i].isInteger())
            {
                v.push_back(nestedList[i].getInteger());
            }
            else
            {
                go(nestedList[i].getList());
            }
        }
    }
    
    int next()
    {
        return v[index++];
    }
    
    bool hasNext()
    {
        int rsize =v.size();
        return index!=rsize;
    }
};