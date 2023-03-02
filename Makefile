CARGS = -std=c11 -Wall -g

play: helpers game
	gcc $(CARGS) -c src/play.c -o play.o
	gcc $(CARGS) helpers.o game.o play.o -o play

game: src/game.c src/game.h src/helpers.h
	gcc $(CARGS) -c src/game.c -o game.o

helpers: src/helpers.c
	gcc $(CARGS) -c src/helpers.c -o helpers.o

test_game: game src/test_game.c src/test_game.h
	gcc $(CARGS) -c src/test_game.c -o test_game.o

tests: helpers game test_game src/tests.c src/tests.h
	gcc $(CARGS) -c src/tests.c -o tests_o.o
	gcc helpers.o game.o test_game.o tests_o.o -o tests.o
	chmod +x tests.o

