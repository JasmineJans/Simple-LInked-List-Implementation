/**
 * This class is a representation of a listNode, the objects that a linked together in a linked list.
 This list node has a variable that holds an item of type ItemType and points to a next ListNode.
 *
 * @author Jasmine Jans (jjans@ada.gonzaga.edu) debugged with Myanna Harris
 * @version Assignment 4
 * @date March 3, 2014
 * @file ListNode.cpp
 */
#include "ListNode.h"
using namespace std;

ListNode::ListNode()
{
    item = 0;
    next = 0;
}

ItemType ListNode::getItem()
{
    return item;
}

ListNode* ListNode::getNext()
{
    return next;
}

ListNode::~ListNode()
{
    delete next;
    next=0;
}

ListNode::ListNode(const ItemType& x)
{
    item = x;
}

ListNode::ListNode(const ItemType& x, ListNode* nNode)
{
    item = x;
    next = nNode;
}

void ListNode::setNext(ListNode * nNode)
{
    next = nNode;
}

void ListNode::setItem(const ItemType& x)
{
    item=x;
}