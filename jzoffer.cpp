#include<stdio.h>

// 注意这个是用c语言写的！！！！

/******* 题目集 *********/
/*
 1、数组
 （1） 二维数组查找
 （8） 旋转数组的最小值 
 （12）调整数组顺序使奇数位于偶数前面
 （18）顺时针打印矩阵 
 
 2、链表
 （3） 从尾到头打印链表（递归＋非递归）
 （11）O(1)时间删除链表结点
 （13）链表中倒数第 k个结点 
 （14）反转链表（递归＋非递归）
 （15）合并两个排序的链表（递归＋非递归）
 （20）两个链表的第一个公共结点 
 
 3、栈和队列
 （5） 组合栈实现队列 
 （19）包含min函数的栈 
 
 4、树 
 （4） 重建二叉树
 （16）树的子结构
 （17）二叉树的镜像
 （21）从上到下打印二叉树
 （22）从上到下分层打印二叉树 
 （23）二叉搜索树的第 k大结点（递归＋非递归）
 （24）输出二叉树根结点到每个叶结点的路径
 （27）判断序列是否为二叉排序树的查找序列  
 
 5、字符串
 （2） 字符串空格替换
 （28）字符串中第一个只出现一次的字符
 （29）字符串左旋
 （32）打印 1到最大的 n位数  
  
 6、其他
 （6） 斐波那契数列
 （7） 青蛙跳台阶 
 （9） 二进制中 1的个数
 （10）数值的整数次方pow
  (33) 阶乘最后一个非零数 
 
 7、排序
 （25）计数排序/鸽巢排序
 （26）鸡尾酒排序（双向冒泡） 
 （30）奇偶排序 
 （31）地精排序 




 */ 



/* 
 * (1) 二维数组查找（从左到右、从上到下递增） 
 * 输入 **matrix 是长度为 matrixSize 的数组指针的数组，其中每个元素（也是一个数组）
 * 的长度组成 *matrixColSize 数组作为另一输入，*matrixColSize 数组的长度也为 matrixSize
 * 放弃思考这个参数吧。。就记住能这样用就行了 
 */
 
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || *matrixColSize == 0){
    	return false;
	} 
    int row = 0, column = *matrixColSize - 1;
    while (row < matrixSize && column >= 0) {
        int num = matrix[row][column];
        if (target == num){
        	return true;
		}
        else if(target < num){
		    column--;
		} 
        else if (target > num){
			row++;
     	}
    }
    return false;
}

/*
 *	(2) 字符串空格替换 
 */ 
char* replaceSpace(char* s){
    if(s==NULL){
        return NULL;
    }
    int count_l=0,count_b=0;
    int i=0;
    while(s[i]!='\0'){
        count_l++;
        if(s[i]==' '){
            count_b++;
        }
        i++;
    }
    int new_l=count_l+count_b*2;
    int pre=count_l;
    int rear=new_l;
    char* result = (char*)malloc(sizeof(char) * new_l + 1); // 扩容，也可以不扩容，只在一个数组里折腾 
    while(pre>=0){
    	if(s[pre]==' '){
            result[rear--]='0';
            result[rear--]='2';
            result[rear--]='%';
            pre--;
        }else{
            result[rear--]=s[pre--];
        }
	}
    return result;
}  

/* 
 *  (3) 从尾到头打印链表
 */ 
// 传入头指针， 
struct ListNode {
     int val;
     struct ListNode *next;
 };
// 非递归 
int* reversePrint(struct ListNode* head, int* returnSize){
	struct ListNode* phead=head;
	int count=0;
	while(phead){
		count++;
		phead=phead->next;
	}
	*returnSize=count;
	int* arr=(int*)malloc(count*sizeof(int));
	int i=count-1;
	phead=head;
	while(phead){  // 放到了数组里 
		arr[i--]=phead->val;
		phead=phead->next;
	}
	return arr;
}
// 递归
void printlist(ListNode* phead){
	if(phead!=NULL){
		if(phead->next!=NULL){
			printlist(phead->next);
		}
		printf("%d ",phead->val);
	}
} 

