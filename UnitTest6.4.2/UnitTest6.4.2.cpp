#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.4.2/project6.4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest642
{
	TEST_CLASS(UnitTest642)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int n = 10;
			int p[10] = { 1,2,3,4,5,6,7,8,-9,10 };
			int min_value;
			int min_index;
			find_min_index(p,n,0,&min_value,&min_index);
			c = Sum(p, n, min_index +1);
			Assert::AreEqual(c, 10);
		}
	};
}
