all: forkin.c
	gcc forkin.c
run: all 
	./a.out
