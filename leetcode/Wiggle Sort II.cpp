//1. 생각없이 풀이
class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        
        int n = nums.size();
        
        vector<int>temp(nums);
        sort(temp.begin(), temp.end());
        
        int i =  n-1;
        int j = (n-1)/2;
        int k = 0;
        
        while (k < n)
        {
            if (k & 1) 
            {
                nums[k++] = temp[i--];
            } else {
                nums[k++] = temp[j--];
            }
        }
    }
};

//2. nth_element : O(n) 
//퀵 셀렉션 알고리즘은 어떠한 임의의 숫자배열이 있다고 했을 때 
//k번째로 작은 값 혹은 큰 값을 찾을 때 사용하는 알고리즘이다.
//https://sexycoder.tistory.com/101

class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        int m = nums.size();
        auto mptr = nums.begin() + (m-1)/2; 
        
        nth_element(nums.begin(), mptr, nums.end());  // O(n)
        int median = *mptr; 
        
        int i = 1;  
        int j = ((m - 1) & 1) ? m - 2 : m - 1; 
        //O(n)
        for (int l = 0; l < m; ++l) 
        {
            if (nums[l] > median) 
            { 
                if (l <= i && (l & 1)) continue;      
                swap(nums[l], nums[i]);
                i += 2;
                l--;
            } 
            else if (nums[l] < median)
            {  
                if (l >= j && (l & 1) == 0) continue;     
                swap(nums[l], nums[j]);
                j -= 2;
                l--;
            }
       }
    }
};


#define _CRT_SECURE_NO_WARNINGS 
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v{ 9, 6, 4, 3, 2, 6, 7, 5, 3 };

	/*
	std::nth_element(v.begin(), v.begin(), v.end());

	
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "값은 " << v[i] << '\n';
	}
	*/

	std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
	std::cout << "중간값은 " << v[v.size() / 2] << '\n';

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "값은 " << v[i] << '\n';
	}


	std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>());
	std::cout << "두 번째로 큰 원소는 " << v[1] << '\n';

	
	return 0;
}