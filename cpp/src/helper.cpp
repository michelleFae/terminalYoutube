#include "helper.h"

#include <iostream>
#include <sstream>
#include <vector>

#include <algorithm>
#include <string>


#include <locale>


using std::transform; using std::toupper;

std::string trim(std::string toTrim) {
  size_t trimPos = toTrim.find_first_not_of(" \t");
  toTrim.erase(0, trimPos);
  trimPos = toTrim.find_last_not_of(" \t");
  if (std::string::npos != trimPos) {
    toTrim.erase(trimPos + 1);
  }
  return toTrim;
}

std::vector<std::string> splitlines(std::string output) {
  std::vector<std::string> commandOutput;
  std::stringstream ss(output);
  std::string line;
  while (std::getline(ss, line, '\n')) {
    commandOutput.emplace_back(line);
  }
  return commandOutput;
}


// const std::string& toLowercase(const std::string s)
// {
//     transform(s.begin(), s.end(), s.begin(),
//                    [](unsigned char c){ return tolower(c); });
//     return &s;
// }


// std::string toLowercase(std::string& str)
// {
// 	std::locale settings;
// 	std::string converted;

// 	for(short i = 0; i < str.size(); ++i)
// 		converted += (std::toupper(str[i], settings));
	
// 	return converted;
// }