//
//  linked list implementation.cpp


#include <iostream>
#include<climits>
using namespace std;

//implementation of Node class
class Node{
    //find and correct the error in implementation Node class
public:
    int data;
    Node*next;
    
    Node(int data){
        this.data=data;
        this.next=NULL;
    }
};

int main(){
    //statically
    Node n1(1);
    Node*head=&n1;
    Node n2(2);
    n1.next=&n2;
    cout<<n1.data<<" "<<n2.data<<endl;
    //dynamically
    Node*n3=new Node(3);
    n2.next=n3;
    Node*n4=new Node(4);
    n3->next=n4;
    return 0;
}
