CC = g++ -std=c++11
INCLUDE = -I/usr/local/opt/openssl@1.1/include
LIRABRY_PATH = -L/usr/local/opt/openssl@1.1/lib/
LIBS = -lcrypto
BROCK_CHAIN_DIR = block_chain
CONNECT_DIR = connect

ifeq ($(shell uname),Linux)
	LIRABRY_PATH = -L/usr/local/lib64/
	INCLUDE = -I/usr/local/include/
endif

defalt: main.o
	$(CC) -Wall -o main main.o $(CONNECT_DIR)/*.o $(BROCK_CHAIN_DIR)/*.o $(INCLUDE) $(LIBS) $(LIRABRY_PATH)

main.o: link_dir
	$(CC) -c main.cpp $(INCLUDE) $(LIBS) $(LIRABRY_PATH)

link_dir:
	make -C $(CONNECT_DIR)
	make -C $(BROCK_CHAIN_DIR)

clean:
	rm *.o $(BROCK_CHAIN_DIR)/*.o $(CONNECT_DIR)/*.o
