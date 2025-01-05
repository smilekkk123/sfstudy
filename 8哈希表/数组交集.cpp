/*
 * 使用 unordered_set 去重
 */
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> s_num1(nums1.begin(),nums1.end()); // 将nums1中的数据去重放入
        for(int num:nums2){
            if(s_num1.find(num)!=s_num1.end()){
                res.insert(num);
            }
        }

        return vector<int>(res.begin(),res.end());

    }
int main(){
    vector<int> nums1;
    vector<int> nums2;
    int num;

    do {
        cin >> num;
        nums1.push_back(num);
    } while (getchar() != '\n' );

    do {
        cin >> num;
        nums2.push_back(num);
    } while (getchar() != '\n' );

    vector<int> res=intersection(nums1,nums2);

    for(int i:res){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
    

}