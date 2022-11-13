#include "encoding.h"
#include "decoding.h"
#include <iostream>

int main(){
	std::string text;
	std::cout << "Enter text: ";
	std::cin >> text;
    std::string encodedText = encoder(text);
	std::cout << "Encoded text: " << encodedText << std::endl;
    std::string decodedText = decoder(encodedText);
	std::cout << "Decoded text: " << decodedText << std::endl;
	return 0;
}
