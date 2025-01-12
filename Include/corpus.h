#pragma once

#include <unordered_map>
#include <string>

#ifndef CORPUS
#define CORPUS

namespace nlp
{
	class Corpus
	{
	private:

		std::unordered_map<std::wstring, size_t> data;
		size_t currentIndex;

	public:

		Corpus();

		/* Adds new Vocab to the corpus
		* O(n) Where n is the number of words in sentance
		*/
		void AddData (std::vector<std::wstring> sentance);


		/* Checks if word exists in the corpus
		* O(1)
		*/
		bool wordExists(std::wstring word);

		/*Retrieve corpus size 
		O(1)
		*/
		size_t size();


		/*
		* Encode the input sentance
		* O(n) Where n = Size of Sentance
		*/
		std::vector<size_t> encodeSentance(std::vector<std::wstring> sentance);

		/*
		* Encode the input sentance 0 for non-exsistance, 1 for exsitance
		* O(n) Where n = Size of Sentance
		*/
		std::vector<bool> binaryEncodeSentance(std::vector<std::wstring> sentance);

		/*
		* Decode vector into original sentance
		* O(nm) Where n = Corpus size, m = vector size
		*/
		std::vector<std::wstring> decodeSentance(std::vector<size_t> vec);
	};
}

#endif // !CORPUS
