#include <iostream>
#include <string>
#include <cstdint>
#include <fstream>
#include <string.h>
#include <openssl/md5.h>
 
int main(int argc, char** argv) {
	if(argc < 2){
		std::cout << "There are not enough arguments" << std::endl;
		std::cin.get();
		return 0;
	}
	std::fstream file;
	file.open(argv[1], std::ios::in | std::ios::binary);

	if(file.fail()){
		std::cout << "That is not a valid file name" << std::endl;
		std::cin.get();
		return 0;
	}
	uint8_t line;
	unsigned char digest[MD5_DIGEST_LENGTH];

	MD5_CTX ctx;
	MD5_Init(&ctx);
	while(true){
		//std::getline(file, line);
		file.read(reinterpret_cast<char*>(&line), sizeof(line));
		if(file.eof()){
			break;
		}
		MD5_Update(&ctx, reinterpret_cast<char*>(&line), sizeof(line));
	}
	MD5_Final(digest, &ctx);

	char mdString[(MD5_DIGEST_LENGTH * 2) + 1];
	for (int i = 0; i < 16; i++)
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

	file.close();
	std::cout << "md5 digest: " << mdString << std::endl;
	std::cin.get();

    return 0;
}