CC = g++ -std=c++11
INCLUDE = -I/usr/local/opt/openssl@1.1/include
LIRABRY_PATH = -L/usr/local/opt/openssl@1.1/lib/
LIBS = -lcrypto

hash_library.o: hash_library.cpp
	$(CC) -c hash_library.cpp $(INCLUDE) $(LIBS) $(LIRABRY_PATH)

block.o: block.cpp
	$(CC) -c block.cpp $(INCLUDE) $(LIBS) $(LIRABRY_PATH)
