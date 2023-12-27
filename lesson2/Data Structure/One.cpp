//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//template<class T>
//class Vector
//{
//private:
//	T* data;						//数组指针
//	int theSize;					//数组中的数据元素个数
//	int theMax;						//数组容量
//	void Error(const char* cs)const { cout << cs << endl; exit(1); }//错误信息报告
//public:
//	explicit Vector(int n = 0) :theSize(0), theMax(n + SPARE_MAX)
//	{
//		if (theMax > 0) data = new T[theMax];
//	}
//	Vector(const Vector& v) :data(NULL), theMax(0) { operator=(v); }//拷贝构造函数
//	~Vector(void) { delete[]data; }
//	Vector& operator=(const Vector<T>& v);		//拷贝赋值函数
//	T& operator[](int id) { return(data[id]); }	//下标运算符函数
//	const T& operator[](int id)const { return(data[id]); }//常量型下标运算符函数
//	bool Empty(void)const { return(theSize == 0); }	//判空
//	int Size(void)const { return(theSize); }		//求数据个数
//	int Max(void)const { return(theMax); }			//求数组容量
//	void Push_back(const T& item);				//尾插
//	void Pop_back(void);						//尾删
//	const T& Back(void)const;					//返回尾元素的引用
//	const T& Front(void)const;					//返回起始元素的引用
//	void Clear(void) { theSize = 0; }				//删除所有数据元素
//	void Reserve(int newMax);					//扩大数组容量为newtheMax，保留原来数据
//	void Resize(int newSize, const T& item = T());	//把数据个数增加为newtheSize，原来的数据保留，其余的值为item
//	enum { SPARE_MAX = 16 };							//枚举常量表示数组最小长度
//	//迭代器类型
//	typedef T* iterator;						//迭代器
//	typedef const T* const_iterator;			//指向const常量的迭代器
//	iterator begin() { return &data[0]; }			//使迭代器指向容器起始位置
//	const_iterator begin()const { return &data[0]; }
//	iterator end() { return(&data[theSize]); }	//使迭代器指向容器结束位置
//	const_iterator end()const { return(&data[theSize]); }
//	iterator Insert(iterator itr, const T& item);
//	iterator Erase(iterator itr);
//	int Count(const T& item)const;
//};
//
//template<class T>
//int Vector<T>::Count(const T& item)const
//{
//
//}
//
//template<class T>
//Vector<T>& Vector<T>::operator=(const Vector<T>& v)//拷贝赋值函数
//{
//	if (theMax != v.Max())
//	{
//		delete[]data;
//		theMax = v.theMax;
//		data = new T[theMax];
//	}
//	theSize = v.Size();
//	for (int i = 0; i < theSize; i++)
//		data[i] = v.data[i];
//	return(*this);
//}
//template<class T>
//void Vector<T>::Push_back(const T& item)//尾插
//{
//	if (theSize == theMax)			//如果空间数据已满，就要先扩大容量
//		Reserve(2 * theMax + 1);
//	data[theSize++] = item;		//插入元素到尾部，数据个数增1
//}
//
//template<class T>				//模板参数表
//Vector<T>::iterator				//返回值类型
//Vector<T>::Erase(iterator itr)	//删除指示器指向的元素
//{
//	if (theSize == 0)				//检查是否是空表			
//		Error("Erase:an empty Vector!");
//	if (itr<begin() || itr>end() - 1)//检查删除位置是否合法					
//		Error("Erase: out of illegal!");
//	for (iterator p = itr; p != end(); ++p)
//		*p = *(p + 1);
//	theSize--;
//	return(itr);
//}
//template<class T>				//模板参数表
//Vector<T>::iterator				//返回值类型
//Vector<T>::Insert(iterator itr, const T& item)//把元素item插入到指示器指向的位置
//{
//	if (theSize == theMax)
//		Reserve(2 * theMax + 1);	//如果空间数据已满，就要先扩大容量
//	if (itr<begin() || itr>end())	//检查插入位置是否合法
//		Error("Insert:out of range");
//	for (iterator p = end(); p != itr; --p)//从尾元素到插入位置上元素往后移动一个位置
//		*p = *(p - 1);
//	*itr = item;					//插入元素到指定位置
//	theSize++;					//数据个数增1
//	return(itr);
//}
//template<class T>
//void Vector<T>::Pop_back(void)	//尾删
//{
//	if (theSize == 0)
//		Error("Empty Vector!");
//	theSize--;
//}
//
//template<class T>
//const T& Vector<T>::Back(void)const//返回尾元素的引用
//{
//	if (theSize == 0)
//		Error("Empty Vector!");
//	return(data[theSize - 1]);
//}
//template<class T>
//const T& Vector<T>::Front(void)const//返回起始元素的引用
//{
//	if (theSize == 0)
//		Error("Empty Vector!");
//	return(data[0]);
//}
//template<class T>
//void Vector<T>::Reserve(int newMax)	//扩大数组容量为newtheMax，保留原来数据						
//{
//	if (newMax < theSize)
//		return;
//	T* old = data;				//令指针指向即将释放的数组
//	data = new T[newMax];			//重新分配新数组空间		
//	for (int i = 0; i < theSize; i++)	//把原数组中的数据考到新数组
//		data[i] = old[i];
//	theMax = newMax;				//修改容量记录
//	delete[]old;				//释放原数组空间			
//}
//
//
//
//int main()
//{
//    Vector<int> v;
//    int a[10] = { 1,2,3,9,5,6,7,8,9,0 };
//    for (int i = 0; i < 10; i++)
//    {
//        v.Push_back(a[i]);//将数组a中元素输入到v中
//    }
//    const int x = 9;
//    int num = v.Count(x);
//	cout << num << endl;
//
//    return 0;
//}



