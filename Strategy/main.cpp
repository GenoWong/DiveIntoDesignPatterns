#include "Strategy.h"
/**
 * The client code picks a concrete strategy and passes it to the context. The
 * client should be aware of the differences between strategies in order to make
 * the right choice.
 */

void clientCode() {
  Context context(std::make_unique<ConcreteStrategyA>());
  std::cout << "Client: Strategy is set to normal sorting.\n";
  context.doSomeBusinessLogic();
  std::cout << "\n";
  std::cout << "Client: Strategy is set to reverse sorting.\n";
  context.set_strategy(std::make_unique<ConcreteStrategyB>());
  context.doSomeBusinessLogic();
}

int main() {
  clientCode();
  return 0;
}