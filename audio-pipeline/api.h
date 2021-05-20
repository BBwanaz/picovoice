/* Author: Brandon Bwanakocha
*  Header file
*/

#define BUFFER_SIZE 100                             // buffer size for strings

// Audio processing node
typedef struct Node{

    char *name;                                     // Name of node/audio processing block
    char *in_type;                                  // property of input signal
    char *out_type;                                 // property of output signal
    char *operation;                                // string that specifies what operations to do                    

    Node *in_port;                                  // input port for this node
    Node *out_port;                                 // output port for this node

}Node;

Node* head, *tail;

//operations declarations
Node* createNode(char*, char*, char*, char*);        // method to create a node
void link( Node* );                                  // function to link two nodes by appending one
void init(Node*);                                    // function to initialize the linked list
void perform(Node*);                                   // function for how the Node performs it's operation