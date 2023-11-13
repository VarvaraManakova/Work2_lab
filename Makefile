Project: main.o scaner.o store.o route.o
	g++ main.o scaner.o store.o route.o -o Project

main.o: main.cpp
	g++ -c main.cpp -o main.o

scaner.o: TextScan.cpp
	g++ -c TextScan.cpp -o scaner.o

store.o: Storage.cpp
	g++ -c Storage.cpp -o store.o

route.o: Route.cpp
	g++ -c Route.cpp -o route.o

clear: Project
