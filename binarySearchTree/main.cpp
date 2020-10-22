//
//  main.cpp
//  binarySearchTree
//
//  Created by Antoine Jermaine Smith Jr. on 10/21/20.
//

#include <iostream>
#include "binaryTree.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    TreeType<int> intTree;
    int x;
    cout<<"Enter an integer to be added to the tree."<<endl;
    cin>>x;
    intTree.addItem(x);
    
    string y;
    cout<<"Would you like to add another integer to the tree? \nType yes or no"<<endl;
    cin>>y;
    while (y == "yes") {
        cout<<"Enter your next integer."<<endl;
        cin>>x;
        intTree.addItem(x);
        cout<<"Would you like to add another integer?\nType yes or no"<<endl;
        cin>>y;
    }
    cout<<endl;
    intTree.printTree();
    return 0;
}