/**
 * (4) 重建二叉树 
 * 给出先序遍历序列和中序遍历序列 
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// 啊啊啊啊这个代码竟然一发通过了我真的感动得晕过去，感觉逐渐上手www 

//传入先序和中序序列及其size 
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	if(preorder==NULL||inorder==NULL||preorderSize<=0||inorderSize<=0){
		return NULL;
	} 
	int* end_preorder=preorder+preorderSize-1;
	int* end_inorder=inorder+inorderSize-1;
	
	int rootValue=preorder[0];
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val=rootValue;
	root->left=NULL;
	root->right=NULL;
	
	if(preorder==end_preorder){
		if(inorder==end_inorder&&*inorder==*preorder){
			return root;
		}
	}
	
	int* rootInorder=inorder; // 指向中序序列左子树最右 
	while(rootInorder<=end_inorder&&*rootInorder!=rootValue){
		rootInorder++;
	}
	int leftsize=rootInorder-inorder;
	int* leftpreorder_end=preorder+leftsize; //指向先序序列左子树最右 
	if(leftsize>0){
		root->left=buildTree(preorder+1,leftsize,inorder,leftsize); 
	}
	if(leftsize<end_preorder-preorder){
		root->right=buildTree(leftpreorder_end+1,end_preorder-leftpreorder_end,rootInorder+1,end_inorder-rootInorder);
	}
	
	
	return root;
}


/*
 *  (5) 用两个栈实现队列 
 */ 
typedef struct {
    int* stk;         // 指栈针 
    int stkSize;      // 栈大小，栈顶指针，指向栈顶空位 
    int stkCapacity;  // 栈容量 
} Stack;

// 建栈、入栈、出栈、栈顶、判空、释放 

Stack* stackCreate(int cpacity) {   // 传入栈容量 
    Stack* ret =(Stack*)malloc(sizeof(Stack));
    ret->stk = (int*)malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}

void stackPush(Stack* obj, int value) {
    obj->stk[obj->stkSize++] = value;   
}

void stackPop(Stack* obj) {
    obj->stkSize--;
}

int stackTop(Stack* obj) {
    return obj->stk[obj->stkSize - 1];
}

bool stackEmpty(Stack* obj) {
    return obj->stkSize == 0;
}

void stackFree(Stack* obj) {
    free(obj->stk);
}

typedef struct {
    Stack* inStack;
    Stack* outStack;
} CQueue;

CQueue* cQueueCreate() {
    CQueue* ret = (CQueue*)malloc(sizeof(CQueue));
    ret->inStack = stackCreate(10000);
    ret->outStack = stackCreate(10000);
    return ret;
}

void in2out(CQueue* obj) {
    while (!stackEmpty(obj->inStack)) {
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);
    }
}

void cQueueAppendTail(CQueue* obj, int value) {   // 入队 
    stackPush(obj->inStack, value);
}

int cQueueDeleteHead(CQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        if (stackEmpty(obj->inStack)) {
            return -1;
        }
        in2out(obj);  //从in到out搬数据 
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return x;
}

void cQueueFree(CQueue* obj) {
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}

/*
 * (6) 斐波那契数列 
 */ 
int fib(int n){   // 0,1,1,2,3,5
    int fib_1=0,fib_2=1,fib_n=0;
    if(n==0){
        return fib_1;
    }
    if(n==1){
        return fib_2;
    }
    for(int i=2;i<=n;i++){
        fib_n=(fib_1+fib_2)%1000000007;
        fib_1=fib_2;
        fib_2=fib_n;
    }
    return fib_n;
}

/*
 * (7) 青蛙跳台阶 
 */
 // 第一次跳一级，则后面的跳法数目等于f(n-1)，第一次跳两级，则后面的跳法数目等于f(n-2)
 // so f(n)=f(n-1)+f(n-2) 
int numWays(int n){   // 1,1,2,3,5,8,13,21
    int num_1=1,num_2=1,num_n=0;
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    for(int i=2;i<=n;i++){
        num_n=(num_1+num_2)%1000000007;
        num_1=num_2;
        num_2=num_n;
    }
    return num_n;

}

/*
 *  (8) 旋转数组的最小值 
 */ 
int minArray(int* numbers, int numbersSize){
	int pre=0,mid=0,rear=numbersSize-1;
	while(numbers[pre]>=numbers[rear]){
		if(rear-pre==1){
			mid=rear;
			break;
		}
		mid=(pre+rear)/2;
		if(numbers[mid]==numbers[pre]&&numbers[mid]==numbers[rear]){  // 此时需要顺序查找 
			int min=numbers[pre];
			for(int i=pre;i<=rear;i++){
				if(numbers[i]<min){
					min=numbers[i];
				}
			}
			return min;
		}
		if(numbers[mid]>=numbers[pre]){
			pre=mid;
		}
		else if(numbers[mid]<=numbers[rear]){
			rear=mid;
		}
	}
	return numbers[mid];

}