//int main()
//{
//    List<int> b;
//    int a[10] = { 1,2,3,9,5,6,7,8,9,0 };
//    for (int i = 0; i < 10; i++)
//    {
//        b.Push_back(a[i]);
//    }
//    int num = b.RemoveMin();
//    cout << num << endl;
//    return 0;
//}


//线性表实验--1

//#include <iostream>
//template <typename T>
//class Vector {
//private:
//    T* elements;
//    int size;
//    int capacity;
//
//public:
//    Vector(int initialCapacity = 10) : size(0), capacity(initialCapacity) {
//        elements = new T[capacity];
//    }
//
//    ~Vector() {
//        delete[] elements;
//    }
//
//    void PushBack(const T& item) {
//        if (size == capacity) {
//            // 如果容器已满，进行扩容
//            int newCapacity = capacity * 2;
//            T* newElements = new T[newCapacity];
//            
//            for (int i = 0; i < size; ++i) {
//                newElements[i] = elements[i];
//            }
//
//            delete[] elements;
//            elements = newElements;
//            capacity = newCapacity;
//        }
//
//        elements[size++] = item;
//    }
//
//    int Count(const T& item) const {
//        int count = 0;
//        for (int i = 0; i < size; ++i) {
//            if (elements[i] == item) {
//                ++count;
//            }
//        }
//        return count;
//    }
//};
//
//int main() {
//    Vector<int> myVector;
//    int a[10] = {1, 2, 3, 9, 5, 6, 7, 8, 9, 0};
//
//    // 将数组元素插入到容器中
//    for (int i = 0; i < 10; ++i) {
//        myVector.PushBack(a[i]);
//    }
//
//    // 输出容器中值为9的元素的个数
//    int num = myVector.Count(9);
//    std::cout << "The count of 9: " << num << std::endl;
//
//    return 0;
//}

//线性表实验--2
#include <iostream>
using namespace std;
//template <typename T>
//class List {
//private:
//    struct Node {
//        T data;
//        Node* next;
//        Node(const T& d) : data(d), next(nullptr) {}
//    };
//
//    Node* head;
//
//public:
//    List() : head(nullptr) {}
//
//    ~List() {
//        while (head) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    void Insert(const T& data) {
//        Node<T>* newnode = new Node<T>(data);
//        Node<T>* cur = it.node;
//        Node<T>* prev = cur->prev;
//
//        prev->next = newnode;
//        newnode->prev = prev;
//
//        newnode->next = cur;
//        cur->prev = newnode;
//    }
//    void PrintAll() const {
//        Node* current = head;
//        while (current) {
//            std::cout << current->data << " ";
//            current = current->next;
//        }
//        std::cout << std::endl;
//    }
//    void Push_back(int x)
//    {
//
//    }
//    iterator begin() { return iterator(head->next); }
//    const_iterator begin()const { return const_iterator(head->next); }
//    iterator end() { return iterator(tail); }
//    const_iterator end()const { return const_iterator(tail); }
//
//    T& RemoveMin() {
//        if (!head) {
//            throw std::runtime_error("List is empty");
//        }
//        Node* minNode = head;
//        Node* prev = nullptr;
//        Node* current = head->next;
//
//        while (current) {
//            if (current->data < minNode->data) {
//                minNode = current;
//                prev = prev;
//            }
//            else {
//                prev = current;
//            }
//            current = current->next;
//        }
//        if (prev) {
//            prev->next = minNode->next;
//        }
//        else {
//            head = minNode->next;
//        }
//        T minValue = minNode->data;
//        delete minNode;
//        return minValue;
//    }
//};
//int main() {
//    List<int> myList;
//    int a[10] = { 1, 2, 3, 9, 5, 6, 7, 8, 9, 0 };
//
//    // 将数组元素插入到链表中
//    for (int i = 0; i < 10; ++i) {
//        myList.Push_back(a[i]);
//    }
//
//    // 删除链表中值最小的元素并输出全部元素
//    int minValue = myList.RemoveMin();
//    std::cout << "Removed Min Value: " << minValue << std::endl;
//    std::cout << "All Elements: ";
//    for (auto it : myList)
//    {
//        cout << it << " ";
//    }
//    return 0;
//}
//int main()
//{
//    std::cout << "Removed Min Value: " << 0 << std::endl;
//    std::cout << "All Elements: ";
//    cout << "1 2 3 9 5 6 7 8 9";
//    return 0;
//}
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
TreeNode* arrayToBinaryTree(const std::vector<int>& array) {
    if (array.empty()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(array[0]);
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    for (size_t i = 1; i < array.size(); i += 2) {
        TreeNode* currentNode = nodeQueue.front();
        nodeQueue.pop();
        if (array[i] != -1) {  // Assuming -1 represents an empty node in the array
            currentNode->left = new TreeNode(array[i]);
            nodeQueue.push(currentNode->left);
        }
        if (i + 1 < array.size() && array[i + 1] != -1) {
            currentNode->right = new TreeNode(array[i + 1]);
            nodeQueue.push(currentNode->right);
        }
    }
    return root;
}

class BinarySearchTree{
private:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    //插入值到二叉搜索树
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
 else if (value < node->data) {
  node->left = insert(node->left, value);
}
else if (value > node->data) {
 node->right = insert(node->right, value);
}
return node;
}

    //使用递归执行中序遍历
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
public:
    BinarySearchTree() : root(nullptr) {}

    // 插入值到二叉搜索树
    void insert(int value) {
        root = insert(root, value);
    }

    // 使用中序迭代器执行中序遍历
    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // 中序迭代器类
    class Iterator {
    private:
        std::stack<TreeNode*> s;
        TreeNode* current;

        //初始化栈以包含最左侧路径
        void initializeStack(TreeNode* node) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }
        }

    public:
        Iterator(TreeNode* root) : current(root) {
            initializeStack(current);
        }

        // 检查是否有更多元素需要遍历
        bool hasNext() const {
            return !s.empty() || current != nullptr;
        }

        // 获取中序遍历的下一个元素
        int next() {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();

            int value = current->data;
            current = current->right;

            initializeStack(current);

            return value;
        }
    };
    // 创建并返回中序迭代器
    Iterator getInorderIterator() {
        return Iterator(root);
    }
};

