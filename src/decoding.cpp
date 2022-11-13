#include "decoding.h"
#include <iostream>

std::string decoder(std::string text)
{
	std::string decodedText;
	for (int i = 0; i < text.size(); ++i)
	{
		int charIndex = (int)text[i];
		if ((charIndex < 65 || charIndex > 122) || (charIndex > 90 && charIndex < 97))
		{
			decodedText += text[i];
			continue;
		}
		if (charIndex < 68)
		{
			charIndex += 26;
		}
		else if (charIndex > 96 && charIndex < 100)
		{
			charIndex += 26;
		}
		decodedText += (char)(charIndex - 3);
	}
	return decodedText;
}
