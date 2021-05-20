/* Author: Brandon Bwanakocha
*  Header file
*/

#define BUFFER_SIZE 100                             // buffer size for strings

typedef struct Node{

    char name[BUFFER_SIZE];                          // Name of node/audio processing block
    char in_type[BUFFER_SIZE];                      // property of input signal
    char out_type[BUFFER_SIZE];                     // property of output signal
    char operation[BUFFER_SIZE];                    // string that specifies what operations to do                    

    Node* in_port;                                  // input port for this node
    Node* out_port;                                 // output port for this node

}Node;







/*
typedef struct client_ops_t client_ops_t;
typedef struct client_t client_t, *pno;

struct client_t {
   
    client_ops_t *ops;
};

struct client_ops_t {
    pno (*AddClient)(client_t *);
    pno (*RemoveClient)(client_t *);
};

pno AddClient (client_t *client) { return client->ops->AddClient(client); }
pno RemoveClient (client_t *client) { return client->ops->RemoveClient(client); }*/