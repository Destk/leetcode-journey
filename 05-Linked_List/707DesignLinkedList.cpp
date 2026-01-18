#include <iostream>
#include <limits>
struct Node{
    int val{};
    Node* next;
    Node(int x) : val(x), next(nullptr) {};
    Node(int x, Node* n) : val(x), next(n) {};
    Node() : val(0), next(nullptr) {};
};

class MyLinkedList {
private:
    int size{};
    Node* head;
public:
    MyLinkedList() : head(nullptr), size(0) {}

    int get(int index) {
        if(index >= size || index < 0) return -1;
        Node* curr = head;
        for(int i =0; i < index; ++i){
            curr=curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        Node* h = new Node(val);
        h->next = head;
        head = h;
        size++;
    }

    void addAtTail(int val) {
        if(head == nullptr){
            head = new Node(val);
            size++;
            return ;
        }
        Node* tail = head;
        Node* c = new Node(val);
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = c;
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index > size) return ;
        if(index == 0){
                Node* newNode = new Node(val);
                newNode->next = head;
                head = newNode;
                size++;
                return;
        }
        Node* tail = head;
        Node* nNode = new Node(val);
        for(int i = 0; i < index-1; ++i){
            tail = tail->next;
        }
        Node* curr = tail->next;
        tail->next = nNode;
        nNode->next = curr;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index >= size || index < 0) return;
        if(index == 0){
            Node* del = head;
            head = head->next;
            size--;
            delete del;
            return ;
        }
        Node* prev = head;
        for(int i = 0; i < index-1; ++i){
            prev = prev->next;
        }
        Node* del = prev->next;
        prev->next = del->next;
        delete del;
        size--;
    }
};

void inp(int& v, int& i){
	bool s = true;
	while(s){
	std::cout<<"Введите индекс\n";
	std::cin>>i;
	if(std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout<<"Ошибка ввода, попробуйте еще раз\n";
		continue;
	}
	std::cout<<"Введите значение\n";
        std::cin>>v;
        if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Ошибка ввода, попробуйте еще раз\n";
                continue;
        }
	else{
		s = false;
	    }
    }
}

int main(){
	char stop{};
    MyLinkedList l;
do{
	int i{}, v{};
	inp(v,i);
	l.addAtHead(v);
    std::cout<<l.get(i)<<'\n';
    inp(i,v);
    l.addAtIndex(i,v);
    std::cout<<l.get(i)<<'\n';
    l.deleteAtIndex(i);
    std::cout<<l.get(i)<<'\n';
	std::cout<<"Продолжить?(y/n)\n";
	std::cin>> stop;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}while(stop == 'y' || stop == 'Y');
return 0;
}
