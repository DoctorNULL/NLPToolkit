#pragma once
#include <string>
#include <math.h>
#include <vector>
#include <unordered_set>
#include <map>
#include "CharacterOperations.h"
#include "utilities.h"
#include <regex>
#include "spacebased_tokenizer.h"

#ifndef STRINGOPS
#define STRINGOPS

namespace nlp
{
	class StringOperation
	{
	public:

		/* Calculate the randomness of string
		O(n) where n = len(string) */
		static long double stringEntropy(std::wstring string);
		
		/* Retrieve all letters of string
		O(n log(n)) where n = len(string) */
		static std::vector <wchar_t> letters(std::wstring string);

		/* Calculate string's average
		O(n) where n = len(string) */
		static long double strAverage(std::wstring string);

		/* Calculate string's distances from average
		O(n) where n = len(string) */
		static std::vector<long double> strDistance(std::wstring string);

		/* Calculate string's average distance
		O(n) where n = len(string) */
		static long double strAvgDist(std::wstring string);

		/* Calculate string's letter length to the string's letter
		O(n) where n = len(string) */
		static long double charRatio(std::wstring string);

		/*Counts the number of vowels in the word
		O(nm) where n = len(string) and m = len(languageVowels)*/
		static size_t vowelsCount(std::wstring string);

		/*Lowers string case
		O(n) where n = len(string)*/
		static std::wstring toLower(std::wstring string);

		/*Uppers string case
		O(n) where n = len(string)*/
		static std::wstring toUpper(std::wstring string);

		/*Checks if string ends with pattern
		* O(n) where n = len(pattern)
		*/
		static bool endsWith(std::wstring string, std::wstring pattern);

		/*Checks if string starts with pattern
		* O(n) where n = len(pattern)
		*/
		static bool startsWith(std::wstring string, std::wstring pattern);

		/*Replace pattern a by pattern b in string
		* O(nm) where n = len(string) , m = len(patternb)
		*/
		static std::wstring replace(std::wstring string, std::wstring patternA, std::wstring stringB);

		/*Replace Suffix by newSuffix in string
		* O(nm) where n = len(string) , m = len(patternb)
		*/
		static std::wstring replaceSuffix(std::wstring string, std::wstring suffix, std::wstring newSuffix);

		/*Checks if string ends with double consonant
		* O(n) where n = len(vowels of language) Almost O(1)
		*/
		static bool endsWithDoubleConsonant(std::wstring string);

		/*Count occurace of pattern in string
		* O(nm) where n = len(pattern) , m = len(string)
		*/
		static size_t countPattern(std::wstring string, std::wstring pattern);

		/*
		* Returns a vector where 0 means 2 similar words, 1 differant words
		* O(nm) where n = len(sent) , m = len(biggest string)
		*/
		static std::vector<bool> sentSimilarityVector(std::wstring sent1, std::wstring sent2, Tokenizer* tokenizer = NULL);

		/*
		* Untokenize tokens to form sentance
		* O(n) where n = len(sent)
		*/
		static std::wstring untokenize(std::vector<std::wstring> vec, std::wstring seperator = L" ");
	};
}

#endif // !STRINGOPS
