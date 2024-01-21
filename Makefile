all: compile link

compile:
	g++ -Isrc/include -c ball.cpp

link:
	g++ ball.o -o ball -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system