#    A simple Tic Tac Toe implementation in the C language + a command line interface.
#    Copyright (C) 2023 Johannes Randerath
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.


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

