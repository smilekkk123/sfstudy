#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0) {
        return {}; // 注意这里
    }  
    vector<vector<int>> res;
    int left, right,i=0;

    while (nums[i] <= 0 && i < nums.size() - 2) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            i++;
            continue;
        }
        left = i + 1;
        right = nums.size() - 1;
        while (left < right) {
            while (nums[i] + nums[left] + nums[right] > 0 && left < right) right--;
            while (nums[i] + nums[left] + nums[right] < 0 && left < right) left++;

            if (nums[i] + nums[left] + nums[right] == 0 && left < right) {
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
        }
        i++;
    }
    return res;
}

int main()
{
    // 输入一个数组，找到3个数和为0的所有不重复三元组
    vector<int> arr;
    int num;
    do
    {
        cin >> num;
        arr.push_back(num);
    } while (getchar() != '\n');

    vector<vector<int>> res;
    res = threeSum(arr);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}