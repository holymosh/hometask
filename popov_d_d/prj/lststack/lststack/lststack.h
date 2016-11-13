#ifndef LSTSTACK
#define LSTSTACK
class LstStack
{
public:
	LstStack() = default;
	LstStack(LstStack& obj);
	~LstStack();
	double pop();
	bool isEmpty();
	void push(const double value);
	double top();
	void remove();
	void deleteAll();
private:

	struct Node;
	struct Node
	{
		Node* pNext_{ nullptr };
		double data_{ 0.0 };
		Node() = default;
		Node(double data, Node* p)
			:data_{ data }, 
			pNext_{ p } 
		{}
	};

	Node* head_{ nullptr };

};


#endif
