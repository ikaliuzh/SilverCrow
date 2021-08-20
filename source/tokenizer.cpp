#pragma once

#include <iostream>
#include <string>
#include <vector>

bool StartsWith(const std::string& s, const std::string& t){
	if (s.size() < t.size())
		return false;
	return std::equal(t.begin(), t.end(), s.begin());
}

bool EndsWith(const std::string& s, const std::string& t){
	if (s.size() < t.size())
		return false;
	return std::equal(t.rbegin(), t.rend(), s.rbegin());
}
