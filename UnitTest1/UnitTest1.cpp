#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.3.IT/PR7.3.IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

         int** T = new int* [3];
         for (int i = 0; i < 3; i++) {

            T[i] = new int[3];
         }
         T[0][0] = 1;
         T[0][1] = 0;
         T[0][2] = -3;

         T[1][0] = 4;
         T[1][1] = 5;
         T[1][2] = -6;

         T[2][0] = 7;
         T[2][1] = 0;
         T[2][2] = 9;
         int t = number_ne_0(T, 3, 3);
         Assert::AreEqual(t, 1);

		}
	};
}
