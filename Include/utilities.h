#pragma once
#include <vector>
#include <string>
#include "CharacterOperations.h"

#ifndef NLPUTIL
#define NLPUTIL

namespace nlp
{
	template<typename T>
	std::vector<T> sliceVector(std::vector<T> vec, size_t from, size_t to)
	{
		std::vector<T> res;

		for (size_t i = from; i < to && i < vec.size(); i++)
		{
			res.push_back(vec[i]);
		}

		return res;
	}

	class LanguageUtils
	{
	public:
		
		static std::vector<wchar_t> getLanguageVowels(language lang)
		{
			const std::vector<wchar_t> englishVowels = { L'a' , L'e', L'i', L'o', L'u' };
			const std::vector<wchar_t> arabicVowels = { L'ا' , L'ي', L'و' };

			switch (lang)
			{
			case nlp::english:
				return englishVowels;
			case nlp::arabic:
				return arabicVowels;
			case nlp::unknown:
				return std::vector<wchar_t>();
			default:
				return std::vector<wchar_t>();
			}
		}
	};
}

#endif // !NLPUTIL
