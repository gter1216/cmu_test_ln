# type tab before command
# xuxiao, 2018.10.31

battleship : battleship.o main.o
	gcc -o battleship main.o battleship.o -I /home/xiaoxu1/usr/local/include -L /home/xiaoxu1/usr/local/include/lib/ 

main.o : main.c
	gcc -c main.c

battleship.o : battleship.c
	gcc -c battleship.c

clean :
	rm battleship battleship.o main.o 
