#include <iostream>

#include "hash_library.hpp"
#include "block.hpp"

int main() {
    std::vector< Block > block_chain;
    std::string first_code = "first-block-chain";
    std::vector< std::string > first_hash = sha256( first_code );
    std::vector< unsigned int > hash_num = change_hash_num( first_hash );
    int count = 0;
    
    while( 1 ) {
        add_num( hash_num, 1 );
        std::string str_next_hash = next_hash( hash_num );
        unsigned int zero = zero_count( str_next_hash );
        count += 1;

        if( count % 100000 == 0 ) {
            std::cout<< count << "\n";
        }
        
        if( zero == 3 ) {
            std::cout<< count << " " << str_next_hash <<"\n";
            break;
        }
    }
}
