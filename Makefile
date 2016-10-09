output: main.o fasta_reader.o sam_reader.o record.o resistome.o annotation_reader.o utility.o
	g++ -std=c++11 main.o fasta_reader.o sam_reader.o record.o resistome.o annotation_reader.o utility.o -o rarefaction
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
fasta_reader.o: fasta_reader.cpp
	g++ -std=c++11 -c fasta_reader.cpp
sam_reader.o: sam_reader.cpp
	g++ -std=c++11 -c sam_reader.cpp
record.o: record.cpp
	g++ -std=c++11 -c record.cpp
resistome.o: resistome.cpp
	g++ -std=c++11 -c resistome.cpp
annotation_reader.o: annotation_reader.cpp
	g++ -std=c++11 -c annotation_reader.cpp
utility.o: utility.cpp
	g++ -std=c++11 -c utility.cpp
clean:
	rm *.o rarefaction
