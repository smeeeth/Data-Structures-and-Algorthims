#include "pch.h"
#include "CppUnitTest.h"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Node.h"
#include "Node.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace DataStructuresandAlgorithmsTest
{
	TEST_CLASS(DataStructuresandAlgorithmsTest)
	{
	public:
		
		TEST_METHOD(TestLinkedList)
		{
			LinkedList<int> *list = new LinkedList<int>();
			Assert::AreEqual(list->size(), 0, std::wstring(L"List should be empty").c_str());

			list->addFirst(5);
			list->addFirst(4);
			list->addFirst(3);

			Assert::AreEqual(3, list->size(),std::wstring(L"List should be size 3").c_str());
			Assert::AreEqual(3, list->removeFirst(), std::wstring(L"First element should be 3").c_str());
			Assert::AreEqual(4, list->removeFirst(),std::wstring(L"First element should be 4").c_str());
			Assert::AreEqual(5, list->removeFirst(),std::wstring(L"First element should be 5").c_str());
			Assert::AreEqual(0, list->size(),std::wstring(L"List should be size 0").c_str());

			list->addFirst(5);
			list->addLast(6);
			list->addLast(7);

			Assert::AreEqual(3, list->size(), std::wstring(L"List should be size 3").c_str());
			Assert::AreEqual(5, list->removeFirst(), std::wstring(L"First element should be 5").c_str());
			Assert::AreEqual(6, list->removeFirst(), std::wstring(L"First element should be 6").c_str());
			Assert::AreEqual(7, list->removeFirst(), std::wstring(L"First element should be 7").c_str());
			Assert::AreEqual(0, list->size(), std::wstring(L"List should be size 0").c_str());

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
	};
}
