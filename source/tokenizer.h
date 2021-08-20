#pragma once

#include <iostream>
#include <string>
#include <vector>



inline bool startswith(const std::string& s, const std::string& t){
	if (s.size() < t.size())
		return false;
	return std::equal(t.begin(), t.end(), s.begin());
}

inline bool endswith(const std::string& s, const std::string& t){
	if (s.size() < t.size())
		return false;
	return std::equal(t.rbegin(), t.rend(), s.rbegin());
}


void tokenize(const std::string& line) {

	static bool comment_block = false;

	size_t i = 0;

	while(i < line.size()){

		if (isspace(line[i])) { ++i; continue; }

		// Comments
		if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/'){
			if (comment_block == false){
				// error to be thrown
			} else {
				comment_block = false;
				i += 2;
				continue;
			}
		}

		if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*'){
			comment_block = true;
			i += 2;
			continue;
		}

		if (comment_block) { ++i; continue; }

		if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') break;

	}
}

enum TokenType {
	Integer,
	Float,
	String,
	Ident,

	If,
	Else,

	While,
	For,
	In,
	Break,
	Continue,

	Function,
	Return,
	Class,
	Enum,

	True,
	False,

	Void,


};

struct Token{
	size_t line;
	size_t col;
	TokenType type;
	std::string data;
};

TokenType classify(const std::string& s){
	return
}

inline bool is_digit(char c){
	return ('0' <= c && c <= '9');
}

inline bool is_numchar(char c){
	return is_digit(c) || c == '.';
}

std::string get_name(const std::string& line, size_t& i){
	std::string buf;
	buf.push_back(line[i++]);
	while (i < line.size() && (isalnum(line[i]) || line[i] == '_'))
		buf.push_back(line[i]);
	return buf;
}

std::string get_number(const std::string& line, size_t& i, TokenType& ttype){
	std::string buf;
	bool decimaldot = false;

	while (i < line.size() && is_numchar(line[i])){
		if (line[i] == '.'){
			if (decimaldot){
				ttype = TokenType::Float;
				decimaldot = true;
			}
			else {
				// throw error as decimal dot encountered second time
			}
		}

		buf.push_back(line[i++]);
	}
	return buf;
}



void tokenize(std::istream& stream) {
	std::string line;
	while(getline(stream, line) && !startswith(line, "exit()")){
		tokenize(line);
	}
}




