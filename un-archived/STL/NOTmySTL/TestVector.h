#pragma once
#include"Vector.h"
#include<cassert>
#include<iostream>
#include<vector>
#include<string>

//#define TEST_ALL
//�������е����ܲ���
namespace STL {
	namespace testVector {
		template<class T>
		using myVector = STL::vector<T>;
		template<class T>
		using stdVector = std::vector<T>;

		void testAll();
		void testInsert();
		void testErase();
		void testPushBack();
		void testSize();
		void testConstruct();
		void testStdAndmySTL();
	}
}