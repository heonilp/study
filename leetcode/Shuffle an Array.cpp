class Solution {
public:
	vector<int> n;
    vector<int> orig;
	
	Solution(vector<int>& nums):n{nums} 
    {
		orig=nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
    {
		n=orig;
		return n;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() 
    {

		for(int i=0;i<n.size();i++)
        {
            int ns = n.size()-i;
			swap(n[i],n[rand()%ns+i]);

		}
		return n;
	}

};