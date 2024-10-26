#include <iostream>
#include <vector>
#include <string>
using namespace std;



vector<unsigned char> cell(30000, 0);
size_t p = 0;


size_t findMatchingBracket(string& input, size_t index){
    int balance = 1;
    if (input[index] == '['){
        for(size_t i = index + 1; i < input.size(); ++i){
            if(input[i] == '[')
                ++balance;
            if(input[i] == ']')
                --balance;
            if(balance == 0)
                return i;
        }
    }

    else if(input[index] == ']'){
        for(size_t i = index - 1; i >= 0; --i){
            if(input[i] == ']')
              ++balance;
            if(input[i] == '[')
              --balance;
            if(balance == 0)
              return i;
        }
    }
    throw std::runtime_error("Unmatched bracket at position " + std::to_string(index));
}



void instructions(string& input){
	size_t size = input.size();
	vector<size_t> loopStack;

	for(size_t i = 0; i < size; i++){
		char command = input[i];

    if (p >= cell.size())
      cell.push_back(0);

		switch(command) {
      case '>':
        ++p;
        if(p >= cell.size())
          cell.push_back(0);
        break;

      case '<':
        if (p > 0)
          --p;
        break;

      case '+':
        ++cell[p];
        break;

      case '-':
        --cell[p];
        break;

      case '.':
        cout << static_cast<char>(cell[p]);
        break;

      case ',':
        cout << "Input something for the cell: ";
        cin >> cell[p];
        break;

      case '[':
          if (cell[p] == 0) 
              i = findMatchingBracket(input, i);
          break;

      case ']':
          if (cell[p] != 0) 
              i = findMatchingBracket(input, i);
          break;
		}
	}
}

int main(){
  string input;
  cout << "Enter Brainfuck input: ";
  getline(cin, input);
  instructions(input);
  cout << endl;

  return 0;
}



