#include <ctime>
#include <functional>
#include <string>
#include <thread>
#include <iostream>
#include <unistd.h>

#include "block_chain/hash_library.hpp"
#include "connect/udp.cpp"


void udp_send( UdpConnect *udp ){
    for( int i = 0; i < 10; i++ ) {
        sleep( 10 );
        std::cout<< "send hello\n";
        udp->udp_send("hello!");
    }
}

void udp_recive( UdpConnect *udp ){
    udp->udp_bind();
    std::cout<< "server start" << "\n";
    while (1){
        std::string rdata=udp->udp_recv();
        printf("recv:%s\n", rdata.c_str());
    }
}

/*
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
    }*/

int main() {
    std::string ip_address = "127.0.0.1";
    UdpConnect udp( ip_address, 4001 );
    std::thread recive_thread( udp_recive, &udp );
    std::thread send_thread( udp_send, &udp );

    recive_thread.join();
    send_thread.join();
}
