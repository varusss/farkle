a.out: main.o die.o player.o scoreboard.o table.o
	g++ -std=c++11 -Wall -Wextra -fsanitize=address main.o die.o player.o scoreboard.o table.o

main.o: main.cc die.h player.h
	g++ -c main.cc

die.o: die.cc die.h
	g++ -c die.cc

player.o : player.cc player.h
	g++ -c player.cc

scoreboard.o : scoreboard.cc scoreboard.h
	g++ -c scoreboard.cc

table.o : table.cc table.h
	g++ -c table.cc

clean:
	rm -f *.o a.out core
