/*
** EPITECH PROJECT, 2019
** Utils.hpp
** File description:
** Util functions
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

class Utils {
	public:
		Utils();
		~Utils();
        bool isDigit(const std::string &s);
        int atoi(const std::string &s);
        void printUsage();
        bool strStr(std::string &s, const std::string &str);
        std::vector<std::string> split(std::string str, std::string elem);
        std::string getWordStr(const std::string &str, const std::string &wrd, std::string separator);
	private:
};

#endif /* !UTILS_HPP_ */
