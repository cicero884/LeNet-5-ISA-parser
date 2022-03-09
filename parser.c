#include<iostream>

// assume input is hax
// use stdin


struct instruction{
	unsigned opcode : 4;


};
struct instruction cur_inst;

int main()
{
	unsigned long long binary_inst;
	while(cin >> hax >> binary_inst != EOF){
		cur_inst = (struct instruction*)binary_inst;
		switch(cur_inst.opcode){
			case 0:
		}
	}
	return 0;
}
