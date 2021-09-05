//Author: Dinesh Reddy Kommera
//Date: 4th September, 2021
//Purpose: C++ program for Sparse Matrix Representation of Linked List 


#include<iostream>
using namespace std;
 
// Node class for linked list
class Node
{
    public:
    int row;
    int col;
    int data;
    Node *next; //address of the next node
};
 
// Function to create new node
void create_new_node(Node **p, int row_index,
                     int col_index, int x)
{
    Node *temp = *p;
    Node *r;
     
    // If link list is empty then create first node and assign value.
    if (temp == NULL)
    {
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }
     
    // If link list is already created then append newly created node
    else
    {
        while (temp->next != NULL)  
            temp = temp->next;
             
        r = new Node();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}
 
// Function prints contents of linked list starting from start
void printList(Node *start)
{
    Node *ptr = start;
    cout << "row_pos:";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "col_pos:";
 
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:  ";
    ptr = start;
     
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
 
// MAIN FUNCTION
int main()
{
     
    int row,col;
    int sparMatrix[10][10];
    // Number of rows and columns
    cout<<"Enter no of rows of the matrix: ";
    cin>>row;
    cout<<"Enter no of columns of the matrix: ";
    cin>>col;

    for(int i=0; i<row;i++){
        for(int j=0;j<col;j++){
            cin>>sparMatrix[i][j];
        }
        cout<<"\n";
    }

     
    // Creating head node of list as NULL
    Node *first = NULL;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            // Pass only those values which are non-zero
            if (sparMatrix[i][j] != 0)
                create_new_node(&first, i, j,
                                sparMatrix[i][j]);
        }
    }
    printList(first);
 
    return 0;
}