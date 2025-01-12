#pragma once
#include "classifier.h"
#include "spacebased_tokenizer.h"
#include <memory>
#include <unordered_set>

#ifndef NAIVEBAYESCLASSIFIER
#define NAIVEBAYESCLASSIFIER

namespace nlp
{
	class NaiveBayesClassifier : public Classifier
	{
	private:
		
		std::unordered_map<size_t, std::unordered_map<std::wstring, double>> data;
		std::unordered_map<size_t, double> prior;

	public:

		NaiveBayesClassifier();
		NaiveBayesClassifier(std::vector<std::wstring> classes);

		void train(std::vector<std::pair<std::wstring, std::wstring>> documents,
			Tokenizer* tokenizer = NULL, bool isMultinominal = true);

		friend std::wostream& operator<< (std::wostream& os, NaiveBayesClassifier x);

		// Inherited via Classifier
		std::wstring predict(std::wstring str, Tokenizer* tokenizer = NULL) override;

		void saveModel(std::filesystem::path path) override;

		void loadModel(std::filesystem::path path) override;

	};
}

#endif // !NAIVEBAYESCLASSIFIER
