#include <iostream>
using namespace std;

// ��������ڵ�ṹ
typedef struct node {
    int data;          // �洢�ڵ������
    struct node* next; // ָ����һ���ڵ��ָ��
} NODE;

// ��ת������
NODE* reverseList(NODE* head) {
    NODE* prev = NULL;  // ǰһ���ڵ�ָ�룬��ʼΪNULL
    NODE* curr = head;     // ��ǰ�ڵ�ָ�룬��head��ʼ
    while (curr != NULL) {
        NODE* next = curr->next; // ������һ���ڵ�
        curr->next = prev;       // ��ǰ�ڵ�ָ��ǰһ���ڵ�
        prev = curr;             // ����ǰһ���ڵ�Ϊ��ǰ�ڵ�
        curr = next;             // ���µ�ǰ�ڵ�Ϊ��һ���ڵ�
    }
    return prev; // ���ط�ת���������ͷ�ڵ�
}

// �ҵ�������м�ڵ�
NODE* findMiddle(NODE* head) {
    NODE* slow = head; // ��ָ��
    NODE* fast = head; // ��ָ��
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // ��ָ��ÿ����һ��
        fast = fast->next->next; // ��ָ��ÿ��������
    }
    return slow; // ������ָ�����ڵĽڵ㣬��Ϊ�м�ڵ�
}

// ������������
void rearrangeList(NODE* head) {
    if (head == NULL || head->next == NULL) return;

    // �ҵ������м�ڵ㲢�������
    NODE* middle = findMiddle(head);
    NODE* secondHalf = middle->next;
    middle->next = NULL; // �ж�����

    // ��ת��벿������
    secondHalf = reverseList(secondHalf);

    // �ϲ�ǰ������������
    NODE* firstHalf = head;
    while (secondHalf != NULL) {
        NODE* temp1 = firstHalf->next; // ����ǰ�벿�ֵ���һ���ڵ�
        NODE* temp2 = secondHalf->next; // �����벿�ֵ���һ���ڵ�

        firstHalf->next = secondHalf; // ǰ�벿�ֵ�ǰ�ڵ�ָ���벿�ֵ�ǰ�ڵ�
        secondHalf->next = temp1;     // ��벿�ֵ�ǰ�ڵ�ָ��ǰ�벿�ֵ���һ���ڵ�

        firstHalf = temp1;  // ����ǰ�벿�ֵ�ǰ�ڵ�
        secondHalf = temp2; // ���º�벿�ֵ�ǰ�ڵ�
    }
}

// �����½ڵ�
NODE* createNode(int data) {
    NODE* newNode = new NODE; // �����½ڵ��ڴ�
    newNode->data = data;     // ���ýڵ�����
    newNode->next = NULL;  // ��ʼ��ָ����һ���ڵ��ָ��
    return newNode;           // �����´����Ľڵ�
}

// �������
void printList(NODE* head) {
    NODE* temp = head; // ��ʱָ�룬���ڱ�������
    while (temp != NULL) {
        cout << temp->data << " -> "; // �����ǰ�ڵ�����
        temp = temp->next;            // �ƶ�����һ���ڵ�
    }
    cout << "NULL" << endl; // ��ʾ�������
}

int main() {
    int n;
    a:cout << "����������ڵ���: ";
    cin >> n;
    if (n <= 0) {
        cout << "����ڵ����������0��" << endl;
        goto a;
    }

    NODE* head = NULL; // ����ͷָ��
    NODE* tail = NULL; // ����βָ��

    cout << "����������ڵ�ֵ: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        NODE* newNode = createNode(data);
        if (head == NULL) {
            head = newNode; // ��ʼ������ͷ
            tail = newNode; // ��ʼ������β
        } else {
            tail->next = newNode; // ����βָ���½ڵ�
            tail = newNode;       // ��������β
        }
    }

    cout << "ԭʼ����:\n";
    printList(head);

    rearrangeList(head);

    cout << "�������к������:\n";
    printList(head);

    return 0;
}
