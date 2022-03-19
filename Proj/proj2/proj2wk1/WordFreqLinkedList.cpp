/*
 * A linked-list based implementation of a class that keeps track of 
 * word-frequecy data.
 * 
 * The data are stored as a singly-linked sequence of nodes accessed
 * from a single pointer (in the data member 'front') to the first
 * node in the list (or the nullptr if the list is empty).  Each node
 * has a word (stored as a string), and an integer representing the
 * number of times that word has been counted.
 *
 * IMPORTANT INVARIANT:
 * The words are in the list in alphabetical order. 
 *
 * Mark A. Sheldon, Tufts Uiversity, Spring 2021
 * 
 *
 * Student name: Qing Cheng  
 * Date: 04/19/2021
 *
 * Anything else you would like to include
 */

/*************  Fill in the TODO items below  *************/
/***  You may add additional private member functions   ***/
/**********************************************************/
#include <iostream>
#include <string>
#include <cstdlib>

#include "WordFreqLinkedList.h"

using namespace std;

/*
 * Purpose:  Constructor initializes an empty list
 */
WordFreqLinkedList::WordFreqLinkedList()
{
    front = nullptr; 
    numElements = 0; 
}

/*
 * Purpose:  Destructor recycles the space associated with all nodes
 *           in the list
 */
WordFreqLinkedList::~WordFreqLinkedList()
{
    while (front != nullptr)
    {
        removeFromFront();
    }
}

/*
 * Purpose:  Return the current size of the list, 
 *           i. e., the number of words/nodes in the list
 */
int WordFreqLinkedList::size()
{
    return numElements; 
}

/*
 * Purpose:  Register one more occurrence of the given word
 *           If word is already in list, it's frequency is incremented by one
 *           If word is not in list, it is added with a frequency of 1
 *           Words are always added in alphabetical order, that is
 *           adding a new word means it goes in front of the first
 *           word that compares > than the new word, or at the end of
 *           the list if this word comes after all the words in the
 *           list alphabetically.
 * Params:   The string word to be added to the list
 * Effects:  Modifies a frequency in the list or adds a new element
 */
void WordFreqLinkedList::countOccurrence(string word)
{
    Node *curr_p = front; 
    bool exists = false;
    int i; 
    
    if (curr_p == nullptr)    //if the list is empty, create new Node  
    {
        front = add(word, nullptr);
        numElements++; 
    } 
       
    else 
    {
        while (curr_p != nullptr)
        { 
            if (curr_p->data.word == word)    //if word already in list 
            {
                curr_p->data.freq++;    //increment freq by 1 
                exists = true; 
                break; 
            }
            curr_p = curr_p->next;    //else, move to next node and check 
        }
        
        if (!exists)    //if the word isn't in list yet 
        {
            i = whereToAdd(word);
            addAt(word, i); 
            numElements++;
        }
    }
}

//get_helper
//purpose: helper function to get(); if the index provided for get() is valid, 
//then this function will find the appropriate WordFreq struct and return it 
//Parameter: the index provided by the user 
//Returns: the WordFreq struct at the given index 
WordFreq WordFreqLinkedList::get_helper(int index)
{
    Node *curr_p = front; 
    int counter = 0; 
    WordFreq w;
    
    while (curr_p != nullptr)
    {
        if (counter == index)
        {
            w = curr_p->data; 
            break;    //if the struct is found, can exit loop 
        }
        else 
        {
            curr_p = curr_p->next; 
            counter++;            
        }
    }
    
    return w;    //return to get()
}

/*
 * Purpose:  Return the index-th element of the list
 * Params:   index must be in range [0 .. size) where
 *           size is the number of words stored in the list
 * Effects:  if index is out of range, prints error message and exits program
 *           otherwise, none
 */
WordFreq WordFreqLinkedList::get(int index)
{       
    WordFreq w;

    if ((index < 0) or (index >= numElements))
    {
        cerr << "index " << index << " out of range [0, " 
        << numElements << ")" << endl;   
        exit(1);    //function will end after error message is printed   
    }   
     
    else 
        w = get_helper(index); 
    
    return w; 
}


//removeFromFront
//purpose: removes the first node in a linked list 
//parameters: none 
//Returns: none
void WordFreqLinkedList::removeFromFront()
{
    Node *before_p = front; 
    
    if (before_p->next != nullptr)    //front ptr points to next node, if exists
        front = before_p->next; 

    else    //else the list is empty now  
        front = nullptr;

    delete before_p; 
    numElements--; 
}


