//
//  TestFile for the ASSIGNMENT 4
//
//  Created by Jasmine Jans on 3/3/14
//
//

#include "List.h"
#include "ListNode.h"
#include <iostream>

int main()
{
    List* list1 = new List();
    
    cout<<"fill list to a size 7"<< endl;
    list1->insert(1,4);
    list1->insert(2,5);
    list1->insert(3,9);
    list1->insert(4,2);
    list1->insert(5,5);
    list1->insert(6,1);
    list1->insert(7,7);
    cout<<"print size"<< endl;
    cout << list1->getSize() <<endl;
    cout<< "call is empty on non empty list" << endl;
    cout<<list1->isEmpty()<< endl;
    cout<<"display list"<< endl;
    list1->display();
    cout<<"mergesort"<<endl;
    list1->sort_mergesort();
    cout<<"display mergesort"<<endl;
    list1->display();
    cout<<"remove item at 1. then remove item at 5 (formerly at 6)"<< endl;
    list1->remove(1);
    list1->remove(5);
    cout<<"print size after 2 removes"<<endl;
    cout << list1->getSize() << endl;
    cout<<"display new list"<<endl;
    list1->display();
    list1->insert(3, 13);
    list1->insert(5,8);
    list1->insert(3,1);
    cout<<"mergesort"<<endl;
    list1->sort_mergesort();
    list1->display();
    cout<< "remove remaining items"<<endl;
    list1->remove(1);
    list1->remove(1);
    list1->remove(1);
    list1->remove(1);
    list1->remove(1);
    list1->remove(1);
    list1->remove(1);
    list1->remove(1);
    cout<<"print size of now empty list"<<endl;
    cout<<list1->getSize()<<endl;
    cout<<"call is empty on empty list"<<endl;
    cout<<list1->isEmpty()<<endl;
}