/*
 * (9) 二进制中 1的个数 

int hammingWeight(uint32_t n) {
    int count=0;
	unsigned int flag=1;
	while(flag){
		if(n&flag){
			count++;
		}
		flag=flag<<1;
	} 
	return count;
}

// 法 2：一个二进制整数 -1，再和原数做 与运算，即可使其最右边一个 1变成 0
//       这样一来，数里有多少个 1就会进行多少次这个运算
int hammingWeight2(uint32_t n){
	int count=0;
	while(n){
		count++;
		n=(n-1)&n;
	}
	return count;
} 
 */ 
 
 
/*
 * (10) 数值的整数次方 
 */
bool myequal(double num1,double num2){
	if((num1-num2>-0.0000001)&&(num1-num2<0.0000001)){
		return true;
	}else{
		return false;
	}
}

double pow1(double x,unsigned int n){
	if(n==0){
		return 1;
	}
	if(n==1){
		return x;
	}
	double result=pow1(x,n>>1);
	result=result*result;
	if(n&0x1==1){
		result=result*x;
	}
	return result;
}

double myPow(double x, int n){
	
	double result;
	
	if(myequal(x,0.0) && n<0){
		return 0.0;
	}
	
	unsigned int abs_n=(unsigned int)(n);
	if(n<0){
		abs_n=(unsigned int)(-n);
	}
	
	result=pow1(x,abs_n);
	if(n<0){
		result=1.0/result;
	}
	return result;
}


/*
 * (11) O(1)时间删除链表中结点 
 */

struct ListNode* deleteNode(struct ListNode* head, int val){
	if(head->val == val) {   // 如果头结点就是 
        return head->next;
    }

    struct ListNode* pre = head;

    // 没找到待删除的节点，继续遍历查找
    while ((pre->next != NULL) && (pre->next->val != val)) {  
        pre = pre->next;
    }

    // 找到，即 pre->next->val=val 
    if(pre->next != NULL) {  
        pre->next = pre->next->next;
    }
    return head;


}

/*
 *  (12) 调整数组顺序使奇数位于偶数前面 
 */
int* exchange(int* nums, int numsSize , int* returnSize){ //
	if(nums==NULL||numsSize==0){ 
		return ;
	} 
	int* pre=nums;
	int* rear=nums+numsSize-1;
	while(pre<rear){
		while(pre<rear&&(*pre)%2!=0){ // 再判断一次是为了避免死循环 
			pre++;
		}
		while(pre<rear&&(*rear)%2==0){
			rear--;
		}
		if(pre<rear){  // 相等的情况下就不需要再交换了 
			int temp=*pre;
			*pre=*rear;
			*rear=temp; 
			
		} 
	}
	*returnSize=numsSize;
	return nums;

}

/*
 * (13) 链表中倒数第 k个结点 
 */
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	if(head==NULL||k==0){
		return NULL;
	} 
	struct ListNode* pre=head;
	struct ListNode* rear=NULL;
	for(int i=0;i<k-1;i++){
		if(pre->next!=NULL){
			pre=pre->next;
		}else{
			return NULL;
		}
	}
	rear=head;
	while(pre->next!=NULL){
		pre=pre->next;
		rear=rear->next;
	}
	return rear;

}

/*
 * (14) 反转链表 
 * （递归＋非递归） 
 */
// 迭代
struct ListNode* reverseList(struct ListNode* head){
	if(head==NULL||head->next==NULL){
		return head;
	} 
	struct ListNode* pre=NULL;  // 前一个结点 
	struct ListNode* cur=head;  // 当前结点
	struct ListNode* temp=NULL;
	while(cur!=NULL){
		temp=cur->next;
		cur->next=pre;
		pre=cur;
		cur=temp;
		
	} 
	return pre;

}
// 递归 
struct ListNode* reverseList2(struct ListNode* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	struct ListNode* node=reverseList2(head->next);
	head->next->next=head;
	head->next=NULL;	
	return node;
}

/*
 * (15) 合并两个排序的链表 
 * （递归 +非递归） 
 */
