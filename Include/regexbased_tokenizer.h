#pragma once
#include "tokenizer.h"
#include <regex>

#ifndef REGEXTOKENIZER
#define REGEXTOKENIZER

namespace nlp
{
	class RegexBasedTokenizer : public Tokenizer
	{

		std::wregex regex;

	public:

		RegexBasedTokenizer(std::wstring regex);

		// Inherited via Tokenizer O(n) where n = len(string)
		std::vector<std::wstring> tokenize(std::wstring string) override;

	};
}

#endif // !SPACETOKENIZER
