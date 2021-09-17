run: base parser main.cpp
	g++ -c main.cpp -o bin/main.o
	g++ bin/main.o bin/token.o bin/node.o bin/condition_parser.o bin/date.o bin/event_storage.o bin/database.o -o bin/main.out
	bin/main.out
	
parser: token.cpp node.cpp condition_parser.cpp
	g++ -c token.cpp            -o bin/token.o
	g++ -c node.cpp             -o bin/node.o
	g++ -c condition_parser.cpp -o bin/condition_parser.o
	
base: date.cpp event_storage.cpp database.cpp
	g++ -c date.cpp          -o bin/date.o
	g++ -c event_storage.cpp -o bin/event_storage.o
	g++ -c database.cpp      -o bin/database.o
