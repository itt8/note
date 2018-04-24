#include<iostream>

using namespace std;
typedef struct node_s{
	struct node_s *prev;
	struct node_s *next;
	int  data;
}Node;

Node *invert_link(Node *head)
{
	Node *p = head;
	Node *q = nullptr;
	Node *t = nullptr;
	for(p; nullptr != p; p = p->prev){
		t = p;
		t->prev = p->next;
		t->next = q;
		q = t;
	}
	return q;
}

void link_print(Node* head){
	Node *p = head;
	for(p; nullptr != p; p = p->next){
		cout << p->data << " ";
	}
}

int main(int argc, char *argv[])
{
	Node *head = nullptr, *t = nullptr, *p = nullptr;
	for(int i = 0; i<100; i++){
		p = new Node;
		if(head == nullptr){
			head = p;
			head->prev = nullptr;
			head->next = nullptr;
			t = head;
			continue;
		}
		p->prev = t;
		t->next = p;
		p->next = nullptr;
		p->data = i;
		t = p;
	}

	link_print(head);
	cout << endl;
	cout << "now invert...\n";
	link_print(invert_link(head));
	cout << endl;
	return 0;
}

