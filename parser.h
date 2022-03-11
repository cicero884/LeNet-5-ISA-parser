#ifndef PARSER_H
#define PARSER_H

//TODO: check endian https://stackoverflow.com/questions/2100331/c-macro-definition-to-determine-big-endian-or-little-endian-machine
//
#include<cstdint>

struct __attribute__((__packed__)) base{
	enum opcode			:4;
}
enum opcode {
	layer_config;
	transfer_config;
	load_store;
	conv;
	pooling;
}
struct __attribute__((__packed__)) layer_config{
	enum opcode			:4;
	uint64_t input_w	:11;
	uint64_t input_h1	:11;
	uint64_t input_h2	:11;
	uint64_t f_size		:4;
	uint64_t f_num		:11;
	uint64_t stride		:4;
	uint64_t deq		:1;
};
struct __attribute__((__packed__)) transfer_config{
	enum opcode			:4;
	uint64_t tile_w		:6;
	uint64_t tile_h		:6;
	uint64_t channel	:10;
	uint64_t top_pad	:4;
	uint64_t bot_pad	:4;
	uint64_t left_pad	:4;
	uint64_t right_pad	:4;
};
struct __attribute__((__packed__)) load_store{
	enum opcode			:4;
	uint64_t DEPT		:4;
	uint64_t DRAM_addr	:32;
	uint64_t SRAM_ID	:2;
	uint64_t SRAM_add	:17;
};
struct __attribute__((__packed__)) conv{
	enum opcode			:4;
	uint64_t DEPT		:4;
	uint64_t OSRAM_addr	:12;
	uint64_t tile_w		:6;
	uint64_t tile_h		:6;
	uint64_t Ibank_addr	:4;
	uint64_t WSRAM_addr	:7;
	uint64_t ACT		:2;
	uint64_t L			:1;
	uint64_t shift		:4;
};
struct __attribute__((__packed__)) pooling{
	enum opcode			:4;
	uint64_t DEPT		:4;
	uint64_t OSRAM_addr	:12;
	uint64_t tile_w		:6;
	uint64_t tile_h		:6;
	uint64_t type		:3;
	uint64_t pool_size	:4;
	uint64_t stride 	:4;
};
union instruction{
	uint64_t binary;
	struct base;
	struct layer_config;
	struct transfer_config;
	struct load_store;
	struct conv;
	struct pooling;
}
#endif
