//Hard 297. Serialize and Deserialize Binary Tree

class Codec {
public:
    string serialize(TreeNode* root) 
    {
        string s = "";
        setserialize(root, s);
        return s;
    }
    void setserialize(TreeNode* root, string &s)
    {
        if(!root) 
        {
            s += "NULL,";
            return;
        }
    
        s += to_string(root->val) + ",";
        setserialize(root->left, s);
        setserialize(root->right, s);
    }   
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream s (data);
        return setdeserialize(s);
    }

    TreeNode* setdeserialize(istringstream& s) 
    {
        string token="";
        getline(s, token, ',');
    
        if(token == "NULL") return NULL;
    
        TreeNode* resNode = new TreeNode(stoi(token));
        resNode->left = setdeserialize(s);
        resNode->right = setdeserialize(s);
    
        return resNode;
    }

};