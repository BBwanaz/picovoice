# Picovoice

This repository contains solutions to the coding prompts for the Software Developer Position. I chose the problems 1, 2 and 4 and I used Python, HTML & JavaScript, and C respectively. Below is a brief solution explanation for each problem.

##  Caching problem

I used a python dictionary as a cache where the keys are the ISBN numbers and the values are the object/struct containing the title, language and author of a book. An example of two entries in this cache would look like the following:

``` 
{
    "00000000" : {
        "author" : "Brandon Bwanakocha",
        "title" : "Job Applications",
        "language" "Shona"
    },
    "12345678" : {
        "author" : "Bill Gates",
        "title" : "How to run microsoft",
        "language" : "English"
    }
}
```

This dictionary is in the order: Least Recently used -> Most Recently Used. I made a wrapper function that caches N data entries into dictionary. The code takes care of the following scenarios:

### Scenario 1: Cache miss and number of entries in cache < N

Append the entry onto the cache.

### Scenario 2: Cache miss and number of entries in cache >= N

Pop the top of the cache (Least Recently Used entry) and append the entry onto the cache.

### Scenario 3: Cache hit

Pop off entry from current position and append the entry to the back of the cache.

## Rest Countries

I used two endpoints to extract the data that I needed using JavaScript. The endpoints include:

```
Name: "https://restcountries.eu/rest/v2/name/"
List of Codes: "https://restcountries.eu/rest/v2/alpha?codes="
```

The code works by using the "Name" Endpoint to extract the neighbours of the country and its ISO code.The code then inserts the country's ISO code onto the list containing the ISO codes of the neighbours, uses the "List of Codes" to make precisely One API call to extract the capitals as needed.

## Audio Pipeline

I used C structures to represent nodes. The structures have the following declaration:

``` C
typedef struct Node{

    char *name;                                             // Name of node/audio processing block
    char *in_type;                                          // property of input signal
    char *out_type;                                         // property of output signal
    char *operation;                                        // string that specifies what operations to do                    

    struct Node *in_port;                                  // input port for this node
    struct Node *out_port;                                 // output port for this node

}Node;
```

The pipeline is simply a doubly linked list with the head pointer being the source and with a declared tail pointer. To use the pipeline, a user must first create nodes using the ```createNode``` function, link the nodes to the pipeline sequentialy using the function ```link``` and then write a loop that traverses through the pipeline nodes, calling the ```perform``` function on each node. Below are the file descriptions:

```api.h``` Header file where I declared the structure and the function prototypes\
```api.c``` C file where I wrote all the functions for the pipeline\
```main.c``` This is where I showed how to use the pipeline and how to create new nodes\
```test```  This is the .exe file that was created



