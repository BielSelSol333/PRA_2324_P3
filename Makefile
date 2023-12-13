bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp TableEntry.h

bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h
	mkdir -p bin
	g++ -o bin/HashTable testHashTable.cpp HashTable.h Dict.h TableEntry.h

clean:
	rm -r bin
