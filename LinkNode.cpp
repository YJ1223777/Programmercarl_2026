#include "LinkNode.h"

int main()
{
	//LinkNode link_node;
	//ListNode* head = link_node.createLinkList(5);
	//head = link_node.removeElements(head, 4);
	//link_node.printLinkList(head);

	//LinkNode* myLinkNode = new LinkNode();
	//myLinkNode->addAtHead(1);
	//myLinkNode->addAtHead(3);
	//myLinkNode->addAtIndex(0, 2);
	//cout << myLinkNode->get(2) << " ";
	//myLinkNode->deleteAtIndex(1);
	//cout << myLinkNode->get(0) << " ";

	LinkNode link_node;
	ListNode* head = link_node.createLinkList(3);
	//head = link_node.reverseList(head);
	//link_node.printLinkList(head);
	//head = link_node.swapPairs(head);
	//link_node.printLinkList(head);
	head = link_node.removeNthFromEnd(head, 1);
	link_node.printLinkList(head);
}