//remove_helper
//Purpose: helper function for remove()
//Parameters: the word in the node to be removed 
//Returns: nothing
//Effects: removes node from list and recycles memory from the heap 
void WordFreqLinkedList::remove_helper(string word)
{
    Node *before_p = front, *curr_p = before_p->next;  
    
    while (curr_p != nullptr)
    {
        //word is not in this node, move to next node 
        if ((curr_p->data.word != word) and (curr_p->next != nullptr)) 
        {
            before_p = before_p->next; 
            curr_p = curr_p->next; 
        }
        
        //word is not in this node and it is the last node (word not in list)
        else if ((curr_p->data.word != word) and (curr_p->next == nullptr))
            return; 
            
        else if (curr_p->data.word == word)    //word found 
        {
            if (curr_p->next == nullptr)    //if item removed was last item 
                before_p->next = nullptr; 

            else
                before_p->next = curr_p->next;    
            
            delete curr_p;
            numElements--; 
            return;    
        }
    }
}

/*
 * Purpose:  Remove word from the list.  That is, it removes and 
 *           recycles the node containing the word (and its count)
 */
void WordFreqLinkedList::remove(string word)
{
    Node *before_p = front; 
    
    if (before_p == nullptr)
        return;    //can't delete word if list is empty 
        
    else if (before_p->data.word == word)    //first item is to be deleted 
        removeFromFront(); 

    else 
        remove_helper(word);
}


/*
 * Purpose:  print out the underlying list on cout
 * Effects:  prints to cout
 * Notes:    this function is here for debugging purposes.
 *           It will not be called in the final version of the wordfreq
 *           program.
 *           Still LEAVE IT AS-IS:  WE WILL USE IT FOR TESTING.
 */
void WordFreqLinkedList::debugPrint()
{
    Node *curr = front;

    cout << "[";
    while (curr != nullptr) {
            cout << "{" << curr->data.word << ", "
                 << curr->data.freq << "}";
            if (curr->next != nullptr)
                    cout << ", ";
            curr = curr->next;
    }
    cout << "]";
}

//add 
//Purpose: creates a new node 
//Parameter: string to be stored and pointer to next node, or nullptr 
//Returns: the pointer to the new Node struct 
//Effects: a new node will be allocated on the heap 
WordFreqLinkedList::Node* WordFreqLinkedList::add(string s, Node *next_p)
{
    Node *new_node_p = new Node;
    new_node_p->next = next_p;
    new_node_p->data.word = s;
    new_node_p->data.freq = 1; 
    
    return new_node_p;
}

//addToFront
//Purpose: adds a new node at the front of the list 
//Parameter: a string for the new node 
//Returns: nothing
//Effect: new node will be created and added to linked list 
void WordFreqLinkedList::addToFront(string s)
{
    Node *new_node_p = add(s, front);
    front = new_node_p;
}


//whereToAdd
//Purpose: compare a string element to others in the list to determine
 //where to put the string (in alphabetical order)
//Parameter: string (from node to be inserted)
//Returns: int that represents the index 
int WordFreqLinkedList::whereToAdd(string s)
{
    Node* curr_p = front;
    string s2;  
    int counter = 0; 
    
    while (curr_p != nullptr)
    {
        s2 = curr_p->data.word;    //checks curr word to word to be inserted   
        
        while (s > s2)    //if our word goes after curr word in list
        {
            counter++; 
            if (curr_p->next != nullptr)
            {
                curr_p = curr_p->next;    //moves to next node  
                s2 = curr_p->data.word; 
            }
            
            else 
                break;    //the case where word will be inserted at the end   
        }  
          
        break;
    }
    
    return counter; 
}


//addAt
//Purpose: adds a new node at the desired index 
//Parameter: string to be stored and index to add new node 
//Returns: nothing
//Effect: new node will be added at indicated index 
void WordFreqLinkedList::addAt(string s, int i)
{
    if (i == 0) 
    {
        addToFront(s);
        return;
     }
    
    int counter = 0; 
    i--; 
    Node *before_p;
    
    for (before_p = front; (before_p != nullptr) and (counter < i); 
         before_p = before_p->next)
    {
        counter++;    //moving pointer to the node before where to insert  
    }    
    
    if (before_p == nullptr)
        cout << "index error" << endl;
    
    else 
    {
        Node *new_node_p = add(s, before_p->next); 
        before_p->next = new_node_p; 
    }
}