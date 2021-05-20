/* Author: Brandon Bwanakocha
*  Header file
*/

#include <stdio.h>

#define BUFFER_SIZE 100                             // buffer size for strings

// Audio processing node
typedef struct Node{

    char *name;                                     // Name of node/audio processing block
    char *in_type;                                  // property of input signal
    char *out_type;                                 // property of output signal
    char *operation;                                // string that specifies what operations to do                    

    struct Node *in_port;                                  // input port for this node
    struct Node *out_port;                                 // output port for this node

}Node;

Node *tail;

//operations declarations
Node* createNode(char*, char*, char*, char*);        // method to create a node
void link( Node* );                                  // function to link two nodes by appending one
void perform(Node*);                                   // function for how the Node performs it's operation