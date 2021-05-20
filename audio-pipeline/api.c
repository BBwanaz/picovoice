#include "api.h"
#include <stdlib.h>
#include <stdio.h>

/*  author: Brandon Bwanakocha
*   description: Creates a new Nodeand returns it
*   param: name: Name of node eg "Amplifier"
*   param: in_type: type of input the node expects
*   param: out_type: type of output the node gives out
*   param: operation: what the Node does as an operation
*   return: pointer to a new node

*/
Node* createNode(char* name, char* in_type, char* out_type, char* operation){

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->name = name;
    newNode->operation = operation;
    newNode->in_type = in_type;
    newNode->out_type = out_type;
    newNode->in_port = NULL;
    newNode->out_port = NULL;
    printf("Node Creation Successful\n");

    return newNode;
}

/*  author: Brandon Bwanakocha
*   description: appends a node to the end of a linked list (pipeline) containing Nodes in order of exercution
*   param: newNode: New node to be added to pipeline
*/

void link(Node* newNode){

    if(tail->out_type == newNode->in_type){                         // if ports are compatible
        tail->out_port = newNode;                                   // the tail's output port gets connected to the input port of new Node
        newNode->in_port = tail;                                    // new node becomes tail
        tail = newNode;
        printf("Node successfuly Linked \n");
        }
    else{
        printf("ERROR: Nodes not compatible\n");
    }
}

/*  author: Brandon Bwanakocha
*   description: represents a function that gets exercuted to perform whatever role a Node has
*   param: node: Node whose specific operation is performed
*/
void perform(Node* node){
    printf("Node %s is performing the following task: %s \n",node->name, node->operation);
    printf("Node: %s DONE!\n\n", node->name);
}