// 迭代 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    } 
    struct ListNode* prehead=NULL;
    if(l1->val<l2->val){
        prehead=l1;
        l1=l1->next;
    }else{
        prehead=l2;
        l2=l2->next;
    }
	struct ListNode* pre=prehead;
	while(l1!=NULL&&l2!=NULL){
		if(l1->val<l2->val){
			pre->next=l1;
			l1=l1->next;
		}
		else{
			pre->next=l2;
			l2=l2->next;
		}
		pre=pre->next;
	}
	if(l1==NULL){
		pre->next=l2;
	}else{
		pre->next=l1;
	}
	return prehead;

}

// 递归 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    } 
    struct ListNode* pre=NULL;
    if(l1->val<l2->val){
    	pre=l1;
    	pre->next=mergeTwoLists(l1->next,l2);
	}
	else{
		pre=l2;
		pre->next=mergeTwoLists(l1,l2->next);
	}
    return pre;

}

/*
 * (16) 树的子结构 
 */
bool check(struct TreeNode* A,struct TreeNode* B){
	if(B==NULL){
		return true;
	}
	if(A==NULL){
		return false;
	}
	if(A->val!=B->val){
		return false;
	}
	return check(A->left,B->left) && check(A->right,B->right);
}
bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
	bool result=false;
	if(A!=NULL&&B!=NULL){
		if(A->val==B->val){
			result=check(A,B);
		}
		if(!result){
			result=isSubStructure(A->left,B);
		}
		if(!result){
			result=isSubStructure(A->right,B);
		}
	} 
	return result;
}

/*
 * (17) 二叉树的镜像 
 */
struct TreeNode* mirrorTree(struct TreeNode* root){
	if((root==NULL)||(root->left==NULL&&root->right==NULL)){
		return root;
	}
	struct TreeNode* ptemp=root->left;
	root->left=root->right;
	root->right=ptemp;
	if(root->left){
		mirrorTree(root->left);
	} 
	if(root->right){
		mirrorTree(root->right);
	}
	return root;

}

/*
 * (18) 顺时针打印矩阵 
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
	if(matrixSize==0||matrixColSize[0]==0){
		*returnSize=0;
		return NULL;
	}
	int num_r=matrixSize, num_c=matrixColSize[0];
	int total=num_r*num_c;
	int* arr = malloc(sizeof(int) * (total));
	*returnSize=0;
	
	int left=0,top=0,right=num_c-1,bottom=num_r-1;
	while(left<=right&&top<=bottom){
		for(int i=left;i<=right;i++){
			arr[*returnSize]=matrix[top][i];
			(*returnSize)++;
		}
		for(int i=top+1;i<=bottom;i++){
			arr[*returnSize]=matrix[i][right]; 
			(*returnSize)++;
		}
		if(left<right&&top<bottom){
			for(i=right-1;i>=left;i--){
				arr[*returnSize]=matrix[bottom][i];
				(*returnSize)++;
			}
			for(i=bottom-1;i>top;i--){
				arr[*returnSize]=matrix[i][left];
				(*returnSize)++;
			}
		}
		
		left++;
		right--;
		top++;
		bottom--;
	}
	return arr;
	
}  

/*
 * (19) 包含 min函数的栈 
 */
typedef struct {
	int* stack_main;
	int* stack_ass;  // 辅助栈
	int top_main;
	int top_ass; 

} MinStack;

#define Max_size 10000
/** initialize your data structure here. */
 
MinStack* minStackCreate() { // 创建 
	MinStack* sta=(MinStack*)malloc(sizeof(MinStack));
	sta->stack_main=(int*)malloc(sizeof(int)*Max_size);
	sta->stack_ass=(int*)malloc(sizeof(int)*Max_size);
	sta->top_ass=-1;
	sta->top_main=-1;
	return sta;
}

void minStackPush(MinStack* obj, int x) {  // 入栈
	if(obj->top_main<Max_size-1){
		obj->stack_main[++obj->top_main]=x;
 	    if(obj->top_ass==-1){
	    	obj->stack_ass[++obj->top_ass]=x;
		}else{
			if(x<obj->stack_ass[obj->top_ass]){
				obj->stack_ass[++obj->top_ass]=x;
			}else{
                ++obj->top_ass;
				obj->stack_ass[obj->top_ass]=obj->stack_ass[obj->top_ass-1];
			}
		}
	} 
    
}

