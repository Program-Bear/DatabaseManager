// ================================================================================================
//
//  BPlusTree.h
//  BPlustree
//
// ================================================================================================



#ifndef BPlusTree_hpp
#define BPlusTree_hpp

#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

#define ORDER 5
#define MAX_POINTER ORDER
#define MAX_KEY (ORDER - 1)
#define MID_V MAX_KEY / 2
#define LEFT 1
#define RIGHT 2



// ================================================================================================
//
// enum NODE_TYPE
// The 3 types of nodes: ROOT, INNER, LEAF
//
// ================================================================================================

enum NODE_TYPE 
{
    ROOT_NODE = 1,
    INNER_NODE = 2,
    LEAF_NODE = 3,
};



// ================================================================================================
//
// class TreeNode 
// The superclass of InnerNode class and LeafNode class
//
// ================================================================================================

class TreeNode 
{
    public:
        TreeNode();
        ~TreeNode();

        // Get and set Node type
        NODE_TYPE getType() { return type; }
        void setType(NODE_TYPE node_type) { type = node_type; }
        
        // Get and set valid Node number
        int getCount() { return count; }
        void setCount(int num) { count = num; }
        
        // Abstract method for getting and setting key
        virtual int getKey(int i) { return 0; }
        virtual void setKey(int i, int key_value) {}
        
        // Abstract method for getting and setting pointer
        virtual TreeNode* getPointer(int i) { return 0; }
        virtual void setPointer(int i, TreeNode* pointer) {}
        
        // Getting and setting parent
        TreeNode* getParent() { return parent; }
        void setParent(TreeNode* parent_node) { parent = parent_node; }

        // Find a closest TreeNode to this TreeNode
        TreeNode* getBrother(int& flag);

        // Print TreeNode
        void printNode();

        // Delete node
        void deleteNode();

    protected:
        NODE_TYPE type;   // What type of node
        int count;        // Number of valid key, for inner node is number of key
        TreeNode* parent; // Pointer to parent node
};



// ================================================================================================
//
// class InnerNode 
// Inherit TreeNode class
//
// ================================================================================================

class InnerNode : public TreeNode 
{
    public:
        InnerNode();
        ~InnerNode();

        int getKey(int i) 
        {
            if ((i < 0) || (i >= MAX_KEY)) 
            {
                return 0;
            } else {
                return keys[i];
            }
        }

        void setKey(int i, int key_value) 
        {
            if ((i >= 0) && (i < MAX_KEY)) 
            {
                keys[i] = key_value;
            }
        }

        TreeNode* getPointer(int i) 
        {
            if ((i < 0) || (i >= MAX_POINTER)) 
            {
                return 0;
            } 
            else 
            {
                return pointers[i];
            }
        }

        void setPointer(int i, TreeNode* pointer) 
        {
            if ((i >= 0) && (i < MAX_POINTER)) 
            {
                pointers[i] = pointer;
            }
        }

        bool insert(int value, TreeNode* pNode);
        bool remove(int value);

        int split(InnerNode* pNode, int key);
        bool merge(TreeNode* pNode);

        // Move one key from pNode to this InnerNode
        bool moveOneKey(TreeNode* pNode);

    protected:
        int keys[MAX_KEY];               // An array of keys, number of keys is MAX_KEY
        TreeNode* pointers[MAX_POINTER]; // An array of pointers, number of pointers is MAX_POINTER
};



// ================================================================================================
//
// class LeafNode 
// Inherit TreeNode class
//
// ================================================================================================

class LeafNode : public TreeNode 
{
    public:
        LeafNode();
        ~LeafNode();

        int getKey(int i) 
        {
            if ((i < 0) || (i >= MAX_KEY)) 
            {
                return 0;
            } 
            else 
            {
                return data[i];
            }
        }

        void setKey(int i, int key_value) 
        {
            if ((i >= 0) && (i < MAX_KEY)) 
            {
                data[i] = key_value;
            }
        }

        TreeNode* getPointer(int i) 
        {
            return 0;
        }
        
        bool insert(int value);
        bool remove(int value);

        int split(LeafNode* newLeaf);
        bool merge(TreeNode* pNode);

        // Double linked list
        LeafNode* prev;
        LeafNode* next;

    protected:
        // Here we just assume the data is key
        int data[MAX_KEY]; // An array of data, number of data is MAX_KEY
};



// ================================================================================================
//
// class BPlusTree 
// BPlusTree
//
// ================================================================================================

class BPlusTree 
{
    public:
        BPlusTree();
        ~BPlusTree();

        bool search(int key); // Search the key
        bool insert(int key); // Insert the key
        bool remove(int key); // Remove the key

        void printTree();
        void clearTree();

        TreeNode* root; // root of B Plus Tree
        
        // head and tail of leave node
        LeafNode* head;
        LeafNode* tail;
    
    private:
        LeafNode* searchLeaf(int key);
        bool insertInnerNode(InnerNode* pNode, int key, TreeNode* rightSon);
        bool removeInnerNode(InnerNode* pNode, int key);
};

#endif /* BPlusTree_hpp */