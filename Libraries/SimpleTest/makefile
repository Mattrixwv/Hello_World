all: lib/libA.a lib/libSO.so libTest
#$@ is the first argument lib/libA.s
#$< is the second argument lib/libA.cpp
lib/libA.a: lib/libA.cpp
	$(CXX) -shared -fPIC -o $@ $<
lib/libSO.so: lib/libSO.cpp
	$(CXX) -shared -fPIC -o $@ $<

libTest: main.cpp
	$(CXX) main.cpp -o libTest -L ./lib -Wl,-rpath,'$$ORIGIN/lib' -lA -lSO

.PHONY: clean

clean:
	rm lib/libA.a lib/libSO.so libTest
