//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//template<class T>
//class Vector
//{
//private:
//	T* data;						//����ָ��
//	int theSize;					//�����е�����Ԫ�ظ���
//	int theMax;						//��������
//	void Error(const char* cs)const { cout << cs << endl; exit(1); }//������Ϣ����
//public:
//	explicit Vector(int n = 0) :theSize(0), theMax(n + SPARE_MAX)
//	{
//		if (theMax > 0) data = new T[theMax];
//	}
//	Vector(const Vector& v) :data(NULL), theMax(0) { operator=(v); }//�������캯��
//	~Vector(void) { delete[]data; }
//	Vector& operator=(const Vector<T>& v);		//������ֵ����
//	T& operator[](int id) { return(data[id]); }	//�±����������
//	const T& operator[](int id)const { return(data[id]); }//�������±����������
//	bool Empty(void)const { return(theSize == 0); }	//�п�
//	int Size(void)const { return(theSize); }		//�����ݸ���
//	int Max(void)const { return(theMax); }			//����������
//	void Push_back(const T& item);				//β��
//	void Pop_back(void);						//βɾ
//	const T& Back(void)const;					//����βԪ�ص�����
//	const T& Front(void)const;					//������ʼԪ�ص�����
//	void Clear(void) { theSize = 0; }				//ɾ����������Ԫ��
//	void Reserve(int newMax);					//������������ΪnewtheMax������ԭ������
//	void Resize(int newSize, const T& item = T());	//�����ݸ�������ΪnewtheSize��ԭ�������ݱ����������ֵΪitem
//	enum { SPARE_MAX = 16 };							//ö�ٳ�����ʾ������С����
//	//����������
//	typedef T* iterator;						//������
//	typedef const T* const_iterator;			//ָ��const�����ĵ�����
//	iterator begin() { return &data[0]; }			//ʹ������ָ��������ʼλ��
//	const_iterator begin()const { return &data[0]; }
//	iterator end() { return(&data[theSize]); }	//ʹ������ָ����������λ��
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
//Vector<T>& Vector<T>::operator=(const Vector<T>& v)//������ֵ����
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
//void Vector<T>::Push_back(const T& item)//β��
//{
//	if (theSize == theMax)			//����ռ�������������Ҫ����������
//		Reserve(2 * theMax + 1);
//	data[theSize++] = item;		//����Ԫ�ص�β�������ݸ�����1
//}
//
//template<class T>				//ģ�������
//Vector<T>::iterator				//����ֵ����
//Vector<T>::Erase(iterator itr)	//ɾ��ָʾ��ָ���Ԫ��
//{
//	if (theSize == 0)				//����Ƿ��ǿձ�			
//		Error("Erase:an empty Vector!");
//	if (itr<begin() || itr>end() - 1)//���ɾ��λ���Ƿ�Ϸ�					
//		Error("Erase: out of illegal!");
//	for (iterator p = itr; p != end(); ++p)
//		*p = *(p + 1);
//	theSize--;
//	return(itr);
//}
//template<class T>				//ģ�������
//Vector<T>::iterator				//����ֵ����
//Vector<T>::Insert(iterator itr, const T& item)//��Ԫ��item���뵽ָʾ��ָ���λ��
//{
//	if (theSize == theMax)
//		Reserve(2 * theMax + 1);	//����ռ�������������Ҫ����������
//	if (itr<begin() || itr>end())	//������λ���Ƿ�Ϸ�
//		Error("Insert:out of range");
//	for (iterator p = end(); p != itr; --p)//��βԪ�ص�����λ����Ԫ�������ƶ�һ��λ��
//		*p = *(p - 1);
//	*itr = item;					//����Ԫ�ص�ָ��λ��
//	theSize++;					//���ݸ�����1
//	return(itr);
//}
//template<class T>
//void Vector<T>::Pop_back(void)	//βɾ
//{
//	if (theSize == 0)
//		Error("Empty Vector!");
//	theSize--;
//}
//
//template<class T>
//const T& Vector<T>::Back(void)const//����βԪ�ص�����
//{
//	if (theSize == 0)
//		Error("Empty Vector!");
//	return(data[theSize - 1]);
//}
//template<class T>
//const T& Vector<T>::Front(void)const//������ʼԪ�ص�����
//{
//	if (theSize == 0)
//		Error("Empty Vector!");
//	return(data[0]);
//}
//template<class T>
//void Vector<T>::Reserve(int newMax)	//������������ΪnewtheMax������ԭ������						
//{
//	if (newMax < theSize)
//		return;
//	T* old = data;				//��ָ��ָ�򼴽��ͷŵ�����
//	data = new T[newMax];			//���·���������ռ�		
//	for (int i = 0; i < theSize; i++)	//��ԭ�����е����ݿ���������
//		data[i] = old[i];
//	theMax = newMax;				//�޸�������¼
//	delete[]old;				//�ͷ�ԭ����ռ�			
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
//        v.Push_back(a[i]);//������a��Ԫ�����뵽v��
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


