// Problem Statement
/*
679. 24 Game
Hard

629

131

Add to List

Share
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/

//Solutions.cpp

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double>a;
        for(int i=0;i<nums.size();i++)
            a.push_back(nums[i]);
        return result(a);
    }
    bool result(vector<double>&a) {
        if(a.size()==1)
            return abs(a[0]-24.0)<0.0001;
        for(int i=0;i<a.size();i++) {
            for(int j=0;j<i;j++) {
                double x=a[i];
                double y=a[j];
                vector<double>val;
                val.push_back(x/y);
                val.push_back(y/x);
                val.push_back(x-y);
                val.push_back(y-x);
                val.push_back(x*y);
                val.push_back(x+y);
                vector<double>copya;
                for(int k=0;k<a.size();k++) {
                    if(k!=i&&k!=j)
                        copya.push_back(a[k]);
                }
                for(int k=0;k<val.size();k++) {
                    copya.push_back(val[k]);
                    if(result(copya))
                        return true;
                    copya.pop_back();
                }
            }
        }
        return false;
    }
};