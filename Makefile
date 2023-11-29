bin/testHashTable: testHashTable.cpp HashTable.h TableEntry.h Dict.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp HashTable.h TableEntry.h Dict.h

bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp TableEntry.h

clean:
	rm -r *.o bin
