class Solution
{
public:
    vector<int> getNsl(vector<int> &nums, int n)
    {

        vector<int> result(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                result[i] = -1;
            }
            else
            {
                while (!s.empty() && nums[s.top()] >= nums[i])
                    s.pop();

                result[i] = s.empty() ? -1 : s.top();
            }
            s.push(i);
        }
        return result;
    }
    vector<int> getNsr(vector<int> &nums, int n)
    {

        vector<int> result(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                result[i] = n;
            }
            else
            {
                while (!s.empty() && nums[s.top()] > nums[i])
                    s.pop();

                result[i] = s.empty() ? n : s.top();
            }
            s.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int> &arr)
    {

        int n = arr.size();

        vector<int> nsl = getNsl(arr, n);
        vector<int> nsr = getNsr(arr, n);

        long long mod = 1e9 + 7;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {

            long long ls = i - nsl[i]; // no. of smaller element at left side
            long long rs = nsr[i] - i; // no. of smaller element at right side;

            long long totalWays = ls * rs; // totalWays no of subarrays we get

            long long totalSum = (arr[i] * totalWays);

            sum = (sum + totalSum) % mod;
        }

        return sum;
    }
};