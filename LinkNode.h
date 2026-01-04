#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class LinkNode
{
public:
	// 自定义一个链表 从0到n-1
	ListNode* createLinkList(int n)
	{
		ListNode* Head = new ListNode(0);
		Head->next = nullptr;
		Head->val = 0;
		ListNode* pre = Head;  //指向下一个节点的过渡值
		for (int i = 1; i < n; i++)
		{
			ListNode* temp = new ListNode(i);
			pre->next = temp;
			pre = temp;
			temp->next = nullptr;
		}
		return Head;
	}


	// 203 移除链表元素
	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;
		while (cur->next != nullptr) {
			if (cur->next->val==val)
			{
				ListNode* temp_val = cur->next;
				cur->next = cur->next->next;
				delete temp_val;
			}
			else
			{
				cur = cur->next;
			}
		}
		head = dummyHead->next;
		delete dummyHead;
		return head;
	}


	// 初始化一个链表
	LinkNode()
	{
		_dummyhead = new ListNode(0);
		_size = 0;
	}


	// 获取链表中下标为 index 的节点的值 如果下标无效，则返回 -1 
	int get(int index) {
		if (index < 0 || index > (_size-1))
		{
			return -1;
		}
		ListNode* cur = _dummyhead->next;
		while (index--)
		{
			cur = cur->next;
		}
		return cur->val;
	}


	// 将一个值为 val 的节点插入到链表中第一个元素之前
	// 在插入完成后，新节点会成为链表的第一个节点
	void addAtHead(int val)
	{
		ListNode* cur = new ListNode(val);
		cur->next = _dummyhead->next;
		_dummyhead->next = cur;
		_size++;
	}


	//  将一个值为 val 的节点追加到链表中作为链表的最后一个元素
	void addAtTail(int val)
	{
		ListNode* tmp = new ListNode(val);
		ListNode* cur = _dummyhead;
		int size = _size;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = tmp;
		_size++;
	}

	// 将一个值为 val 的节点插入到链表中下标为 index 的节点之前
	// 如果 index 等于链表的长度，那么该节点会被追加到链表的末尾
	// 如果 index 比长度更大，该节点将 不会插入 到链表中
	// 如果 index 小于0，则在头部插入节点
	void addAtIndex(int index, int val)
	{
		if (index > _size) return;
		if (index < 0) index = 0;
		ListNode* tmp = new ListNode(val);
		ListNode* cur = _dummyhead;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		tmp->next = cur->next;
		cur->next = tmp;
		_size++;
	}


	// 如果下标有效，则删除链表中下标为 index 的节点
	void deleteAtIndex(int index)
	{
		if (index < 0 || index >(_size - 1))
		{
			return;
		}
		ListNode* cur = _dummyhead;
		while (index--)
		{
			cur = cur->next;
		}
		ListNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		tmp = nullptr;
		_size--;
	}


	// 给一个单链表的头节点 head 反转链表 返回反转后的链表
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		ListNode* pre = new ListNode(0);
		if (cur == nullptr)
		{
			return nullptr;
		}
		while (cur != nullptr)
		{
			ListNode* tmp = cur->next;
			if (cur==head)
			{
				cur->next = nullptr;
				pre = cur;
				cur = tmp;
			}
			else 
			{
				cur->next = pre;
				pre = cur;
				cur = tmp;
			}
		}
		return pre;
	}


	// 两两交换其中相邻的节点
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;
		if (cur->next==nullptr)
		{
			return nullptr;
		}
		while (cur->next!=nullptr && cur->next->next!=nullptr)
		{
			ListNode* leftcur = cur->next;
			ListNode* rightcur = cur->next->next;

			cur->next = rightcur;
			leftcur->next = rightcur->next;
			rightcur->next = leftcur;

			cur = leftcur;	
		}
		ListNode* result = dummyHead->next;
		delete dummyHead;
		return result;
	}


	// 删除倒数第n个节点
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* slowcur = dummyHead;
		ListNode* fastcur = dummyHead;
		while (n > 0)
		{
			fastcur = fastcur->next;
			n--;
		}
		while (fastcur->next != nullptr)
		{
			slowcur = slowcur->next;
			fastcur = fastcur->next;
		}

		ListNode* tmp = slowcur->next;
		slowcur->next = tmp->next;
		delete tmp;

		ListNode* result = dummyHead->next;
		delete dummyHead;
		return result;
	}



	// 链表相交
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* curA = headA;
		ListNode* curB = headB;
		int lenA = 0;
		int lenB = 0;

		while (curA!=nullptr)
		{
			curA = curA->next;
			lenA++;
		}
		while (curB != nullptr)
		{
			curB = curB->next;
			lenB++;
		}

		curA = headA;
		curB = headB;

		if (lenA < lenB)
		{
			swap(lenA, lenB);
			swap(curA, curB);
		}

		int len = lenA - lenB;

		while (len--)
		{
			curA = curA->next;
		}

		while (curA!=nullptr)
		{
			if (curA == curB)
			{
				return curA;
			}
			curA = curA->next;
			curB = curB->next;
		}
		return NULL;
	}


	// 环形链表 II
	ListNode* detectCycle(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast!=nullptr && fast->next!=nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow==fast)
			{
				ListNode* index1 = head;
				ListNode* index2 = fast;
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2;
			}
		}
		return nullptr;
	}


	// 打印链表
	void printLinkList(ListNode* head)
	{
		ListNode* temp = head;
		int val = 0;
		while (temp != nullptr)
		{
			val = temp->val;
			cout << val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

private:
	ListNode* _dummyhead;
	int _size;

};
