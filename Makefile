FightClub: fightclub.o club.o fighter.o ninja.o warrior.o witch.o yoda.o 
	g++ -std=c++11 fightclub.o club.o fighter.o ninja.o warrior.o witch.o yoda.o -o FightClub

fightclub.o: fightclub.cpp
	g++ -std=c++11 -c fightclub.cpp

club.o: club.cpp
	g++ -std=c++11 -c club.cpp

fighter.o: fighter.cpp
	g++ -std=c++11 -c fighter.cpp

ninja.o: ninja.cpp
	g++ -std=c++11 -c ninja.cpp

warrior.o: warrior.cpp
	g++ -std=c++11 -c warrior.cpp

witch.o: witch.cpp
	g++ -std=c++11 -c witch.cpp

yoda.o: yoda.cpp
	g++ -std=c++11 -c yoda.cpp

start: FightClub
	./FightClub

clean:
	rm *.o FightClub

compress:
	tar czf FightClub.tar.gz *
