#include <iostream>
#include <functional>

void plus(int a, int b)
{
  std::cout << a << " + " << b << " = " << a + b << std::endl;
}

int main()
{
  auto bind_plus = std::bind(
    plus,
    std::placeholders::_1,
    std::placeholders::_2
  );

  bind_plus(1, 2);

  // 3rd parameter will be ignored
  bind_plus(3, 4, 5);
  return 0;
}