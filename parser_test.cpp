#include<iostream>
#include<bitset>
#include"parser.h"
// assume input is hax(without 0x)
// and default is little endian

union instruction inst;

int main()
{
	while(std::cin.peek() != std::char_traits<char>::eof()){
		uint64_t in;
		std::cin >> std::hex >> in;
		inst.binary = in;// __builtin_bswap64(in);
		std::cout << std::bitset<64>(in) << std::endl;
		// std::cout << std::bitset<64>(inst.binary) << std::endl;
		std::cout << inst.base.opcode << std::endl;
		struct layer_config l;
		switch(inst.base.opcode){
			case layer_config:
				std::cout << std::endl;
				std::cout << l.opcode << std::endl;
				std::cout << l.input_w << std::endl;
				std::cout << l.input_h << std::endl;
				std::cout << l.input_c << std::endl;
				std::cout << l.f_size << std::endl;
				std::cout << l.f_num << std::endl;
				std::cout << l.stride << std::endl;
				std::cout << l.deq << std::endl;
				std::cout << std::endl;
				break;
			case transfer_config:
				break;
			case load_store:
				break;
			case conv:
				break;
			case pooling:
				break;
			default:
				break;
		}
	}
	return 0;
}
