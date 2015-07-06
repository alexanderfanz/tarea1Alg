#ifndef NODEST2_H_
#define NODEST2_H_

#include <map>

	
using namespace std;

namespace ns_suffix2 {
	
struct R_Value;

class Node_ST2 {
	
	public:
		map<char, R_Value> children;
		int position;
		
		
	public:
		Node_ST2();
		~Node_ST2();
		void set_position(int pos);
		bool is_c(char c, R_Value& result);
		R_Value insert_c(char c);
		int get_number_of_children();
		int get_position();
};

struct R_Value {
	Node_ST2* node;
	char* cad;
	int pos;
	int len;
};

}


#endif