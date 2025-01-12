#pragma once
#include <string>
#include "StringOperations.h"

#ifndef STEMMERBASE
#define STEMMERBASE

namespace nlp
{
	class Stemmer
	{
	public:
		virtual std::wstring stem(std::wstring string) = 0;
	};
}

#endif // !STEMMERBASE
