#include "api.h"
#include <stdlib.h>
#include <stdio.h>

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

void link(Node* newNode){

    if(tail->out_type == newNode->in_type){                         // if ports are compatible
        tail->out_port = newNode;                                   // the tail's output port gets connected to the input port of new Node
        newNode->in_port = tail;
        tail = newNode;
        printf("Node successfuly Linked \n");
        }
    else{
        printf("ERROR: Nodes not compatible\n");
    }
}

void perform(Node* node){
    printf("Node %s is performing the following task: %s \n",node->name, node->operation);
    printf("Node: %s DONE!\n\n", node->name);
}