void minStackPop(MinStack* obj) {  // 出栈
	if(obj->top_ass>=0&&obj->top_main>=0){
		obj->top_main--;
		obj->top_ass--;
	} 
}

int minStackTop(MinStack* obj) {  // 获得栈顶元素
	return obj->stack_main[obj->top_main];

}

int minStackMin(MinStack* obj) {  // 获得最小值 
	return obj->stack_ass[obj->top_ass];

}

void minStackFree(MinStack* obj) {  // 释放 
	free(obj->stack_ass);
	free(obj->stack_main);
	free(obj);

}

/*
 * (20) 两个链表的第一个公共结点 
 */
// 双指针法；意思是说错的人一定会错过对的人终究会重逢
// 另外，这段代码写得好优雅
// 另一种方法：长的那条先走几步 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode *pA = headA, *pB = headB;
    while (pA != pB) {  // 最后两者都为 null，或者相等指向同一结点 
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
    }
    return pA;
}

/*
 * (21) 从上到下打印二叉树 ver.1.0 
 */
int* levelOrder(struct TreeNode* root, int* returnSize){
	if(root==NULL){
        *returnSize=0;
        return root;
	}
	struct TreeNode* Queue[1100];  // 借助queue实现层序遍历 
	struct TreeNode *p;
	int* arr=(int *)malloc(sizeof(int)*1100);  // 层序遍历结果 
    int front =0,rear=0;
    int i=0;
    Queue[rear]=root;//根节点先入队
    while(front<=rear){
        p=Queue[front++];//队头元素出队
        arr[i++]=p->val;
        if(p->left){
			Queue[++rear]=p->left;
		}
        if(p->right){
			Queue[++rear]=p->right;
		}
    }
    *returnSize=i;
	return arr;

}

/*
 * (22) 从上到下打印二叉树 ver.2.0
 *  request：每层打印到一行 
 */ 
#define MAXSIZE 1100
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	if (root==NULL) {// 空树返回NULL
        *returnSize = 0;
        return NULL;
    }
    
    struct TreeNode* Queue[MAXSIZE];// = (struct TreeNode*)malloc(sizeof(struct TreeNode) * MAXSIZE);// 数组队列
    struct TreeNode* p;
    int front=0,rear=0;
    int i=0;
    int temp=0;
    int** arr = (int**)malloc(sizeof(int*) * MAXSIZE);// 保存层次遍历结果
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int*) * MAXSIZE);// 指向一个数组，数组记录树每层的节点数
    Queue[rear] = root;
    while (front <= rear) {
        (*returnColumnSizes)[*returnSize] = (rear-front+1);// 此时队列存储的结点数就是该层结点数
        arr[*returnSize] = (int*)malloc(sizeof(int) * (rear-front+1));//结果数组初始化
        temp = rear;
        i = 0;
        while (front <= temp) {//本层元素出队
            p=Queue[front++];
			arr[*returnSize][i++] = p->val;// 出队元素保存进结果数组 
            if (p->left) {
                Queue[++rear] = p->left;
            }
            if (p->right) {
                Queue[++rear] = p->right;
            }
        }
        (*returnSize)++;//层数+1
    }
    return arr;

}

/*
 * (23) 二叉搜索树的第 k大结点（递归＋非递归） 
 * 就是二叉排序树啦 
 */ 
// 递归
// 有没有人告诉我一下树节点不够多的时候怎么办啊 T-T 
void findkth(struct TreeNode* root,int k,int* step,int* res){  //step和 res的地址 
	if(root!=NULL){
		findkth(root->right,k,step,res);
		(*step)++;
		if(*step==k){
			*res=root->val;
			return ;
		}
		findkth(root->left,k,step,res);
	} 
}

int kthLargest(struct TreeNode* root, int k){
	if(root==NULL||k<=0){
		return ;
	}
	int step=0,res=0;
	findkth(root,k,&step,&res);  // 传入两个数的地址，保持一致性
	if((*step)<k){
		return ;
	}
	return res; 

}

// 迭代
#define MaxSize 10000
int kthLargest(struct TreeNode* root, int k)
{
    struct TreeNode* stack[MaxSize];
    int top=-1;
    int step=0,res=0;
    while(root!=NULL||top!=-1)  // 还有结点没有访问完（树上还有，or栈里还有） 
    {
        while(root!=NULL)
        {
            stack[++top]=root;  // push 
            root=root->right;  // 右子树 
        }
        if(top!=-1)  // 有右子树 
        {
            root=stack[top--];  // pop 按右中左的顺序 
            step++;
            if(step==k)
            {
                res=root->val;
                break;
            }
            root=root->left;  // 左子树 
        }
    }
    return res;
}

