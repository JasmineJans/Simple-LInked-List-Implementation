/**
 * This class is a representation of a LinkedList, that uses pointers to connect ListNode objects.
   This list can hold unlimited nodes and you can insert remove and get nodes and their items from out of the list.
 *
 * @author Jasmine Jans (jjans@ada.gonzaga.edu) debugged with Myanna Harris
 * @version Assignment 4
 * @date March 3, 2014
 * @file List.cpp
 */
#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
    size = 0;
    head = NULL;
}

List::~List()
{
    cout << "In List destructor" << endl;
    while(size > 0)
        remove(1);
}

void List::insert(int pos, const ItemType & x)
{
    ListNode* newPtr = new ListNode();
    if (pos == 1)
    {
        newPtr->setNext(head);
        head = newPtr;
    }
    else
    {
        ListNode* prev = ptrTo(pos - 1);
        newPtr->setNext(prev->getNext());
        prev->setNext(newPtr);
    }
    newPtr->setItem(x);
    size++;
}

ListNode* List::ptrTo(int pos) const
{
    ListNode* prev = head;
    for (int i = 1; i < pos; i++)
        prev = prev->getNext();
    return prev;
}


List::List(const List* list)
{
    size = list->size;
    if (list->head == NULL)
        head = NULL;
    else
    {
        head = new ListNode();
        head->setItem(list->head->getItem());
        ListNode* newPtr = head;
        for(ListNode* origPtr = list->head->getNext(); origPtr != NULL;
            origPtr = origPtr->getNext())
        {
            newPtr->setNext(new ListNode());
            newPtr = newPtr->getNext();
            newPtr->setItem(origPtr->getItem());
        }
        newPtr->setNext(NULL);
    }
}



bool List::isEmpty() const
{
    if (size > 0)
        return false;
    else
        return true;
}


int List::getSize() const
{
    return size;
}

void List::display() const
{
    ListNode* newPtr = head;
    while (newPtr != NULL)
    {
        cout << newPtr->getItem() << endl;
        newPtr = newPtr->getNext();
    }
}


int List::get(int pos) const
{
    
    ListNode* cur;
    
    int i = 1;
    cur = head;
    while (i < pos)
    {
        cur = cur->getNext();
        i++;
    }
    return (cur->getItem());
}

void List::remove(int pos)
{
	ListNode* cur;
	ListNode* prev;
    
    if(size==1)
    {
        head = NULL;
        cur = NULL;
        size=0;
	}
    else
    {
        if (pos == 1)
        {
            cur = head;
            head = cur->getNext();
        }
        else
        {
            prev = ptrTo(pos - 1);
            cur = prev->getNext();
            prev->setNext(cur->getNext());
        }
    
	
        cur->setNext(NULL);
        delete cur;
        cur = NULL;
        size--;
    }
}

void List::sort_mergesort()
{
    head = mergesort(head, size);
    
}

ListNode* List::mergesort(ListNode* lhead, int lsize)
{
    int length1;
    int length2;
    ListNode* headNode;
    
    if(lsize>1)
    {
        length1 = (int)lsize/2;
        length2 = lsize-length1;
        
        ListNode* head1 = lhead;
        ListNode* head2;
        ListNode* tempTail = lhead;
   
        for(int i =1; i<length1; i++)
            tempTail = tempTail->next;
       
        head2 = tempTail -> next;
        tempTail -> next = NULL;
       
        head1 = mergesort(head1, length1);
        head2 = mergesort(head2, length2);
        headNode = merge(head1, head2);
    }
    else
    {
        headNode = lhead;
    }
    
return headNode;
}

ListNode* List::merge(ListNode* lhead1, ListNode * lhead2)
{
    ListNode* newHead;
    ListNode* tempHead;
    
    if(lhead1->item <= lhead2->item)
    {
        newHead = lhead1;
        tempHead = lhead1;
        lhead1=lhead1->next;
    }
    else
    {
        newHead = lhead2;
        tempHead = lhead2;
        lhead2=lhead2->next;
    }

    while(lhead1 !=NULL || lhead2 !=NULL)
    {
        if(lhead1 == NULL)
        {
          tempHead -> next = lhead2;
          lhead2=lhead2->next;
          tempHead = tempHead->next;
        }
        else if(lhead2 == NULL)
        {
            tempHead -> next = lhead1;
            lhead1=lhead1->next;
            tempHead = tempHead->next;
        }
        else if (lhead1->item >= lhead2->item)
        {
            tempHead -> next = lhead2;
            lhead2=lhead2->next;
            tempHead = tempHead->next;
        }
        else
        {
            tempHead -> next = lhead1;
            lhead1=lhead1->next;
            tempHead = tempHead->next;
        }
            
    }
    
    return newHead;
    
}



