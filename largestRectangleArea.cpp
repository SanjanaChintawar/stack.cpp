// Largest Rectangular Area in Histogram

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> nextSmallerElelmets(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElelmets(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElelmets(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElelmets(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};

int main()
{
    Solution s1;
    vector<int> height{2, 1, 5, 6, 2, 3};
    int ans;

    ans = s1.largestRectangleArea(height);
    cout << ans;

    return 0;
}