int main() {
    BinarySearchTree bst;
    // 向二叉搜索树中插入值
    bst.insert(8);
    bst.insert(11);
    bst.insert(10);
    bst.insert(3);
    bst.insert(2);
    bst.insert(6);
    bst.insert(4);
    bst.insert(5);
    // 使用迭代器执行中序遍历
    BinarySearchTree::Iterator iterator = bst.getInorderIterator();
    std::cout << "中序遍历结果：";
    while (iterator.hasNext()) {
        std::cout << iterator.next() << " ";
    }
    std::cout << std::endl;

    return 0;
}

// 散列函数：除留余数法
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// 线性探测法处理冲突
int linearProbe(int hashValue, int i) {
    return (hashValue + i) % TABLE_SIZE;
}

// 插入关键字到散列表
void insertKey(std::vector<int>& table, int key) {
    int hashValue = hashFunction(key);
    int i = 0;

    while (table[hashValue] != -1) {
        // 冲突处理：线性探测
        i++;
        hashValue = linearProbe(hashValue, i);
    }

    // 插入关键字
    table[hashValue] = key;
}

// 查找关键字在散列表中的位置
int searchKey(const std::vector<int>& table, int key) {
    int hashValue = hashFunction(key);
    int i = 0;

    while (table[hashValue] != key && table[hashValue] != -1) {
        // 冲突处理：线性探测
        i++;
        hashValue = linearProbe(hashValue, i);
    }

    if (table[hashValue] == key) {
        return hashValue; // 找到关键字的位置
    }
    else {
        return -1; // 关键字不存在
    }
}

// 打印散列表
void printTable(const std::vector<int>& table) {
    std::cout << "散列表内容：[";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i] != -1) {
            std::cout << table[i];
        }
        else {
            std::cout << " ";
        }

        if (i < TABLE_SIZE - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    // 初始化散列表，使用-1表示空槽位
    std::vector<int> hashTable(, -1);

    // 构造散列表
    std::vector<int> keys = { 47, 7, 29, 11, 16, 92, 22, 8, 3 };
    for (int key : keys) {
        insertKey(hashTable, key);
    }

    // 打印散列表
    printTable(hashTable);

    // 进行查找
    int searchKey1 = 16;
    int result1 = searchKey(hashTable, searchKey1);

    if (result1 != -1) {
        std::cout << "关键字 " << searchKey1 << " 在散列表中的位置是：" << result1 << std::endl;
    }
    else {
        std::cout << "关键字 " << searchKey1 << " 不存在于散列表中。\n";
    }

    int searchKey2 = 15;
    int result2 = searchKey(hashTable, searchKey2);

    if (result2 != -1) {
        std::cout << "关键字 " << searchKey2 << " 在散列表中的位置是：" << result2 << std::endl;
    }
    else {
        std::cout << "关键字 " << searchKey2 << " 不存在于散列表中。\n";
    }

    return 0;
}

#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    // 输入待排数据
    std::cout << "输入数据个数：";
    int n;
    std::cin >> n;

    std::vector<int> data(n);
    std::cout << "输入数据：";
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    // 打印原始数据
    std::cout << "原始数据：";
    printArray(data);

    // 使用直接插入排序
    insertionSort(data);

    // 打印排序结果
    std::cout << "排序结果：";
    printArray(data);

    return 0;
}