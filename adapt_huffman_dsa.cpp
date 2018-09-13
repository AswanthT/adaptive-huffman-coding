#include<iostream>
#include<vector>
using namespace std;

class Node  {
public:
    int data;
    int count;
    Node* left;
    Node* right;
    Node* parent;
    Node(int d) {
        data = d;
        if(d)
            count = 1;
        else
            count = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    void print()    {
        cout<<"data: "<<data;
        cout<<" count: "<<count<<endl;
    }
};
class Tree  {
    public:
    Node* nyt;
    Node* root;
    Node* position[26];
    Tree()  {
        nyt = new Node(0);
        root = nyt;
        for(int i=0; i<26; i++)
            position[i] = NULL;
    }
    void append(int c) {
        if(position[c-97]==NULL)    {
            Node* t = new Node(c);
            position[c-97] = t;
            Node* nnyt = new Node(0);
            nyt->right = t;
            t->parent = nyt;
            nyt->left = nnyt;
            nnyt->parent = nyt;
            nyt->count = nyt->count+1;
            Node* temp = nyt->parent;
            while(temp!=NULL)   {
                temp->count = temp->count+1;
                if((temp->left->count) > (temp->right->count))  {
                    Node* temp1 = temp->left;
                    temp->left = temp->right;
                    temp->right = temp1;
                }
                temp = temp->parent;
            }
            nyt = nnyt;
        }
        else    {
            Node* t = position[c-97];
            Node* temp = root;
            while((temp->left)!=t && (temp->right)!=t)  {
                if((temp->left->data!=0) && (temp->left->count == t->count)) {
                    Node* temp1 = temp->left;
                    temp->left = t;
                    if(t->parent->left==t)
                        t->parent->left = temp1;
                    else
                        t->parent->right = temp1;
                    temp1->parent = t->parent;
                    t->parent = temp;
                    break;
                }
                else if((temp->right->data!=0) && (temp->right->count == t->count)) {
                    Node* temp1 = temp->right;
                    temp->right = t;
                    if(t->parent->left==t)
                        t->parent->left = temp1;
                    else
                        t->parent->right = temp1;
                    temp1->parent = t->parent;
                    t->parent = temp;
                    break;
                }
                else if(temp->left->data==0)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            t->count = t->count+1;
            temp = t->parent;
            while(temp!=NULL)   {
                temp->count = temp->count+1;
                if((temp->left->count) > (temp->right->count))  {
                    Node* temp1 = temp->left;
                    temp->left = temp->right;
                    temp->right = temp1;
                }
                temp = temp->parent;
            }
        }
    }
    vector<bool> searchnyt()    {
        Node* temp = root;
        vector<bool> code;
        while(temp!=nyt)    {
            if(temp->left->data==0) {
                code.push_back(false);
                temp = temp->left;
            }
            else    {
                code.push_back(true);
                temp = temp->right;
            }
        }
        return code;
    }
    vector<bool> search(int d) {
        Node* temp = root;
        vector<bool> code;
        while(1) {
            if(temp->left==NULL && temp->right==NULL)
                break;
            if(temp->left->data==d)   {
                code.push_back(false);
                code.push_back(true); //parity
                return code;
            }
            if(temp->right->data==d)  {
                code.push_back(true);
                code.push_back(true);//parity
                return code;
            }
            if(temp->left->data==0) {
                code.push_back(false);
                temp=temp->left;
            }
            else if(temp->right->data==0)   {
                code.push_back(true);
                temp = temp->right;
            }
        }
        code.push_back(false);
        return code;
    }
    int traverse(vector<bool> code,int &i)   {
        Node* temp = root;
        while(temp->right!=NULL || temp->left!=NULL)    {
            if(code[i]==0)
                temp = temp->left;
            else
                temp = temp->right;
            i++;
        }
        return temp->data;
    }
};