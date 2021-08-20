#include "tokenizer.h"

void interpret(std::istream& stream) {
	std::string s;
	while(getline(stream, s) && !startswith(s, "exit()")){
		// interpreter.getline(s);
	}
}

int main(){
	return 0;
}


/*
func name(x, y, z : Integer, alpha:Channel) -> Integer:
	for (i in 0:5)

	for (a in b):
		alpha = 5;
		beta = 20;
	end

	while ():

	end


end
*/