//���Ա�ʵ��--1

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
//            // ���������������������
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
//    // ������Ԫ�ز��뵽������
//    for (int i = 0; i < 10; ++i) {
//        myVector.PushBack(a[i]);
//    }
//
//    // ���������ֵΪ9��Ԫ�صĸ���
//    int num = myVector.Count(9);
//    std::cout << "The count of 9: " << num << std::endl;
//
//    return 0;
//}

//���Ա�ʵ��--2
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
//    // ������Ԫ�ز��뵽������
//    for (int i = 0; i < 10; ++i) {
//        myList.Push_back(a[i]);
//    }
//
//    // ɾ��������ֵ��С��Ԫ�ز����ȫ��Ԫ��
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

    //����ֵ������������
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

    //ʹ�õݹ�ִ���������
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
public:
    BinarySearchTree() : root(nullptr) {}

    // ����ֵ������������
    void insert(int value) {
        root = insert(root, value);
    }

    // ʹ�����������ִ���������
    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // �����������
    class Iterator {
    private:
        std::stack<TreeNode*> s;
        TreeNode* current;

        //��ʼ��ջ�԰��������·��
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

        // ����Ƿ��и���Ԫ����Ҫ����
        bool hasNext() const {
            return !s.empty() || current != nullptr;
        }

        // ��ȡ�����������һ��Ԫ��
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
    // �������������������
    Iterator getInorderIterator() {
        return Iterator(root);
    }
};

int main() {
    BinarySearchTree bst;
    // ������������в���ֵ
    bst.insert(8);
    bst.insert(11);
    bst.insert(10);
    bst.insert(3);
    bst.insert(2);
    bst.insert(6);
    bst.insert(4);
    bst.insert(5);
    // ʹ�õ�����ִ���������
    BinarySearchTree::Iterator iterator = bst.getInorderIterator();
    std::cout << "������������";
    while (iterator.hasNext()) {
        std::cout << iterator.next() << " ";
    }
    std::cout << std::endl;

    return 0;
}

// ɢ�к���������������
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// ����̽�ⷨ�����ͻ
int linearProbe(int hashValue, int i) {
    return (hashValue + i) % TABLE_SIZE;
}

// ����ؼ��ֵ�ɢ�б�
void insertKey(std::vector<int>& table, int key) {
    int hashValue = hashFunction(key);
    int i = 0;

    while (table[hashValue] != -1) {
        // ��ͻ��������̽��
        i++;
        hashValue = linearProbe(hashValue, i);
    }

    // ����ؼ���
    table[hashValue] = key;
}

// ���ҹؼ�����ɢ�б��е�λ��
int searchKey(const std::vector<int>& table, int key) {
    int hashValue = hashFunction(key);
    int i = 0;

    while (table[hashValue] != key && table[hashValue] != -1) {
        // ��ͻ��������̽��
        i++;
        hashValue = linearProbe(hashValue, i);
    }

    if (table[hashValue] == key) {
        return hashValue; // �ҵ��ؼ��ֵ�λ��
    }
    else {
        return -1; // �ؼ��ֲ�����
    }
}

// ��ӡɢ�б�
void printTable(const std::vector<int>& table) {
    std::cout << "ɢ�б����ݣ�[";
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
    // ��ʼ��ɢ�б�ʹ��-1��ʾ�ղ�λ
    std::vector<int> hashTable(, -1);

    // ����ɢ�б�
    std::vector<int> keys = { 47, 7, 29, 11, 16, 92, 22, 8, 3 };
    for (int key : keys) {
        insertKey(hashTable, key);
    }

    // ��ӡɢ�б�
    printTable(hashTable);

    // ���в���
    int searchKey1 = 16;
    int result1 = searchKey(hashTable, searchKey1);

    if (result1 != -1) {
        std::cout << "�ؼ��� " << searchKey1 << " ��ɢ�б��е�λ���ǣ�" << result1 << std::endl;
    }
    else {
        std::cout << "�ؼ��� " << searchKey1 << " ��������ɢ�б��С�\n";
    }

    int searchKey2 = 15;
    int result2 = searchKey(hashTable, searchKey2);

    if (result2 != -1) {
        std::cout << "�ؼ��� " << searchKey2 << " ��ɢ�б��е�λ���ǣ�" << result2 << std::endl;
    }
    else {
        std::cout << "�ؼ��� " << searchKey2 << " ��������ɢ�б��С�\n";
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
    // �����������
    std::cout << "�������ݸ�����";
    int n;
    std::cin >> n;

    std::vector<int> data(n);
    std::cout << "�������ݣ�";
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    // ��ӡԭʼ����
    std::cout << "ԭʼ���ݣ�";
    printArray(data);

    // ʹ��ֱ�Ӳ�������
    insertionSort(data);

    // ��ӡ������
    std::cout << "��������";
    printArray(data);

    return 0;
}