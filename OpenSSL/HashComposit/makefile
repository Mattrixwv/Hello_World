../../Binaries/Linux/HashComposit : main.cpp
	$(CXX) -o "../../Binaries/Linux/HashComposit" -std=c++11 main.cpp SourceFiles/MD4HashClass.cpp SourceFiles/MD5HashClass.cpp SourceFiles/SHA1HashClass.cpp SourceFiles/SHA224HashClass.cpp SourceFiles/SHA256HashClass.cpp SourceFiles/SHA384HashClass.cpp SourceFiles/SHA512HashClass.cpp SourceFiles/WhirlpoolHashClass.cpp -lcrypto

##Having trouble getting this to work the way I want it to
#CXXFLAGS = "-std=c++11"
#OUTFILELOCATION = "../../Binaries/Linux"	#Location of the output file
#OUTFILENAME = "HashComposit"	#The name of the output file
#OBJECTFILELOCATION = "../../.ObjectFiles/OpenSSL/HashComposit"
#LIBRARIES = "-lcrypto"
#OBJECTDEPS = $(foreach file, $(OBJECTFILELOCATION), $(wildcard $(OBJECTFILELOCATION)file.o))

#executable : ../../Binaries/Linux/HashComposit
#all : $(OBJECTFILELOCATION)/MD4HashClass.o $(OBJECTFILELOCATION)/MD5HashClass.o $(OBJECTFILELOCATION)/SHA1HashClass.o $(OBJECTFILELOCATION)/SHA224HashClass.o $(OBJECTFILELOCATION)/SHA256HashClass.o $(OBJECTFILELOCATION)/SHA384HashClass.o $(OBJECTFILELOCATION)/SHA512HashClass.o $(OBJECTFILELOCATION)/WhirlpoolHashClass.o $(OBJECTFILELOCATION)/main.o executable
#all : ../../Binaries/HashComposit

#Compile most of the object codes
##Having trouble getting this working
#$(OBJECTFILELOCATION)/%.o : SourceFiles/%.cpp Headers/%.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
#$(OBJECTFILELOCATION)/MD4HashClass.o : SourceFiles/MD4HashClass.cpp Headers/MD4HashClass.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
#$(OBJECTFILELOCATION)/MD5HashClass.o : SourceFiles/MD5HashClass.cpp Headers/MD5HashClass.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
#$(OBJECTFILELOCATION)/SHA1HashClass.o : SourceFiles/SHA1HashClass.cpp Headers/SHA1HashClass.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
#$(OBJECTFILELOCATION)/SHA224HashClass.o : SourceFiles/SHA224HashClass.cpp Headers/SHA224HashClass.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
#$(OBJECTFILELOCATION)/SHA256HashClass.o : SourceFiles/SHA256HashClass.cpp Headers/SHA256HashClass.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
#$(OBJECTFILELOCATION)/SHA384HashClass.o : SourceFiles/SHA384HashClass.cpp Headers/SHA384HashClass.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
#$(OBJECTFILELOCATION)/SHA512HashClass.o : SourceFiles/SHA512HashClass.cpp Headers/SHA512HashClass.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<
#$(OBJECTFILELOCATION)/WhirlpoolHashClass.o : SourceFiles/WhirlpoolHashClass.cpp Headers/WhirlpoolHashClass.h Headers/HashesHead.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

#Compile the main function
#$(OBJECTFILELOCATION)/main.o : main.cpp Headers/*.h
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

#Compile all of the object code together
#../../Binaries/Linux/HashComposit : $(OBJECTFILELOCATION)/MD4HashClass.o $(OBJECTFILELOCATION)/MD5HashClass.o $(OBJECTFILELOCATION)/SHA1HashClass.o $(OBJECTFILELOCATION)/SHA224HashClass.o $(OBJECTFILELOCATION)/SHA256HashClass.o $(OBJECTFILELOCATION)/SHA384HashClass.o $(OBJECTFILELOCATION)/SHA512HashClass.o $(OBJECTFILELOCATION)/WhirlpoolHashClass.o $(OBJECTFILELOCATION)/main.o
#	$(CXX) $(CXXFLAGS) -o $@ $? $(LIBRARIES)


#.PHONY : clean

#clean :
#	rm $(OBJECTFILELOCATION)/*.o

#.PHONY : cleanall

#cleanall :
#	rm $(OBJECTFILELOCATION)/*.o ../../Binaries/Linux/HashComposit
