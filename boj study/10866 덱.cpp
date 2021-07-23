#include <bits/stdc++.h>
#include  <iostream>
using namespace std;
 
int n;
int main()
{
    string s;
    cin>>n;
    deque<int> q;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        if(s=="push_back"){
            int x;
            cin>>x;
            q.push_back(x);
        }else if(s=="push_front"){
            int x;
            cin>>x;
            q.push_front(x);
        }else if(s=="pop_front"){
            cout<<(q.empty()?-1:q.front())<<endl;
            if(!q.empty())q.pop_front();
        }else if(s=="pop_back"){
            cout<<(q.empty()?-1:q.back())<<endl;
            if(!q.empty())q.pop_back();
        }else if(s=="size"){
            cout<<q.size()<<endl;
        }else if(s=="empty"){
            cout<<q.empty()<<endl;
        }else if(s=="front"){
            cout<<(q.empty()?-1:q.front())<<endl;
        }else if(s=="back"){
            cout<<(q.empty()?-1:q.back())<<endl;
        }
       
    }
    
    return 0;
}