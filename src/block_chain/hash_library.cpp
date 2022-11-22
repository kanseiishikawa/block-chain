#include <cstring>
#include <ios>
#include <iostream>
#include <sstream>
#include <functional>
#include <string>
#include <vector>
#include <iomanip>

#include <openssl/sha.h>

#include "hash_library.hpp"

std::vector< std::string > sha256( std::string word ) {
    std::vector< std::string > hash;
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha_ctx;
    SHA256_Init( &sha_ctx );
    SHA256_Update( &sha_ctx, word.c_str(), word.size() );
    SHA256_Final( digest, &sha_ctx );
    
    for( int i = 0; i < SHA256_DIGEST_LENGTH; i++ ) {
        std::ostringstream ss;
        ss << std::hex << static_cast<int>( digest[i] );
        hash.push_back( ss.str() );
    }

    return hash;
}

std::string change_to_string(std::vector<std::string> data) {
    std::string str_data;

    for( std::string d: data ) {
        str_data += d;
    }

    return str_data;
}

std::vector< unsigned int > change_hash_num( std::vector< std::string > hash ) {
    std::vector< unsigned int > num_list;
    
    for( std::string word: hash ) {
        unsigned int num;
        std::istringstream iss( word );
        iss >> std::hex >> num;
        num_list.push_back( num );
    }
    
    return num_list;
}

std::string next_hash( std::vector<unsigned int> &hash_num ) {
    std::ostringstream hash_string;
    
    for( unsigned int num: hash_num ) {
        hash_string << std::hex << num;
    }

    return change_to_string( sha256( hash_string.str() ) );
}

void add_num( std::vector<unsigned int> &base_num, unsigned int num ) {
    const unsigned int check_num = 16 * 16 - 1;

    for( int i = static_cast< int >( base_num.size() ) - 1; i >= 0; i-- ) {
        base_num[i] += num;
        
        if( check_num < base_num[i] ) {
            num = 1;
            base_num[i] -= check_num;
        } else {
            break;
        }
    }
}

unsigned int zero_count( std::string hash ) {
    unsigned int count = 0;

    for( int i = 0; i < hash.size(); i++ ) {
        if( hash[i] == '0' ) {
            count += 1;
        } else {
            break;
        }
    }

    return count;
}
