/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

/* Alternate recursive solution
Node* flatten(Node* head, Node* rest = nullptr) {
  if (!head) return rest;
  head->next = flatten(head->child, flatten(head->next, rest));
  if (head->next) head->next->prev = head;
  head->child = nullptr;
  return head;
}
*/

class Solution {
public:
    Node* flatten(Node* head) {
	for (Node* h = head; h; h = h->next)
	{
		if (h->child)
		{
			Node* next = h->next;
			h->next = h->child;
			h->next->prev = h;
			h->child = NULL;
			Node* p = h->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
	}
	return head;
}
};