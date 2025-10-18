// Implement the LRUCache class:

// LRUCache(int capacity) we need to initialize the LRU cache with positive size capacity.
// int get(int key) returns the value of the key if the key exists, otherwise return -1.
// Void put(int key,int value), Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.if the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.
#include<bits/stdc++.h>
using namespace std;  

class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {    //constructor of inner class
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);       //dummy head and tail
  node * tail = new node(-1, -1);

  int cap;                              //total capacity
  unordered_map < int, node * > m;      //maps key → pointer to its corresponding node in the linked list.

  LRUCache(int capacity) {        //Connstructor
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {    // adds a new node right after the head
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) { //Does not delete the actual memory
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);             // remove old reference
      deletenode(resnode);       // remove from list
      addnode(resnode);          // add to front (most recently used)
      m[key_] = head -> next;    // update map to point to new position
      return res;
    }

    return -1;
  }

void put(int key_, int value) {
    //  Step 1: If the key already exists in the cache
    if (m.find(key_) != m.end()) {
        node * existingnode = m[key_];   // Get the old node
        m.erase(key_);                   // Remove it from the map
        deletenode(existingnode);        // Remove it from the linked list
    }

    //  Step 2: If cache is full, remove the least recently used (LRU) node
    if (m.size() == cap) {
        m.erase(tail->prev->key);        // Remove LRU key from map
        deletenode(tail->prev);          // Remove LRU node from list (just before tail)
    }

    //  Step 3: Insert the new key-value pair as most recently used (MRU)
    addnode(new node(key_, value));      // Add new node right after head (MRU position)

    //  Step 4: Update the map to point to this new node
    m[key_] = head->next;                // head->next is always the most recently added node
}

};