class Solution
{
public:
    int binarySearch(int target, vector<int> &nums)
    {
        int start = 0;
        int end = nums.size();
        while (start < end)
        {
            int mid = (start + end) / 2;

            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }

        return start;
    }
    int missingNumber(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[binarySearch(i, nums)] != i)
                return i;
        }

        return nums.size();
    }
};