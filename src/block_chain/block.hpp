#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iostream>

class Block {
public:
    Block( int before_index, const char* before_hash ) {
        hash = before_hash;
        index = before_index;
    }
    
    int data;
    int64_t proof;
private:
    const char* hash;
    unsigned int index;
};

#endif
