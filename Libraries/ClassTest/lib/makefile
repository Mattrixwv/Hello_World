all: libTestClass.a

obj/TestClass.o: SourceFiles/TestClass.cpp
	g++ -c -fPIC -I Headers -o $@ $<
libTestClass.a: obj/TestClass.o
	g++ -shared -o $@ $<

.PHONY: clean

clean:
	rm obj/*.o libTestClass.a
