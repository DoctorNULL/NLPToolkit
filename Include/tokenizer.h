#pragma once
#include <vector>
#include <string>

#ifndef TOKENIZERBASE
#define TOKENIZERBASE

namespace nlp
{
	class Tokenizer
	{
	public:
		virtual std::vector<std::wstring> tokenize(std::wstring string) = 0;
	};
}

#endif // !TOKENIZERBASE
