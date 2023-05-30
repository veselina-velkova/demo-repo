#include<string>
#include<vector>
#pragma once

class TestClass
{
   private:
   std::string name;
   int number;
   float sum = 0.0;
   std::vector<float> grades{};

   public:
   TestClass();

   /* Methods */
   void test_getNumber();
   void test_valid_getNumber();
   void test_invalid_getNumber();
   void check_try_catch_getNumber(const int num, const std::string& name);

   void test_getName();
   void test_valid_getName();
   void test_invalid_getName();
   void check_getName(const int number, const std::string& name);

   void test_setNumber();
   void test_valid_setNumber();
   void test_invalid_setNumber();
   void check_setNumber();
   
};