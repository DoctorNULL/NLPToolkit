#pragma once
#include "stemmer.h"

#ifndef PORTERSTEMMER
#define PORTERSTEMMER

namespace nlp
{
	class PorterStemmer : public Stemmer
	{
	private :

		void step1a(std::wstring& in);
		void step1b(std::wstring& in);
		void step1c(std::wstring& in);

		void step2(std::wstring& in);

		void step3(std::wstring& in);

		void step4(std::wstring& in);

		void step5a(std::wstring& in);

		void step5b(std::wstring& in);


		size_t measure(std::wstring str);
		bool endcvc(std::wstring str);

	public:

		// Return the word to its original shape
		std::wstring stem(std::wstring string) override;

	};
}

#endif // !PORTERSTEMMER
