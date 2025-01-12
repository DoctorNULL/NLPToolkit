#pragma once
#include <iostream>
#include <vector>
#include <map>

#ifndef DISPLAYERS
#define DISPLAYERS

template<typename T>
std::wostream& operator<< (std::wostream& os, const std::vector<T> vec)
{
	os << "[";

    for (size_t i = 0; i < vec.size(); ++i) 
    {
        os << vec[i];
        if (i != vec.size() - 1)
            os << ", ";
    }

	os << "]\n";

    return os;
}

template<typename T1, typename T2>
std::wostream& operator<< (std::wostream& os, const std::map<T1, T2> map)
{
    os << "{\n";

    for (std::pair<T1, T2> x : map)
    {
        os << "\t" << x.first << " : " << x.second << std::endl;
    }

    os << "}\n";
}

template<typename T1, typename T2>
std::wostream& operator<< (std::wostream& os, const std::unordered_map<T1, T2> map)
{
    os << "{\n";

    for (std::pair<T1, T2> x : map)
    {
        os << "\t" << x.first << " : " << x.second << std::endl;
    }

    os << "}\n";
}

#endif // !DISPLAYERS
