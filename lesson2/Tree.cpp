#include <iostream>
using namespace std;
typedef int DataType;
typedef struct BinaryTree
{
	DataType data;//放对应数据
	struct BinaryTree* left;//左子树节点
	struct BinaryTree* right;//右子树节点
}BTNode;
BTNode* BuyNode()
{
	BTNode* root=(BTNode*)malloc(sizeof(BTNode));
	if(root==nullptr)
	{
		perror("malloc failed!");
		exit(-1);
	}
	root->data=0;
	root->left=root->right=nullptr;
}
BTNode* CreatNode()
{
	


}
int TreeSize(int* root,int k)
{
	return root==nullptr ? 0 : 
		TreeSize(root->left,k)+TreeSize(root->right,k)+1;
}
int main()
{


	return 0;
}