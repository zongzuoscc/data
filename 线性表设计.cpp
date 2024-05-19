#include <iostream>
using namespace std;

// 定义链表节点结构
typedef struct node {
    int data;          // 存储节点的数据
    struct node* next; // 指向下一个节点的指针
} NODE;

// 反转链表函数
NODE* reverseList(NODE* head) {
    NODE* prev = NULL;  // 前一个节点指针，初始为NULL
    NODE* curr = head;     // 当前节点指针，从head开始
    while (curr != NULL) {
        NODE* next = curr->next; // 保存下一个节点
        curr->next = prev;       // 当前节点指向前一个节点
        prev = curr;             // 更新前一个节点为当前节点
        curr = next;             // 更新当前节点为下一个节点
    }
    return prev; // 返回反转后的新链表头节点
}

// 找到链表的中间节点
NODE* findMiddle(NODE* head) {
    NODE* slow = head; // 慢指针
    NODE* fast = head; // 快指针
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // 慢指针每次走一步
        fast = fast->next->next; // 快指针每次走两步
    }
    return slow; // 返回慢指针所在的节点，即为中间节点
}

// 重新排列链表
void rearrangeList(NODE* head) {
    if (head == NULL || head->next == NULL) return;

    // 找到链表中间节点并拆分链表
    NODE* middle = findMiddle(head);
    NODE* secondHalf = middle->next;
    middle->next = NULL; // 切断链表

    // 反转后半部分链表
    secondHalf = reverseList(secondHalf);

    // 合并前后两部分链表
    NODE* firstHalf = head;
    while (secondHalf != NULL) {
        NODE* temp1 = firstHalf->next; // 保存前半部分的下一个节点
        NODE* temp2 = secondHalf->next; // 保存后半部分的下一个节点

        firstHalf->next = secondHalf; // 前半部分当前节点指向后半部分当前节点
        secondHalf->next = temp1;     // 后半部分当前节点指向前半部分的下一个节点

        firstHalf = temp1;  // 更新前半部分当前节点
        secondHalf = temp2; // 更新后半部分当前节点
    }
}

// 创建新节点
NODE* createNode(int data) {
    NODE* newNode = new NODE; // 分配新节点内存
    newNode->data = data;     // 设置节点数据
    newNode->next = NULL;  // 初始化指向下一个节点的指针
    return newNode;           // 返回新创建的节点
}

// 输出链表
void printList(NODE* head) {
    NODE* temp = head; // 临时指针，用于遍历链表
    while (temp != NULL) {
        cout << temp->data << " -> "; // 输出当前节点数据
        temp = temp->next;            // 移动到下一个节点
    }
    cout << "NULL" << endl; // 表示链表结束
}

int main() {
    int n;
    a:cout << "请输入链表节点数: ";
    cin >> n;
    if (n <= 0) {
        cout << "链表节点数必须大于0。" << endl;
        goto a;
    }

    NODE* head = NULL; // 链表头指针
    NODE* tail = NULL; // 链表尾指针

    cout << "请输入链表节点值: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        NODE* newNode = createNode(data);
        if (head == NULL) {
            head = newNode; // 初始化链表头
            tail = newNode; // 初始化链表尾
        } else {
            tail->next = newNode; // 链表尾指向新节点
            tail = newNode;       // 更新链表尾
        }
    }

    cout << "原始链表:\n";
    printList(head);

    rearrangeList(head);

    cout << "重新排列后的链表:\n";
    printList(head);

    return 0;
}
