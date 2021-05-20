#include "api.h"


int main(void){

    Node* src;
    Node* node;
    
    src = createNode("SRC","N/A","wav", "Input signal to pipeline");   //assuming we get the source from somewhere else;
    tail = src;

    node = createNode("ADC","wav","wav", "Convert signal to Digital");    // Create a new node
    link(node);

    node = createNode("Averager","wav","wav", "Stregnthen signal");    // Create a new node
    link(node);

    node = createNode("High Pass Filter","wav","wav", "Filter out low frequencies");    // Create a new node
    link(node);

    node = createNode("Sampler","wav","wav", "Samle out audio");    // Create a new node
    link(node);
    printf("\n");

   
    // Perform signal processing
    Node* tmp = src;
    while(tmp->out_port != NULL){
        perform(tmp);
        tmp = tmp->out_port;
    }
}