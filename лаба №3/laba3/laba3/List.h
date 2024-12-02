#pragma once
class List
{
	List();
	~List();


private:
	class Node
	{
	public:
		Node* pNext;
		int data;

	protected:
		Node(int data, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
		Node* head;
		int Size;

	}
};