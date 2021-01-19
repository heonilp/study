class Solution {
public:
    
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            Node* p = nullptr;
            
            for(int i=0; i<n; i++)
            {
                Node* c = q.front();
                q.pop();
                if(p)  p->next = c;
                p = c;
                
                if(c->left)  q.push(c->left);
                if(c->right)  q.push(c->right);
            }
        }
        return root;
    }
};