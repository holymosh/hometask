#ifndef LSTSTACK
#define LSTSTACK
class LstStack
{
public:
	LstStack() = default;
	LstStack(LstStack& obj);
	~LstStack();
	double pop();
	void push(const double value);
	double getTop() const;
private:

	struct Node;
	struct Node
	{
		Node* pNext_{ nullptr };
		double data_{ 0.0 };
	};
	Node* head_{ nullptr };

};


#endif
