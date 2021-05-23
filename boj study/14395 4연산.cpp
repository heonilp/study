#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;
//98765432 
//연산의 아스키 코드 순서는 '*', '+', '-', '/' 이다.
//값을 얼마나잡아야되는거지..
#define IMT 10000000000

struct st_hi
{
    long long a;
    string s;
};

long long s;
long long t;
set<long long> s_ck; // 중복X
queue<st_hi> que;


void BFS()
{
    while (!que.empty())
    {
          
        struct st_hi go = que.front();
        
        long long Goal = go.a;
        string str = go.s;    
   
        que.pop();
        
        if (Goal == t) 
        {
            if (str.length() == 0) 
            {
                str = "0"; //s와 t가 같은 경우에는 0을
                cout << str << endl;
                 return;
            }
            else
            {
                cout << str << endl;         
                return;
            }
          
        }
        
        if (0 <= Goal*Goal && Goal*Goal<= IMT && s_ck.count(Goal*Goal) == 0)
        {
            struct st_hi putdata;
            putdata.a = Goal*Goal;
            putdata.s = str+"*";
            que.push(putdata);
            s_ck.insert(putdata.a);
        }

        
        if (0 <= Goal+Goal && Goal+Goal <= IMT && s_ck.count(Goal+Goal) == 0) 
        {    
            struct st_hi putdata;
            putdata.a = Goal+Goal;
            putdata.s = str+"+";
            que.push(putdata);
            s_ck.insert(putdata.a);
        }
        if (0 <= Goal-Goal && Goal-Goal <= IMT && s_ck.count(Goal-Goal) == 0)
        {
            
            struct st_hi putdata;
            putdata.a = Goal-Goal;
            putdata.s = str+"-";
            que.push(putdata);
            s_ck.insert(putdata.a);
        }
        
        

        if (Goal != 0 && 0 <= Goal/Goal&& Goal/Goal <= IMT && s_ck.count(Goal/Goal) == 0)
        {

            struct st_hi putdata;
            putdata.a = Goal/Goal;
            putdata.s = str+"/";
            que.push(putdata);
            s_ck.insert(putdata.a);
            
        }
    }
    
    printf("-1\n"); //다를 경우
    
}

int main() 
{
    cin >> s >> t;

    st_hi go;
    
    go.a = s;
    go.s = "";
    
    que.push(go);
    s_ck.insert(s);

    BFS();
    
    
    return 0;
    
}