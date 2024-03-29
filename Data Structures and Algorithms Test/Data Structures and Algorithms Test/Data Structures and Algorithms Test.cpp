#include "pch.h"
#include "CppUnitTest.h"
#include "Node.h"
#include "Node.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "ArrayList.h"
#include "ArrayList.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace DataStructuresandAlgorithmsTest
{
	TEST_CLASS(TestLinkedList)
	{
	public:
		TEST_METHOD(TestLinkedList1)
		{
			LinkedList<int>* list = new LinkedList<int>();
			Assert::AreEqual(list->size(), 0, std::wstring(L"List should be empty").c_str());

			list->addFirst(5);
			list->addFirst(4);
			list->addFirst(3);

			Assert::AreEqual(3, list->size(), std::wstring(L"List should be size 3").c_str());
			Assert::AreEqual(3, list->removeFirst(), std::wstring(L"First element should be 3").c_str());
			Assert::AreEqual(4, list->removeFirst(), std::wstring(L"First element should be 4").c_str());
			Assert::AreEqual(5, list->removeFirst(), std::wstring(L"First element should be 5").c_str());
			Assert::AreEqual(0, list->size(), std::wstring(L"List should be size 0").c_str());
		}
		
		TEST_METHOD(TestLinkedList2)
		{
			LinkedList<int>* list = new LinkedList<int>();
			list->addFirst(5);
			list->addLast(6);
			list->addLast(7);

			Assert::AreEqual(3, list->size(), std::wstring(L"List should be size 3").c_str());
			Assert::AreEqual(5, list->removeFirst(), std::wstring(L"First element should be 5").c_str());
			Assert::AreEqual(6, list->removeFirst(), std::wstring(L"First element should be 6").c_str());
			Assert::AreEqual(7, list->removeFirst(), std::wstring(L"First element should be 7").c_str());
			Assert::AreEqual(0, list->size(), std::wstring(L"List should be size 0").c_str());
		}

		TEST_METHOD(TestLinkedList3)
		{
			LinkedList<int>* list = new LinkedList<int>();
			list->addFirst(5);
			list->addLast(6);
			list->addFirst(4);
			list->addFirst(3);

			Assert::AreEqual(4, list->size(), std::wstring(L"List should be size 4").c_str());
			Assert::AreEqual(3, list->removeFirst(), std::wstring(L"First element should be 3").c_str());
			Assert::AreEqual(4, list->removeFirst(), std::wstring(L"First element should be 4").c_str());
			Assert::AreEqual(5, list->removeFirst(), std::wstring(L"First element should be 5").c_str());
			Assert::AreEqual(6, list->removeFirst(), std::wstring(L"First element should be 6").c_str());
			Assert::AreEqual(0, list->size(), std::wstring(L"List should be size 0").c_str());
		}

		TEST_METHOD(TestLinkedList4) {

			LinkedList<int>* list = new LinkedList<int>();
			list->addFirst(4);
			list->addFirst(3);
			list->addLast(5);
			list->addFirst(2);

			Assert::AreEqual(4, list->size(), std::wstring(L"List should be size 4").c_str());
			Assert::AreEqual(5, list->removeLast(), std::wstring(L"Last element should be 5").c_str());
			Assert::AreEqual(4, list->removeLast(), std::wstring(L"Last element should be 4").c_str());
			Assert::AreEqual(3, list->removeLast(), std::wstring(L"Last element should be 3").c_str());
			Assert::AreEqual(2, list->removeLast(), std::wstring(L"Last element should be 2").c_str());
			Assert::AreEqual(0, list->size(), std::wstring(L"List should be size 0").c_str());
		}

		TEST_METHOD(TestLinkedList5) {

			LinkedList<int>* list = new LinkedList<int>();
			list->addFirst(1);
			list->addLast(2);
			list->addLast(3);
			list->addLast(4);
			list->remove(2);

			Assert::AreEqual(3, list->size(), std::wstring(L"List should be size 3").c_str());
			Assert::AreEqual(1, list->removeFirst(), std::wstring(L"First element should be 1").c_str());
			Assert::AreEqual(3, list->removeFirst(), std::wstring(L"First element should be 3").c_str());
			Assert::AreEqual(4, list->removeFirst(), std::wstring(L"First element should be 4").c_str());
			Assert::AreEqual(0, list->size(), std::wstring(L"List should be size 0").c_str());

			Assert::IsNull(list->remove(2), std::wstring(L"Removing element not in list should return null.").c_str());
		}

		TEST_METHOD(TestLinkedList6) {

			LinkedList<int>* list = new LinkedList<int>();
			list->addFirst(1);
			list->insertAfter(1, 3);
			list->insertBefore(3, 2);
			list->insertAfter(3, 4);

			Assert::AreEqual(4, list->size(), std::wstring(L"List should be size 4").c_str());
			Assert::AreEqual(1, list->removeFirst(), std::wstring(L"First element should be 1").c_str());
			Assert::AreEqual(2, list->removeFirst(), std::wstring(L"First element should be 2").c_str());
			Assert::AreEqual(3, list->removeFirst(), std::wstring(L"First element should be 3").c_str());
			Assert::AreEqual(4, list->removeFirst(), std::wstring(L"First element should be 4").c_str());
		}

		TEST_METHOD(TestLinkedList7) {

			LinkedList<int>* list = new LinkedList<int>();
			list->addFirst(1);
			list->addLast(2);
			list->addLast(3);
			list->addLast(4);
			list->addLast(5);
			list->addLast(6);

			Assert::AreEqual(6, list->size(), std::wstring(L"List should be size 6").c_str());

			Assert::AreEqual(1, list->removeAtPosition(0), std::wstring(L"Element at position 0 should be 1").c_str());

			auto func = [list] {list->removeAtPosition(6); };
			Assert::ExpectException<std::out_of_range>(func, std::wstring(L"Remove at invalid index should throw exception").c_str());

			Assert::AreEqual(6, list->removeAtPosition(4), std::wstring(L"Element at position 5 should be 6").c_str());
		}

		
	};

	TEST_CLASS(TestQueue)
	{
	public:
		TEST_METHOD(TestQueue1) {
			Queue<int>* queue = new Queue<int>();
			
			queue->enqueue(5);
			queue->enqueue(4);
			queue->enqueue(3);
			queue->enqueue(2);
			queue->enqueue(1);

			Assert::AreEqual(5, queue->size(), std::wstring(L"Queue should be size 5").c_str());
			Assert::AreEqual(1, queue->dequeue(), std::wstring(L"Element at top of queue should be 1").c_str());
			Assert::AreEqual(2, queue->dequeue(), std::wstring(L"Element at top of queue should be 2").c_str());
			Assert::AreEqual(3, queue->dequeue(), std::wstring(L"Element at top of queue should be 3").c_str());
			
			queue->enqueue(10);


			Assert::AreEqual(3, queue->size(), std::wstring(L"Queue should be size 3").c_str());
			Assert::AreEqual(10, queue->dequeue(), std::wstring(L"Element at top of queue should be 10").c_str());
			Assert::AreEqual(4, queue->dequeue(), std::wstring(L"Element at top of queue should be 4").c_str());
			Assert::AreEqual(5, queue->dequeue(), std::wstring(L"Element at top of queue should be 5").c_str());
			

			Assert::AreEqual(0, queue->size(), std::wstring(L"Queue should be size 0").c_str());
		}
	};

	TEST_CLASS(TestStack)
	{
	public:
		TEST_METHOD(TestStack1) {
			Stack<int>* stack = new Stack<int>();

			stack->push(1);
			stack->push(2);
			stack->push(3);
			stack->push(4);
			stack->push(5);

			Assert::AreEqual(5, stack->size(), std::wstring(L"Stack should be size 5").c_str());
			Assert::AreEqual(1, stack->pop(), std::wstring(L"Element at top of queue should be 1").c_str());
			Assert::AreEqual(2, stack->peek(), std::wstring(L"Element at top of queue should be 2").c_str());
			Assert::AreEqual(2, stack->pop(), std::wstring(L"Element at top of queue should be 2").c_str());
			Assert::AreEqual(3, stack->pop(), std::wstring(L"Element at top of queue should be 3").c_str());

			stack->push(10);

			Assert::AreEqual(4, stack->pop(), std::wstring(L"Queue should be size 4").c_str());
			Assert::AreEqual(5, stack->pop(), std::wstring(L"Element at top of queue should be 5").c_str());
			Assert::AreEqual(10, stack->pop(), std::wstring(L"Element at top of queue should be 10").c_str());

		}
	};

	TEST_CLASS(TestArrayList)
	{
	public:
		TEST_METHOD(TestArrayList1) {
			ArrayList<int>* list = new ArrayList<int>();

			list->set(1, 0);
			list->set(2, 1);
			list->set(3, 2);
			list->set(4, 3);
			list->set(5, 4);

			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());
			Assert::AreEqual(2, list->get(1), std::wstring(L"Element at index 1 should be 2").c_str());
			Assert::AreEqual(3, list->get(2), std::wstring(L"Element at index 2 should be 3").c_str());
			Assert::AreEqual(4, list->get(3), std::wstring(L"Element at index 3 should be 4").c_str());
			Assert::AreEqual(5, list->get(4), std::wstring(L"Element at index 4 should be 5").c_str());

		}

		TEST_METHOD(TestArrayList2) {
			ArrayList<int>* list = new ArrayList<int>();

			list->set(1, 0);
			list->set(5, 4);
			list->set(2, 1);
			
			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());
			Assert::AreEqual(2, list->get(1), std::wstring(L"Element at index 1 should be 2").c_str());
			Assert::AreEqual(5, list->get(4), std::wstring(L"Element at index 2 should be 5").c_str());
			
			list->set(3, 2);

			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());
			Assert::AreEqual(2, list->get(1), std::wstring(L"Element at index 1 should be 2").c_str());
			Assert::AreEqual(3, list->get(2), std::wstring(L"Element at index 2 should be 3").c_str());
			Assert::AreEqual(5, list->get(4), std::wstring(L"Element at index 2 should be 5").c_str());

			list->set(4, 3);

			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());
			Assert::AreEqual(2, list->get(1), std::wstring(L"Element at index 1 should be 2").c_str());
			Assert::AreEqual(3, list->get(2), std::wstring(L"Element at index 2 should be 3").c_str());
			Assert::AreEqual(4, list->get(3), std::wstring(L"Element at index 3 should be 4").c_str());
			Assert::AreEqual(5, list->get(4), std::wstring(L"Element at index 4 should be 5").c_str());

		}

		TEST_METHOD(TestArrayList3) {
			ArrayList<int>* list = new ArrayList<int>();

			list->set(1, 0);
			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());

			list->set(4, 3);
			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());
			Assert::AreEqual(4, list->get(3), std::wstring(L"Element at index 3 should be 4").c_str());

			list->set(3, 2);
			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());
			Assert::AreEqual(3, list->get(2), std::wstring(L"Element at index 2 should be 3").c_str());
			Assert::AreEqual(4, list->get(3), std::wstring(L"Element at index 3 should be 4").c_str());

			list->set(5, 4);
			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());
			Assert::AreEqual(3, list->get(2), std::wstring(L"Element at index 2 should be 3").c_str());
			Assert::AreEqual(4, list->get(3), std::wstring(L"Element at index 3 should be 4").c_str());
			Assert::AreEqual(5, list->get(4), std::wstring(L"Element at index 4 should be 5").c_str());

			list->set(2, 1);

			Assert::AreEqual(1, list->get(0), std::wstring(L"Element at index 0 should be 1").c_str());
			Assert::AreEqual(2, list->get(1), std::wstring(L"Element at index 1 should be 2").c_str());
			Assert::AreEqual(3, list->get(2), std::wstring(L"Element at index 2 should be 3").c_str());
			Assert::AreEqual(4, list->get(3), std::wstring(L"Element at index 3 should be 4").c_str());
			Assert::AreEqual(5, list->get(4), std::wstring(L"Element at index 4 should be 5").c_str());

		}

		TEST_METHOD(TestArrayList4) {
			ArrayList<bool>* list = new ArrayList<bool>(false, 10);

			list->set(true, 1);
			list->set(true, 3);
			list->set(true, 5);
			list->set(true, 7);
			list->set(true, 9);

			Assert::AreEqual(false, list->get(0), std::wstring(L"Element at index 0 should be false").c_str());
			Assert::AreEqual(true, list->get(1), std::wstring(L"Element at index 1 should be true").c_str());
			Assert::AreEqual(false, list->get(2), std::wstring(L"Element at index 2 should be false").c_str());
			Assert::AreEqual(true, list->get(3), std::wstring(L"Element at index 3 should be true").c_str());
			Assert::AreEqual(false, list->get(4), std::wstring(L"Element at index 4 should be false").c_str());
			Assert::AreEqual(true, list->get(5), std::wstring(L"Element at index 5 should be true").c_str());
			Assert::AreEqual(false, list->get(6), std::wstring(L"Element at index 6 should be false").c_str());
			Assert::AreEqual(true, list->get(7), std::wstring(L"Element at index 7 should be true").c_str());
			Assert::AreEqual(false, list->get(8), std::wstring(L"Element at index 8 should be false").c_str());
		}

		TEST_METHOD(TestArrayList5) {
			ArrayList<int>* list = new ArrayList<int>();

			list->set(1, 0);
			list->set(2, 1);
			list->set(3, 2);
			list->set(4, 3);
			list->set(5, 4);

			Assert::AreEqual(0, list->indexOf(1), std::wstring(L"Element 1 should be at index 0").c_str());
			Assert::AreEqual(1, list->indexOf(2), std::wstring(L"Element 2 should be at index 1").c_str());
			Assert::AreEqual(2, list->indexOf(3), std::wstring(L"Element 3 should be at index 2").c_str());
			Assert::AreEqual(3, list->indexOf(4), std::wstring(L"Element 4 should be at index 3").c_str());
			Assert::AreEqual(4, list->indexOf(5), std::wstring(L"Element 5 should be at index 4").c_str());

			list->set(6, 2);
			Assert::AreEqual(2, list->indexOf(6), std::wstring(L"Element 6 should be at index 2").c_str());

		}

		TEST_METHOD(TestArrayList6) {
			ArrayList<LinkedList<int>*>* list = new ArrayList<LinkedList<int>*>(new LinkedList<int>(), 10);

			list->get(0)->addFirst(5);

			LinkedList<int>* firstList = list->get(0);
			Assert::AreEqual(1, firstList->size(), std::wstring(L"List should be size 1").c_str());
			Assert::AreEqual(5, firstList->removeFirst(), std::wstring(L"First element should be 5").c_str());
			Assert::AreEqual(0, firstList->size(), std::wstring(L"List should be empty").c_str());
			Assert::AreEqual(0, list->get(1)->size(), std::wstring(L"Element at index 1 should be empty list").c_str());
		}

		TEST_METHOD(TestArrayList7) {
			ArrayList<LinkedList<int>*>* list = new ArrayList<LinkedList<int>*>(nullptr, 10);

			list->set(new LinkedList<int>(5), 0);

			LinkedList<int>* firstList = list->get(0);
			Assert::AreEqual(1, firstList->size(), std::wstring(L"List should be size 1").c_str());			
			Assert::AreEqual(5, firstList->removeFirst(), std::wstring(L"First element should be 5").c_str());			
			Assert::IsNull(list->get(1), std::wstring(L"Element at index 1 should be null").c_str());
		}
	};
}
