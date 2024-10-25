#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void checkStack(vector<int>& sm ,size_t size){
	if(sm.size() < size){
		throw std::runtime_error("Not enough elements in the Stack");
	}
}
 
void sum (vector<int>& sm){
	checkStack(sm, 2);
	int b = sm.back();
	sm.pop_back();
	int a = sm.back();
	sm.pop_back();
	sm.push_back(a + b);
}
void substract (vector<int>& sm){
        checkStack(sm, 2);
        int b = sm.back();
        sm.pop_back();
        int a = sm.back();
        sm.pop_back();
        sm.push_back(a - b);
}
void multiply (vector<int>& sm){
        checkStack(sm, 2);
        int b = sm.back();
        sm.pop_back();
        int a = sm.back();
        sm.pop_back();
        sm.push_back(a * b);
}
void division (vector<int>& sm){
        checkStack(sm, 2);
        int b = sm.back();
        sm.pop_back();
        int a = sm.back();
        sm.pop_back();
        sm.push_back(a / b);
}
void remainder (vector<int>& sm){
        checkStack(sm, 2);
        int b = sm.back();
        sm.pop_back();
        int a = sm.back();
        sm.pop_back();
        sm.push_back(a % b);
}

void inst(vector<int>& sm, vector<string>& instruct){
    for (const string& instruction : instruct){
        if(instruction == "+"){
            sum(sm);
        }
        else if (instruction == "-"){
            substract(sm);
        }
        else if (instruction == "*"){
            multiply(sm);
        }
        else if (instruction == "/"){
            division(sm);
        }
        else if (instruction == "%"){
            remainder(sm);
        }
        else{
            int number = stoi(instruction);
            sm.push_back(number);
        }
    }

}

int main(){
    vector<int> sm;
    vector<string> instruct = {"3", "7", "+", "8", "*","63", "+", "2", "/"};
    for(int i = 0; i < instruct.size(); i++){
    	inst(sm, instruct);
    }
	std::cout << "Result: " << sm.back() << endl;
    return 0;
}
