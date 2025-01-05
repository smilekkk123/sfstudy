#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
（1）初始化一个堆，从最后一个父节点开始，i取len/2-1，son=i*2+1，son的右兄弟=son+1
（2）每次输出最顶端，swap（最顶端，最后一个），继续对未排序节点建堆
*/

void buildMaxHeap(vector<int>& arr,int dad,int end){
    int son;
    for(int i=dad;i>=0;i--){
        son=i*2+1;
        // 找出最大的兄弟
        if(son+1<=end && arr[son]<arr[son+1]){  // 如果右兄弟存在且右兄弟更大
            son++;
        }
        // 最大的兄弟和爹比
        if(son<=end && arr[i]<arr[son]){  // 找出三个中最大的
            swap(arr[i],arr[son]);   
        }
    }
}

void HeapSort(vector<int>& arr){
    int len=arr.size();
    buildMaxHeap(arr,len/2-1,len-1);  // 建初始堆，第一个父节点 len/2-1，最后一个节点 len-1
    for(int i=len-1;i>0;i--){   // i表示数组长度
        swap(arr[i],arr[0]);
        buildMaxHeap(arr,i/2-1,i-1);
    }
}


int main(){
    vector<int> arr;
    int x;
    do{
        cin>>x;
        arr.push_back(x);
    }while(getchar()!='\n');

    HeapSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    


    return 0;
}