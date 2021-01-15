class Solution {    
public:
    int evalRPN(vector<string>& tokens)
    {
    stack<int> numbers;
    int num1, num2;
    for(auto &it : tokens)
    {
      if(it == "+")
      {
        num2 = numbers.top();
        numbers.pop();
        num1 = numbers.top();
        numbers.pop();
        numbers.push(num1 + num2);
      }
      else if(it == "*")
      {
        num2 = numbers.top();
        numbers.pop();
        num1 = numbers.top();
        numbers.pop();
        numbers.push(num1 * num2);
      }
      else if(it == "-")
      {
        num2 = numbers.top();
        numbers.pop();
        num1 = numbers.top();
        numbers.pop();
        numbers.push(num1 - num2);
      }
      else if(it == "/")
      {
        num2 = numbers.top();
        numbers.pop();
        num1 = numbers.top();
        numbers.pop();
        numbers.push(num1 / num2);
      }
      else  numbers.push(stoi(it));
    }
    return numbers.top();
    
    }
        
};