class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countneg = 0;
        int countpos = 0;

        for(int i=0;i<=nums.size()-1;i++){
        if(nums[i]>0)
        countpos++;
        if(nums[i]<0)
        countneg++;
    }
    return max(countpos,countneg);
    }
};