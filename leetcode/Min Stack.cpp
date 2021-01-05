struct st_Node
{
    int value;
    int min;
    st_Node* next;
    
    st_Node(int value) 
    {
        this->value=value;
        this->min=value;
        next=nullptr;
    }
};

class MinStack 
{
public:
    st_Node* head;
    
    MinStack() 
    {
        head = nullptr;
    }
    
    void push(int x) 
    {
        st_Node* newnode = new st_Node(x);
        
        if(head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode->min = min(head->min, newnode->min);
            newnode->next = head;
            head = newnode;
        }
    }
    
    void pop()
    {
        st_Node* removeNode = head;
        head = head->next;
        delete(removeNode);
    }
    
    int top() 
    {
        if(head == nullptr)
        {
            return INT_MIN;
        }
        else
        {
            return head->value;
        }
    }
    
    int getMin() 
    {
        if(head == nullptr) 
        {
            return INT_MIN;
        }
        else
        {
            return head->min;
        }
    }
};