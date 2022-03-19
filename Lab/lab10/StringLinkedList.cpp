/*
 * Linked lists of strings.
 *
 * (c) Mark A. Sheldon, Tufts University, Spring 2018
 *
 * Updated: Spring 2021
 */
 //Qing Cheng
 //successfully implemented functions: isEmpty, addToFront, removeFront, 
 //firstElement, length, print, printArtistically

#include <iostream>
#include <stdexcept>

#include "StringLinkedList.h"

using namespace std;

/*
 * Useful functions for allocating a new Node on the heap
 * and initializing it.
 * Native C++ speakers would make Node constructors for this.
 *
 * StringLinkedList:: is required before the function, because
 * C++ hasn't realized this function is in the class yet.
 */
StringLinkedList::Node *StringLinkedList::newNode(string s, Node *next)
{
        Node *result = new Node;

        result->element = s;
        result->next    = next;

        return result;
}

StringLinkedList::Node *StringLinkedList::newNode(string s)
{
        return newNode(s, nullptr);
}

/*
 * Initialize an empty list
 */
StringLinkedList::StringLinkedList()
{
    front = nullptr;
}

/*
 * Reclaim all heap-allocated data associated with list
 */
StringLinkedList::~StringLinkedList()
{
        // TODO:  free all heap storage
}

/*
 * Return true if the list is empty, false otherwise
 */ 
bool StringLinkedList::isEmpty()
{
        if (front == nullptr)
            return true;
        else
            return false; 
}

/*
 * Add the given string to the front of the list
 */
void StringLinkedList::addToFront(string s)
{
        Node *new_node = newNode(s, front);
        front = new_node;
}

/*
 * Remove the first element (and associated node) from the list
 * Assumes the list is non-empty.
 */
void StringLinkedList::removeFirst()
{
        front = front->next; 
}

/*
 * Return first element in the list.
 * Assume list is non-empty.
 */
string StringLinkedList::firstElement()
{
        return front->element;
}

/*
 * Print the list elements between square brackets, separated
 * by commas.  E. g.,  [] is the empty list.  
 * [monarch, swallowtail, peacock] is a list of three strings.
 *
 * There is no newline at the end.
 */
void StringLinkedList::print()
{
    Node *temp = front; 
    cout << "[";
    while (temp != nullptr)
    {
        cout << temp->element; 
        temp = temp->next; 
        if (temp != nullptr)
            cout << ", ";
    }
    cout << "]";
}

/*
 * Return the length of the list.
 * Do this with a loop here.
 * If you have time, you can re-write this using a recursive helper
 * function that takes a pointer to a Node as an argument.
 */
int StringLinkedList::length()
{
        // TODO:  replace this with a correct definition
        //        First, just write a loop here.  Test it.
        //        Then use length(front), which should be
        //        written recursively.'
        int counter = 0;
        Node *temp = front;
        while (temp != nullptr)
        {
            counter++;
            temp = temp->next;            
        }
        return counter;
}

/*
 * Add the given string to the back of the list.
 */
void StringLinkedList::addToBack(string s)  
{
    cout <<"Not yet implemented " << endl;
}

/*
 * Add the given string to the list so that it is at the given
 * position.  Are you going to check the validity of the position
 * somehow? 
 */
void StringLinkedList::addAtPosition(string s, int position)
{
    cout << "not yet implemendted" << endl;
}

/*
 * Remove the string from the list at the current position
 */
void StringLinkedList::removeFromPosition(int position)
{
        // TODO if you have time
        cout << "Not yet implemented" << endl;
}

/*
 * Recursively calculate length
 */
int StringLinkedList::length(Node *current)
{
        // TODO if you have time
        cout << "Not yet implemented" << endl;
        return -1;
}

/*
 * Print the list in a more (ASCII)artistic fashion.
 * The empty list prints as ()
 * A 3-element list prints like this:
 * "monarch" ~> "swallowtail" ~> "peacock" ~> ()
 */
void StringLinkedList::printArtistically()
{
        
        Node *temp = front; 
        while (temp != nullptr)
        {
            printArtistically(temp);
            temp = temp->next;
        }
        cout << "()";        
}

/*
 * Print a list in the artistic fashion described above starting at
 * given node.
 */
void StringLinkedList::printArtistically(Node *current)
{
    cout << "\"" << current->element << "\"" << " ~> " ;
}

/*
 * Remove all occurrences of given string, s from the list
 */
void StringLinkedList::remove(string s)
{
        front = removeRec(s, front);
}

/*
 * Remove the first occurrence of s from the list starting at
 * firstNode.
 * Return a pointer to the first node in the updated list.
 * If s does not occur in list, no change is made and firstNode is
 * returned. 
 */
StringLinkedList::Node *StringLinkedList::removeRec(string s, Node *firstNode)
{
        // TODO if you have time
        //      Replace this body with a recursive solution
        cout << "Not yet implemented" << endl;
        return nullptr;
}

