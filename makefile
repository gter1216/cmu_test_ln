# type tab before command
# louna, 2018.10.31

test : test.o
	gcc -o test test.o -I /home/xiaoxu1/usr/local/include -L /home/xiaoxu1/usr/local/include/lib/ 

test.o : test.c
	gcc -c test.c

clean :
	rm test test.o
