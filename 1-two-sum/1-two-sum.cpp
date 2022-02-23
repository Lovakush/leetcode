class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size;
        size = nums.size();
        vector<int> vect;
        unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        if (mp.find(target - nums[i]) == mp.end())
            mp[nums[i]] = i;
        else
        {
            vect.push_back(mp[target - nums[i]]);
            vect.push_back(i);
            break;
        }
    }
        return vect;
}
};