/*
 * (24) 输出二叉树根结点到每个叶结点的路径 
 */ 
void PrintPath(TreeNode* root){
	if(root==NULL){
		printf("threr is no tree\n");
		return;
	}
	struct TreeNode* stack[1000];
	struct TreeNode* pNode=root;
	int data[1000];
	int top=0,i=0,k=0;
	stack[top]=pNode;
	while(top!=-1){
		pNode=stack[top--];  //pop
		data[k++]=pNode->val;
		if(pNode->left==NULL&&pNode->right==NULL){  // 叶子结点 
			for(i=0;i<k;i++){
				printf("%d ",data[i]);
			}
			k--;
			printf("\n");
		}
		if(pNode->right!=NULL){
			stack[++top]=pNode->right;
		}
		if(pNode->left!=NULL){
			stack[++top]=pNode->left;
		}
	}	
} 

/*
 * (25) 计数排序
 * https://blog.csdn.net/justidle/article/details/104203972 
 */ 
// 时间：O(n+k) 空间：O(n+k)，n为数组长，k为数范围 
void CountSort(int* sort,int n){
	if(sort==NULL||n<1){
		return;
	}
	int max=sort[0],min=sort[0];
	int i,j,k;
	for(i=0;i<n;i++){      // 找出最大和最小值 
		if(sort[i]<min){
			min=sort[i];
		}
		if(sort[i]>max){
			max=sort[i];
		}
	}
	int range=max-min+1;  // 数值范围
	int count[range];
	for(j=0;j<range;j++){
		count[j]=0;
	} 
	for(k=0;k<n;k++){
		count[sort[k]-min]++;
	}
	j=0;
	for(i=0;i<range;i++){
		while(count[i]>0){
			sort[j++]=min+i;
			count[i]--;
		}
	}
}

/*
 * (26) 鸡尾酒排序（双向冒泡） 
 */ 
