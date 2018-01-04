CXX = g++
CXXFLAGS = -std=c++11 -pthread -W -Wall 
TARGET = Main.exe
OBJECTS = SudokuSolver.o BoardMaker.o Main.o

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -f *.o Main.exe
