#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums,int target)
{
    sort(nums.begin(), nums.end());
    if (nums.size() < 4) {
        return {};
    }  
    vector<vector<int>> res;
    int left, right,i=0;
    for (int k = 0; k < nums.size() - 3; k++)
    {
        if(k>0 && nums[k] == nums[k-1]){
            continue;
        }
        int tmptgt = target - nums[k];
        i=k+1;
        while (i < nums.size() - 2) {
            if (i > k+1 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                while ((long)nums[i] + nums[left] + nums[right] > tmptgt && left < right) right--;
                while ((long)nums[i] + nums[left] + nums[right] < tmptgt && left < right) left++;

                if ((long)nums[i] + nums[left] + nums[right] == tmptgt && left < right) {
                    res.push_back({nums[k],nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            i++;
    }
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

    int target;
    cin>>target;

    vector<vector<int>> res;
    res = fourSum(arr,target);

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