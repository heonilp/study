int combination(int n, int r)
{
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}


bool solve(string s)
{
    stack<char> temp;
    map<char, char> p = { {'(', ')'}, {'{', '}'}, {'[', ']'} ,{'<', '>'}};

    
    for(char c : s)
    {
        cnt++;
        
        if(p.find(c) != p.end())
        {
            temp.push(c);
        }
        else
        {
           
            if(temp.empty() == true)
            {
                return false;
            }
            else if(c == p[temp.top()])
            {
              
                temp.pop();
            }
            else
            {
               
                return false;
            }
        }
        
       
    }
    
    if( temp.empty())
    {
        return true;
    }
    else
    {
    
        return false;
    }
  
   
}
