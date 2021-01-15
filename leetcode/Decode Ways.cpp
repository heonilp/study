class Solution {
public:
  int numDecodings(string s) {

    if (s.size() == 0) 
    {
		return 0;
	}
        
    if(s[0] == '0')
    {
        return 0;
    }
        
  
	int num1;
	int num2;
        
	int ss = 1;
	int sum = 1; 

        
        
	int temp;

	for (int i = 1; i < s.size(); i++)
    {
		temp = 0;

		num1 = s[i] - '0';
        
		if (num1 > 0 && num1 < 10) 
        {
			temp = sum;
		}

		num2 = stoi(s.substr(i - 1, 2));
		
        if (num2 >= 10 && num2 <= 26) 
        {
			temp += ss;
		}
		ss = sum;
		sum = temp;
	}

	return sum;
   }
};