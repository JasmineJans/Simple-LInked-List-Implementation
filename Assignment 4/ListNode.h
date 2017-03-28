/**
 * This class is a representation of a listNode, the objects that a linked together in a linked list.
   This list node has a variable that holds an item of type ItemType and points to a next ListNode.
 *
 * @author Jasmine Jans (jjans@ada.gonzaga.edu) debugged with Myanna Harris
 * @version Assignment 4
 * @date March 3, 2014
 * @file ListNode.h
 */

/** @file ListNode.h */

#ifndef _LISTNODE
#define _LISTNODE

typedef int ItemType;

/** @class ListNode
 * object node for LinkedList. */

class ListNode
{
    //List has access to all of ListNodes protected and private variables.
    friend class List;
public:
    /**
     * This method returns the item stored in the node
     *@pre node is not equal to node.
     *@post none.
     *@returns the item stored in that node.
     */
     ItemType getItem();
    /**
     * This method returns next node that this current node is pointing to.
     *@pre node is not equal to null
     *@post none.
     *@returns the next node that this current node is pointing to.
     */
     ListNode* getNext();
    
    //default constructor
    //sets item and next to 0; (NULL)
    ListNode();
    //non default constructor
    //sets item to ItemType x
    ListNode(const ItemType & x);
    //non defauly constructor
    //sets next to nNode and item to x
    ListNode(const ItemType & x, ListNode * nNode);
    
    /**
     * This method sets the next node the current node is poinintg to to nNode.
     *@pre none.
     *@post none.
     *@param ListNode* nNode is the new node that this node will point to.
     */
    void setNext(ListNode * nNode);
    
    /**
     * This method sets the item of the current node to x.
     *@pre node is not NULL.
     *@post none.
     *@param ItemType x is the item node is being set to.
     */
    void setItem(const ItemType & x);
    
    //destructor of ListNode
    //deletes next and sets item to 0
    ~ListNode();
    
    private :
    ItemType item; // A data item
    ListNode* next; // Pointer to next node
}; // end Node

#endif