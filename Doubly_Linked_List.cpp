#include <iostream>
using namespace std;

class doubly_linked_list{
    
  struct node{
   int item;
   node *next;
   node *prev; 
  }; 
private:
  node *first, *last;
  int length;
  
public:
    doubly_linked_list(){
        first = last = NULL;
        length = 0;
    }
   bool isEmpty(){
       return (first == NULL);
   }
   void insertatFirst(int element){
       node *newnode = new node;
       newnode->item = element;
       if (length == 0){
           first = last = newnode;
           newnode->next = newnode->prev = NULL;
       }else{
           newnode->next = first;
           newnode->prev = NULL;
           first->prev = newnode;
           first = newnode;
       }
       length++;
   }

    void insertatLast(int element){
        node *newnode = new node;
        newnode->item = element;
        if(length == 0){
            first = last = newnode;
            newnode->next = newnode->prev = NULL;
        }else{
        newnode->next = NULL;
        newnode->prev = last;
        last->next = newnode;
        last = newnode;
        }
        length++;
    }
    void insertatPos(int pos, int element){
        
        if(pos < 0 || pos > length){
            cout<<"You cannot add elements "<<endl;
        }else{
            node *newnode = new node;
            newnode->item = element;
            if(pos == 0){
                insertatFirst(element);
            }else if(pos ==length){
                insertatLast(element);
            }else{
                 node *curr = first;
                 for(int i = 0; i < pos; i++){
                     curr = curr->next;
                 }
                 newnode->next = curr->next;
                 newnode->prev = curr; 
                 curr->next = newnode;
                 curr->next->prev = newnode;
                 length++;
            }
        }
    }
    void removeFirst(){
        if(length == 0){
            return;
        }else if(length == 1){
            delete first;
            first = last = NULL;
        }else{
            node *curr = first;
            first = first->next;
            first->prev = NULL;
            delete curr;
        }
        length--;
    }
    void removeLast(){
          if(length == 0){
              return;
          }else if(length == 1){
              delete first;
              first = last = NULL;
          }else{
              node *curr = last;
              last = last->prev;
              last->next = NULL;
              delete curr;
          }
          length--;
    }
        void remove(int item){
            node *curr = first->next;
            if(length == 0){
                removeFirst();
            }else{
                 
                 while(curr != NULL){
                 if(curr->item == item){
                     break;
                     curr = curr->next;
                 }
                 }
            }
                    if(curr == NULL){
                        return;
                    }else if(curr->next == NULL){
                        removeLast();
                    }else{
                 curr->next->prev = curr->prev;
                 curr->prev->next = curr->next;   
                 delete curr;
                 length--;
            }
        }
void display(){
    node *curr = first;
    cout<<"displaying List"<<"[ ";
    while(curr != NULL){
        cout<<curr->item <<" ";
        curr = curr->next; 
    }
    cout<<" ]"<<endl;
}
void displayInReverse(){
    node *curr = last;
    cout<<"Displaying list in reverse "<<"[ ";
    while(curr != NULL){
        cout<<curr->item<<" ";
        curr = curr->prev; 
    }
    cout<<" ]"<<endl;
}    
    
};
int main(){
doubly_linked_list d ;
d.insertatFirst(10);
d.insertatLast(20);
d.insertatLast(30);
d.insertatLast(40);
d.removeFirst();
d.remove(30);
d.removeLast();
d.insertatLast(23);
d.insertatLast(69);
d.display();
d.displayInReverse();
return 0;
 }