#pragma once
#include <stdint.h>
#include <vector>

#ifndef CHAROPS
#define CHAROPS

namespace nlp
{
	enum language
	{
		english,
		arabic,
		unknown
	};

	class CharOperation
	{
	public :

		/*Check if character is english character
		  O(1)
		*/
		static bool isEnglishChar(wchar_t c);

		/*Check if character is arabic character
		  O(1)
		*/
		static bool isArabicChar(wchar_t c);

		/*Return Language of character*/
		static language getLanguage(wchar_t c);

		static bool isConstant(wchar_t c);
	};
}

#endif
