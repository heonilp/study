class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==nullptr) return {} ;
        vector<vector<int> > v;
        vector<int> r;
        queue<TreeNode*> q;
        q.push(root);
        
        int cnt=1;
        
        while(!q.empty())
        {
            if(q.front()->left!=nullptr)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right!=nullptr)
            {
                q.push(q.front()->right);
            }
            
            r.push_back(q.front()->val);
            q.pop();
            
            cnt--;
            
            if(cnt==0)
            {
                cnt=q.size();
                v.push_back(r);
                r.clear();
                
            }
        }
        return v;
    }
};