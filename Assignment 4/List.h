/**
 * This class is a representation of a LinkedList, that uses pointers to connect ListNode objects.
 This list can hold unlimited nodes and you can insert remove and get nodes and their items from out of the list.
 *
 * @author Jasmine Jans (jjans@ada.gonzaga.edu) debugged with Myanna Harris
 * @version Assignment 4
 * @date March 3, 2014
 * @file List.cpp
 */

#ifndef _LIST
#define _LIST
using namespace std;

#include <iostream>
#include <algorithm>
#include "ListNode.h"


class List
{
public:
    //Constructor and Destructors
    
    //Default Construtor
    //sets size to 0 and head to NULL
    List();
    
    //copy constructor
    //creates a whole new copy of the list given thorugh the parameter.
    List(const List* l);
    
    //destructor
    //removes all the nodes in the list and sets everything back to NULL and zero.
    ~List();
    
    /**
     * This method check to see if the Linked LIst is empty
     *@pre a linked list exists.
     *@post none.
     *@returns true or false based on if the list is Empty or not
     */
    bool isEmpty() const;
    
    /**
     * This method returns the size of a linked list.
     *@pre none.
     *@post none.
     *@returns the size of the linkedlist
     */
    int getSize() const;
    
    /**
     * This method inserts the item x in position pos.
     *@pre the position is within the range of 1 and size.
     *@post none.
     *@param pos is the postion the item is to be inserted.
     *@param x is the value of the item to be inserted in the List
     */
    void insert(int pos, const ItemType& x);
    
    /**
     * This method removes the node at position pos.
     *@pre the param pos falls between 1 and size.
     *@post none.
     *@param pos is the position of the node you want to remove
     */
    void remove(int pos);
    
    /**
     * This method displays the nodes in the list
     *@pre a list exists.
     *@post none.
     */
    void display() const;
    
    /**
     * This method sorts the list using the mergesort algorithm
     *@pre the list exists.
     *@post none.
     */
    void sort_mergesort();
    
    
private:
    ListNode* ptrTo(int pos) const; //helper method makes a pointer to a given position.
    int get(int pos) const; //private method that gets the item at position pos
    int size; // the size of the list.
    ListNode * head; //pointer to the head of the list
    ListNode * mergesort(ListNode * lhead, int lsize); //helper method  called in sort_mergesort that recursivly sorts the list.
    ListNode * merge(ListNode * lhead1, ListNode * lhead2); //helper method called in mergesort that recursively merges lhead1 and lhead2 back together to sort the list.
};

#endif