#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include "tokenizer.h"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

#ifndef NGRAM
#define NGRAM

namespace nlp
{
	class NGram
	{
	private :

		uint32_t n, totalCount;
		std::unordered_map<std::wstring, size_t> data, countData;

		std::wstring concatStrings(std::vector<std::wstring> strings, wchar_t seperator = L'\0');

	public:

		NGram(uint32_t n);

		/*Fit the N-Gram to the input on character level
		O(len(inputData) * len(maxLength))*/
		void fit(std::vector<std::wstring> inputData);

		/*Fit the N-Gram to the input on sentance level using input tokenizer
		O(len(inputData) * len(maxLength))*/
		void fit(std::vector<std::wstring> inputData, Tokenizer* tokenizer);

		friend std::wostream& operator<< (std::wostream& os, NGram x);

		void saveToFile(std::filesystem::path path);
		void loadFromFile(std::filesystem::path path);

		/*Get Gram count for key
		O(1)*/
		int64_t getCount(std::wstring key);

		/*Get Gram probability for key based on prefix
		* smooth will use the add one smoothing
		O(1)*/
		long double getProbability(std::wstring key, std::wstring prefix = L"", bool smooth = false);

		/*Get Gram probability for Sentance
		* This Function For Character Level (for sentence level use the overloaded one with tokenizer)
		O(nm) Where n = N-GRAM, m = len(sent)*/
		long double getSentanceProbability(std::wstring sent, bool smooth = false);

		/*Get Gram probability for Sentance
		* This Function For Character Level (for sentence level use the overloaded one with tokenizer)
		O(nm) Where n = N-GRAM, m = len(sent)*/
		long double getSentanceProbability(std::wstring sent, Tokenizer* tokenizer, bool smooth = false);

		/*Calculate Gram power
		
		Gram power is the sum of probabilities of first, mid and last Grams of the string

		This Fucntion For Character Level (for sentence level use the overloaded one with tokenizer)

		O(n) where n = len(string)
		
		*/
		long double gramPower(std::wstring str);

		/*Calculate Gram power

		Gram power is the sum of probabilities of first, mid and last Grams of the string

		This Fucntion For Sentence Level (for character level use the overloaded one without tokenizer)

		O(n) where n = len(string)

		*/
		long double gramPower(std::wstring str, Tokenizer* tokenizer);
	};
}

#endif // !NGRAM
