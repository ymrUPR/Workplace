#include <iostream>
#include <vector>
#include <string>
using namespace std;



vector<unsigned char> cell(30000, 0);
size_t p = 0;


size_t findMatchingBracket(string& input, size_t index){
  char open = input[index];
  char close = (open == '[') ? ']' : '[';
  int balance = 1;
  int step = (open == '[') ? 1 : -1;

  for (int i = static_cast<int>(index) + step; i >= 0 && i < static_cast<int>(input.size()); i += step){ //init
    if(input[i] == open) balance++;
    else if( input[i] == close) balance--;
    if (balance == 0) return static_cast<size_t>(i);
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
        cell[p] = cin.get();
        break;

      case '[':
        if(cell[p] == 0){
          i = findMatchingBracket(input, i);
        }
        else {
          loopStack.push_back(i);
        }
        break;

      case ']':
        if(cell[p] != 0){
          i = loopStack.back();
          }
        else {
          loopStack.pop_back();
        }
        break;
		}
	}
}

int main(){
  string input;
  cout << "Enter Brainfuck code: ";
  getline(cin, input);
  instructions(input);
  cout << endl;

  return 0;
}



