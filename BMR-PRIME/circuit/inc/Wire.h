
#ifndef __WIRE_H__
#define __WIRE_H__

#include <vector>
#include <boost/thread/mutex.hpp>
#include <boost/thread.hpp>
#include "common.h"

class Gate;

typedef uint8_t signal_t;
#define NO_SIGNAL (2) //since this is a boolean circuit, valid values are either 0 or 1.

typedef struct Wire {
	signal_t _sig;	// the actual value that is passing	through the wire (after inputs have been set)
	std::vector<gate_id_t> _enters_to; //TODO make it a regular c array
	gate_id_t _out_from;
	bool _is_output;
	void* _data;
	Wire(bool out):_sig(NO_SIGNAL), _is_output(out),_out_from(NULL),_data(NULL){}
	inline signal_t Sig() { return _sig; }
	inline void Sig(signal_t s) { _sig = s; }
	void print(int w_id) {
		printf ("wire %d: sig=%d, is_out=%b, out_from=%d\n",w_id, (int)_sig, _is_output, _out_from);
	}
} Wire;

#endif
