#include <iostream>

using namespace std;


int function() {
  static int count = 0;
  count++;
  return count;
}

int main() {
    //call the function 10 times:
  for (int i = 0; i < 10; ++i) {
    function();
  }
  //and call again to output:
  cout << function();
}
