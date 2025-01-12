#pragma once
#include "tokenizer.h"

#ifndef SEPERATORTOKENIZER
#define SEPERATORTOKENIZER

namespace nlp
{
	class SeperatorBasedTokenizer : public Tokenizer
	{
	private :

		std::wstring seperator;

	public:

		SeperatorBasedTokenizer(std::wstring seperator = L".");

		// Inherited via Tokenizer O(nm) where n = len(string) and m = len(seperator)
		std::vector<std::wstring> tokenize(std::wstring string) override;

	};
}

#endif // !SEPERATORTOKENIZER
