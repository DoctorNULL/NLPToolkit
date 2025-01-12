#pragma once
#include "tokenizer.h"

#ifndef SPACETOKENIZER
#define SPACETOKENIZER

namespace nlp
{
	class SpaceBasedTokenizer : public Tokenizer
	{
	public:
		

		// Inherited via Tokenizer O(n) where n = len(string)
		std::vector<std::wstring> tokenize(std::wstring string) override;

	};
}

#endif // !SPACETOKENIZER
