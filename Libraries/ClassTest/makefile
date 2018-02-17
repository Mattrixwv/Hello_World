SUBDIR = lib

all: Libs ClassTest

Libs:
	cd lib && $(MAKE)

obj/main.o: SourceFiles/main.cpp
	$(CXX) -c -I Headers -o $@ $<

ClassTest: obj/main.o
	$(CXX) -o $@ $< -L lib -lTestClass -Wl,-rpath,'$$ORIGIN/lib'

.PHONY: clean

clean:
	rm obj/*.o ClassTest
