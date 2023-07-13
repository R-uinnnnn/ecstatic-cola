#include <iostream>
using namespace std;

struct student {
    int num;
    student* next;
    student* prev;
};

student* create(int n) {
    student* head = new student;
    head->num = 1;
    head->next = nullptr;
    head->prev = nullptr;
    
    student* current = head;

    for (int i = 2; i <= n; i++) {
        student* newNode = new student;
        newNode->num = i;
        newNode->next = nullptr;
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    // 构建循环链表
    current->next = head;
    head->prev = current;

    return head;
}

void find(student* head, int* num) {
    student* current = head;
    int count = 1;

    while (current->next != current) {
        // 数到第 3 的倍数的人
        for (int i = 1; i < 3; i++) {
            current = current->next;
        }

        // 当前节点出列
        num[count] = current->num;
        count++;

        student* eliminated = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current = current->next;

        delete eliminated;
    }

    // 最后留下的人
    num[count] = current->num;
    num[0] = count;
    delete current;
}

int main() {
    int count;
    cin >> count;
    getchar();
    int* num = new int[count + 1];
    student* p = create(count);
    find(p, num);

    for (int i = 1; i < num[0]; i++) {
        cout << num[i] << " ";
    }
    cout << num[num[0]] << endl;
    cout << num[count] << endl;

    delete[] num;
    getchar();
    return 0;
}
