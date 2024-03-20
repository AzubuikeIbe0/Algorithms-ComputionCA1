#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinaryTree T1;

   /* T1.InsertNode(1);
    T1.InsertNode(2);
    T1.InsertNode(3);
    T1.InsertNode(4);
    T1.InsertNode(5);
    T1.InsertNode(6);
    T1.InsertNode(7);

    T1.InOrder();

    T1.DeleteNode(7);
    T1.InOrder();

    T1.DeleteNode(3);
    T1.InOrder();*/

    BinarySearchTree T2;

    T2.InsertNode(1);
    T2.InsertNode(2);
    T2.InsertNode(3);
    T2.InsertNode(4);
    T2.InsertNode(5);
    T2.InsertNode(6);
    T2.InsertNode(7);

    T2.InOrder();
    T2.DeleteNode(2);
    cout << endl;

    T2.InOrder();
    cout << endl;

    T2.GetHeight();
    cout << endl;
    
    T2.InOrder();
    cout << endl;

    T2.~BinarySearchTree();
    T2.InOrder();

    return 0;
}

