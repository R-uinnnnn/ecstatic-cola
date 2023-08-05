#include <iostream>
using namespace std;
typedef int DataType;
typedef struct BinaryTree
{
	DataType data;//放对应数据
	struct BinaryTree* left;//左子树节点
	struct BinaryTree* right;//右子树节点
}BTNode;

int TreeSize(int* root,int k)
{
	return root==nullptr ? 0 : 
		TreeSize(root->left,k)+TreeSize(root->right,k)+1;
}
int main()
{


	return 0;
}