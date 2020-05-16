#include<iostream>
using namespace std;

class A {
  int i;
public:
  A(int ii) : i(ii) {//Add a statement here}
  ~A() {//Add a statement here}
  void f() const {}
};

class B {
  int i;
public:
  B(int ii) : i(ii) {//Add a statement here}
  ~B() {//Add a statement here}
  void f() const {}
};

class C : public B {
  A a;
  B b;
public:
  C(int ii) : b(ii), B(ii), a(ii) {//Add a statement here}
  ~C() {//Add a statement here} 
  void f() const {
    a.f();
    B::f();
  }
};

int main() {
  C c(47);
  return 0;
}
