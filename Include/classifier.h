#pragma once
#include <unordered_map>
#include <filesystem>
#include <vector>
#include <string>
#include "tokenizer.h"
#include <fstream>
#include <sstream>

#ifndef CLASSIFIER
#define CLASSIFIER

namespace nlp
{
	class Classifier
	{
	protected :
		
		std::unordered_map<size_t, std::wstring> labels;

		Classifier();
		Classifier(std::vector<std::wstring> classes);

	public:

		virtual std::wstring predict(std::wstring str, Tokenizer* tokenizer = NULL) = 0;
		virtual void saveModel(std::filesystem::path path) = 0;
		virtual void loadModel(std::filesystem::path path) = 0;

	};
}

#endif // !CLASSIFIER
