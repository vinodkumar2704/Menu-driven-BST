# Menu-driven-BST
QUESTION:


The Binary Search Tree (BST) data structure supports many of the dynamic-set operations.A BST is organized as a binary tree in which each node is an object that contains a key value. In
addition to a key and satellite data, each node contains attributes left, right, and p that point to the nodes corresponding to its left child, its right child, and its parent, respectively. If a child or
the parent is missing, the appropriate attribute contains the value NIL. The root node is the only node in the tree whose parent is NIL. The keys in a binary search tree are always stored in such a
way as to satisfy the binary-search-tree property:

• Let x be a node in a binary search tree. If y is a node in the left subtree of x, then y.key ≤ x.key. If y is a node in the right subtree of x, then y.key ≥ x.key.


Write a program to create a Binary Search Tree T and perform the operations insertion, deletion, search, find level, find minimum, find maximum, predecessor, successor, and traversals(inorder,
preorder and postorder) on T. Input should be read from console and output should be shown in
console.

Your program should include the following functions.

• Main() - creates the Binary Search Tree T with T as the root node (which is NIL initially)
and repeatedly reads a character ‘a’, ‘d’, ‘s’, ‘l’, ‘m’, ‘x’, ‘r’, ‘u’, ‘i’, ‘p’, ‘t’, ‘y’, ‘z’ or ‘e’ from
the console and calls the sub-functions appropriately until character ‘e’ is entered.
• CreateNode(k) creates a new node with key value k and returns a pointer to the new node. All the pointer attributes of the new node are set to NIL.
• Insert(T, x) - inserts the node x into the BST T.
Note: The caller of this function is assumed to create the node x using the CreateNode()
function.
• Delete(T, x) - deletes the node x from the BST T.
Note: The caller of this function is assumed to invoke Search() function to locate the node
x.
• Search(T, k) - searches for a node with key k in T, and returns a pointer to a node with key k if one exists; otherwise, it returns NIL.
• Level(T, k) - searches for a node with key k in T, and returns the level of the node with key k if one exists; otherwise, it returns NIL.
• MinValue(T) returns the minimum value in the BST T.
• MaxValue(T) returns the maximum value in the BST T.
• Predecessor(T, y) - searches for a node with key y in T, and returns a pointer to a node which is predecessor of the node with key y if one exists; otherwise, it returns NIL.
• Successor(T, y) - searches for a node with key y in T, and returns a pointer to a node which is successor of the node with key y if one exists; otherwise, it returns NIL.
• Inorder(T) - performs recursive inorder traversal of the BST T and prints the data in the nodes of T in inorder.
• Preorder(T) performs recursive preorder traversal of the BST T and prints the data in the nodes of T in preorder.
• Postorder(T) performs recursive postorder traversal of the BST T and prints the data in the nodes of T in postorder.



Input format:
• Each line contains a character from ‘a’, ‘d’, ‘s’, ‘l’, ‘m’, ‘x’, ‘r’, ‘u’, ‘i’, ‘p’, ‘t’, ‘y’, ‘z’ or ‘e’ followed by at most one integer. The integers, if given, are in the range [−106
, 106 ].
• Character ‘a’ is followed by an integer separated by space. In this operation, a node with this integer as key is created and inserted into T.
• Character ‘d’ is followed by an integer separated by space. In this operation, the node with this integer as key is deleted from T and the deleted node’s key is printed.
• Character ‘s’ is followed by an integer separated by space. This operation is to find the node with this integer as key in T.
• Character ‘l’ is followed by an integer separated by space. This operation is to find the level of the node with this integer as key in T.
• Character ‘m’ is to find the minimum value of T.
• Character ‘x’ is to find the maximum value of T.
• Character ‘r’ is followed by an integer separated by space. This operation is to find the predecessor of the node with this integer as key in T.
• Character ‘u’ is followed by an integer separated by space. This operation is to find the successor of the node with this integer as key in T.
• Character ‘i’ is to perform inorder traversal of T.
• Character ‘p’ is to perform preorder traversal of T.
• Character ‘t’ is to perform postorder traversal of T.
• Character ‘e’ is to ‘exit’ from the program.


Output Format:
• The output (if any) of each command should be printed on a separate line.
• For option ‘d’, print the deleted node’s key. If a node with the input key is not present in T,
then print -1.
• For option ‘s’, if the key is present in T, then print 1. If key is not present in T, then print -1.
• For option ‘l’, if the key is present in T, then print its level. If key is not present in T, then
print -1.
• For option ‘m’, print the minimum value of T.
• For option ‘x’, print the maximum value of T.
• For option ‘r’, if the key is present in T, then print its predecessor. If key is not present in T,
then print -1.
• For option ‘u’, if the key is present in T, then print its successor. If key is not present in T,
then print -1.
• For option ‘i’, print the data in the nodes of T obtained from inorder traversal.
• For option ‘p’, print the data in the nodes of T obtained from preorder traversal.
• For option ‘t’, print the data in the nodes of T obtained from postorder traversal.

Sample Input :
a 25
a 13
a 50
a 45
a 55
a 18
l 50
l 19
m
x
r 25
u 30
u 25
i
p
t
y 3
z 2
y 7
s 10
s 25
d 55
d 13
d 10
d 25
i
s 25
e

Sample Output :
2
-1
13
55
18
-1
45
13 18 25 45 50 55
25 13 18 50 45 55
18 13 45 55 50 25
45
18
-1
-1
1
55
13
-1
25
18 45 50
-1
