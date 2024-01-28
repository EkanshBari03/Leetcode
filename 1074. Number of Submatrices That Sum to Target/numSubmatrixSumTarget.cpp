class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> nums(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < col; j++)
            {
                sum = sum + matrix[i][j];
                nums[i][j] = sum;
            }
        }
        int cnt = 0;
        for (int sc = 0; sc < col; sc++)
        {
            for (int c = sc; c < col; c++)
            {
                unordered_map<int, int> m;
                int presum = 0;
                for (int r = 0; r < row; r++)
                {
                    presum += nums[r][c] - (sc > 0 ? nums[r][sc - 1] : 0);
                    if (presum == target)
                        cnt++;
                    if (m.find(presum - target) != m.end())
                        cnt += m[presum - target];
                    m[presum]++;
                }
            }
        }

        return cnt;
    }
};