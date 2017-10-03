/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#define ATEST(value)                            \
  test(value, #value)

#define ATEST_MESSAGE(value, message)           \
  test(value, message)

#define ATEST_EQUAL(lhs, rhs)                   \
  test((lhs) == (rhs), #lhs " == " #rhs)

#define ATEST_ADD(klass) {                      \
    klass child;                                \
    run(child, #klass);                         \
  }

namespace atest {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Test {
 private:
  size_t testNum_;
  size_t failNum_;

 public:
  Test();
  virtual ~Test() = default;

  bool run();

 protected:
  void run(Test& test, const std::string& message);
  void test(bool value, const std::string& message);

  virtual void onRun() = 0;
};
/***********************************************************************//**
	@brief 
***************************************************************************/
}
