#include "encoding.h"
#include <iostream>

std::string encoder(std::string text)
{
	std::string encodedText;
	for (int i = 0; i < text.size(); ++i)
	{
		int charIndex = (int)text[i];
		if ((charIndex < 65 || charIndex > 122) || (charIndex > 90 && charIndex < 97))
		{
			encodedText += text[i];
			continue;
		}
		if (charIndex > 119)
		{
			int i = charIndex - 122;
			charIndex = 96 + i;
		}
		else if (charIndex > 87 && charIndex < 91)
		{
			int i = charIndex - 90;
			charIndex = 64 + i;
		}
		encodedText += (char)(charIndex + 3);
	}
	return encodedText;
}
