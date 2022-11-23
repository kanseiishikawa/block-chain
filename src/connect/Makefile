CC = g++ -std=c++11 -Qunused-arguments -Wunused-command-line-argument
INCLUDE = -I/usr/local/opt/openssl@1.1/include
LIRABRY_PATH = -L/usr/local/opt/openssl@1.1/lib/
LIBS = -lcrypto

udp.o: udp.cpp
	$(CC) -c udp.cpp $(INCLUDE) $(LIBS) $(LIRABRY_PATH)
