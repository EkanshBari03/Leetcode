class Solution {
    public int[] getNsl(int[] nums, int n) {
        int[] result = new int[n];
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && nums[s.peek()] >= nums[i]) {
                s.pop();
            }

            result[i] = s.isEmpty() ? -1 : s.peek();
            s.push(i);
        }

        return result;
    }

    public int[] getNsr(int[] nums, int n) {
        int[] result = new int[n];
        Stack<Integer> s = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && nums[s.peek()] > nums[i]) {
                s.pop();
            }

            result[i] = s.isEmpty() ? n : s.peek();
            s.push(i);
        }

        return result;
    }

    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;

        int[] nsl = getNsl(arr, n);
        int[] nsr = getNsr(arr, n);

        long mod = (long) 1e9 + 7;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            long ls = i - nsl[i];
            long rs = nsr[i] - i;

            long totalWays = ls * rs;

            long totalSum = (arr[i] * totalWays) % mod;

            sum = (sum + totalSum) % mod;
        }

        return (int) sum;
    }
}