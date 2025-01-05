#include<iostream>
#include<vector>
using namespace std;

/*
快速排序：
（1）while(left<right){ 每次选第一个元素作为key，返回key所在位置，对key左右再分别快排 }
（2）partition: 选择第一个元素作为key，将大于key的移到key右边，小于的放到左边
            具体实现：while(i<j)，右指针先左移，遇到 <key 的，交换，左指针++；
                                 左指针右移，遇到 >=key 的，交换，右指针--；
*/

int Partition(vector<int>& arr, int l, int r) {
    int i = l, j = r;
    int key = arr[i];
    while (i < j) {
        while (i < j && arr[j] > key) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i++] = arr[j];
            arr[j] = temp;
        }
        while (i < j && arr[i] <= key) {
            i++;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j--] = temp;
        }
    }
        return i;
}

// 降序
int Partition1(vector<int>& arr, int l, int r) {
    int i = l, j = r;
    int key = arr[i];
    while (i < j) {
        while (i < j && arr[j] < key) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i++] = arr[j];
            arr[j] = temp;
        }
        while (i < j && arr[i] >= key) {
            i++;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j--] = temp;
        }
    }
        return i;
}

void QuickSort(vector<int>& arr, int left, int right) {
    int mid;
    if (left < right) {
        mid = Partition(arr, left, right);
        QuickSort(arr, mid + 1, right);
        QuickSort(arr, left, mid - 1);
    }
}

void QuickSort1(vector<int>& arr, int left, int right) {
    int mid;
    if (left < right) {
        mid = Partition1(arr, left, right);
        QuickSort1(arr, mid + 1, right);
        QuickSort1(arr, left, mid - 1);
    }
}

int main(){
    vector<int> arr;
    int x;
    do{
        cin>>x;
        arr.push_back(x);
    }while(getchar()!='\n');
    /*
    QuickSort(arr,0,arr.size()-1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
*/
    QuickSort1(arr,0,arr.size()-1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}