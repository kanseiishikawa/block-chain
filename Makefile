CC = g++ -std=c++11 -Qunused-arguments -Wunused-command-line-argument
INCLUDE = -I/usr/local/opt/openssl@1.1/include -I./src/block_chain
LIRABRY_PATH = -L/usr/local/opt/openssl@1.1/lib/
LIBS = -lcrypto
BROCK_CHAIN_DIR = src/block_chain

defalt: main.o block_chain
	$(CC) -Wall -o main main.o $(BROCK_CHAIN_DIR)/*.o $(INCLUDE) $(LIBS) $(LIRABRY_PATH)

block_chain:
	make -C $(BROCK_CHAIN_DIR)

main.o: main.cpp
	$(CC) -c main.cpp $(INCLUDE) $(LIBS) $(LIRABRY_PATH)

clean:
	rm *.o $(BROCK_CHAIN_DIR)/*.o
