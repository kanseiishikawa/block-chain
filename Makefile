SRC = src

defalt:
	make -C $(SRC)

clean:
	make -C $(SRC) clean
