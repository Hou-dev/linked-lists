#include <iostream>
#include <cstdlib>

using namespace std;


//	Declare in simpleLinkedList.cpp a structure 'node' which defines a single
//	node of linkedList containing integers only. Your structure should have at
//	least one variable for data section and a pointer for the next node.

struct Node {
	int data;
	Node *link;
};


class simpleLinkedList
{
public:

	simpleLinkedList() {
		count = 0;
		first = NULL;
		last = NULL;
	}
	~simpleLinkedList() {
		Node *temp; //pointer to deallocate the memory
					//occupied by the node
		while (first != NULL) //while there are nodes in the list
		{
			temp = first; //set temp to the current node
			first = first->link; //advance first to the next node
			delete temp; //deallocate the memory occupied by temp
		}
		last = NULL; //initialize last to NULL; first has already
					 //been set to NULL by the while loop

		count = 0;
	}
	void add(int data) {
		Node* node = new Node();
		node->data = data;
		node->link = NULL;

		if (first == NULL) {
			first = node;
			last = node;
			count++;
		}
		else {
			last->link = node;
			last = node;
			count++;
		}
	}
	void print() {
		Node* temp = first;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->link;
		}
	}
	int length() {
		return count;
	}
	int itemAt(int location) {
		Node* node = new Node();


		if (location == 0) { // insert in the first position
			return first->data;
		}
		else if (location<count) {
			int localCount = 0;
			Node *current = first;
			while (localCount<(location)) {
				current = current->link;
				localCount++;
			}
			return current->data;
		}
		else
			cout << "Can not find item at location = " << location << "! List length is " << count << endl;
	}
	void insertAt(int insertItem, int location) {
	    Node* temp1 = new Node();
	    temp1->data=insertItem;
	    temp1->link = NULL;
	    if(location==1){
            temp1->link = first;
            first = temp1;
            return;
	    }
	    Node* temp2 = first;
	    for(int i =0; i<location-2;i++){
            temp2=temp2->link;
	    }
	    temp1->link = temp2->link;
	    temp2->link = temp1;
	    count++;
	}// insert a node at a specific position in the list
	void remove(int removeItem) {
	  Node *current;
	  Node *trailCurrent;
	  bool found;
      if (first == NULL){
        cout<<"We cannot delete from an empty list"<<endl;
      }
      else{
        current = first;
        found = false;
        while (current!=NULL && !found){
            if(current->data ==removeItem){
                found=true;
            }
            else{
                trailCurrent=current;
                current=current->link;
            }
        }
        if(current==NULL){
            cout<<"Number is not in list"<<endl;
        }
        else{
            if (current->data==removeItem){
                if(first==current){
                    first = first->link;
                    if(first==NULL){
                        last=NULL;
                    }
                    delete current;
                }
                else{
                    trailCurrent->link = current->link;
                    if(current==last){
                        last = trailCurrent;
                    }
                    delete current;
                }
                count--;
            }
            else{
                cout<<"Item not in list"<<endl;
            }
        }
      }

	}// delete a node containing specific item

private:

    int count;      //variable to store the number of list elements
    Node* first;    //pointer to the first node of the list
    Node* last;     //pointer to the last node of the list
};