void swap(int* a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void cocktailSort(int* data,int n){
	if(data==NULL||n<2){
		return;
	}
	int low = 0;
	int high= n-1;
	int i;
	while(low<high){
		for(i=low;i<high;i++){
			if(data[i]>data[i+1]){
				swap(&data[i],&data[i+1]);
			}
		}
		high--;
		for(i=high;i>low;i--){
			if(data[i]<data[i-1]){
				swap(&data[i],&data[i-1]);
			}
		}
		low++;
	}
}
 
/*
 *  (27) 判断序列是否为二叉排序树的查找序列 
 */ 
bool orderJudge(int data[],int length){
	/*
	判断有效性；
	int lowpart[],highpart[];
	遍历按序大放大，小放小；
	分别判断 lowpart序列单增 和 highpart序列单减 
}

/*
 * (28) 字符串中第一个只出现一次的字符 
 */ 
char firstUniqChar(char* s){
	if(s==NULL){
		return ' ';
	} 
	int tableSize=256,i;
	int hashTable[tableSize];
	for(i=0;i<tableSize;i++){
		hashTable[i]=0;
	}
	char* pHashKey=s;
	while((*pHashKey)!='\0'){
		hashTable[*(pHashKey)]++;
		pHashKey++;
	}
	pHashKey=s;
	while(*pHashKey!='\0'){
		if(hashTable[*pHashKey]==1){
			return *pHashKey;
		}
		pHashKey++;
	}
	return ' ';

}

/*
 * (29) 字符串左旋 
 */ 
void Reverse(char* begin,char* end){
	if(begin==NULL||end==NULL){
		return ;
	}
	while(begin<end){
		char temp=*begin;
		*begin=*end;
		*end=temp;
		begin++;
		end--;
	}
}
 
char* reverseLeftWords(char* s, int n){
	 if(s!=NULL){
	 	int len=strlen(s);
	 	if(len>0&&n>0&&n<len){
	 		char* pstart_1=s;
	 		char* pend_1  =s+n-1;
	 		char* pstart_2=s+n;
	 		char* pend_2  =s+len-1;
	 		Reverse(pstart_1,pend_1);
	 		Reverse(pstart_2,pend_2);
	 		Reverse(pstart_1,pend_2);
		 }
	 	
	 } 
	 return s;

}

/*
 * (30) 奇偶排序
 * https://blog.csdn.net/qq_37507976/article/details/93306089 
 */
void oddevensort(int data[],int length){
	if(data==NULL||length<1){
		return;
	}
	bool oddsorted =false;
	bool evensorted=false;
	int i;
	while(!oddsorted||!evensorted){
		oddsorted=true;
		evensorted=true;
		for(i=0;i<length-1;i+=2){
			if(data[i]>data[i+1]){
				int temp=data[i];
				data[i]=data[i+1];
				data[i+1]=temp;
				evensorted=false;
			}
		}
		for(i=1;i<length-1;i+=2){
			if(data[i]>data[i+1]){
				int temp=data[i];
				data[i]=data[i+1];
				data[i+1]=temp;
				oddsorted=false;
			}
		}
	}
} 

/*
 * (31) 地精排序
 * https://blog.csdn.net/p812438109/article/details/102925401?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-2-102925401-blog-81748602.235%5Ev27%5Epc_relevant_3mothn_strategy_and_data_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-2-102925401-blog-81748602.235%5Ev27%5Epc_relevant_3mothn_strategy_and_data_recovery&utm_relevant_index=3 
 *（但其中有一步演示总觉得不太对，思想是没问题的 
 */ 
void gnomeSort(int data[],int length){
	if(data==NULL||length<1){
		return;
	}
	int i=0;
	while(i<length){
		if(i==0||data[i-1]<=data[i]){ // 无需交换 
			i++;
		}
		else{
			int temp=data[i];
			data[i]=data[i-1];
			data[i-1]=temp;
			i--;
		} 
	}
} 

/*
 * (32) 打印 1到最大的 n位数 
 */
// 全排列解法 
void printNumbers(int n){
	if(n<=0){
		return;
	}
	char number[n+1];
	number[n]='\0';
	for(int i=0;i<10;i++){
		number[0]=i+'0';
		Print1toMaxDigits(number,n,0);
	}
}

void Print1toMaxDigits(char* number,int length,int index){
	if(index==length-1){   // 已经固定完所有位 
		PrintNumber(number);  // 输出此时这个数 
		return;
	}
	for(int i=0;i<10;i++){
		number[index+1]=i+'0';  // 固定第（index+1）位为 i 
		Print1toMaxDigits(number,length,index+1);  // 开始固定下一位 
	}
}

void PrintNumber(char* number){
	bool isbegin=false;
	int nlength=strlen(number);
	for(int i=0;i<nlength;i++){
		if(isbegin==false&&number[i]!='0'){  // 遇到第一个非零字符才开始打印 
			isbegin=true; // 可以开始了 
		}
		if(isbegin==true){
			printf("%c",number[i]);
		}
	}
	printf("\t");
}

/*
 * (32) 阶乘的最后一个非零数 
 */
int main() {
    int n;
    scanf("%d",&n);

    int count2 = 0, count5 = 0;  //记一下2，5的个数
    int product = 1;         //记一下其他质因子的积的个位数
    for (int i = 2; i <= n; i++) {
        int temp = i;
        for (; temp % 5 == 0; temp /= 5)
            count5++;
        for (; temp % 2 == 0; temp /= 2)
            count2++;
        product = product * temp % 10;
    }
    for (int i = 0; i < count2 - count5; i++)  //5肯定比2少，2*5匹配完后，剩余的2乘回去
        product = product * 2 % 10;
    printf("%d\n",product);
}








 

/*
 * 栈的压入、弹出序列 
 */
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){

}










int main(){
	/*
	char str[]="WE Are Happy.";
	char* p=str;
	printf("%s\n",replaceSpace(p)); 
	
	int arr[5]={2,2,2,0,1};
	printf("%d\n",minArray(arr,5)); 
	
	
	
	printf("%lf\n",myPow(3,5));
	
	int a[7]={2,1,5,4,7,6,8};
	int* p=a;
	p=exchange(a,7);
	for(int i=0;i<7;i++){
		printf("%d ",*p);
		p++;
	}
	*/
	int arr1[5]={1,2,3,4,5};
	int arr2[5]={4,5,3,2,1};
	if(validateStackSequences(arr1,5,arr2,5)){
		printf("ok\n");
	}else{
		printf("no\n");
	}
	

	
	
	
	
	return 0;
}




