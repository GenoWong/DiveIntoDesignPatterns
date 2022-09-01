#include "Builder.h"
/**
 * The client code creates a builder object, passes it to the director and then
 * initiates the construction process. The end result is retrieved from the
 * builder object.
 */
/**
 * I used raw pointers for simplicity however you may prefer to use smart
 * pointers here
 */
void ClientCode(Director& director) {
  ConcreteBuilder1* builder = new ConcreteBuilder1();
  director.set_builder(builder);
  std::cout << "Standard basic product:\n";
  director.BuildMinimalViableProduct();

  Product1* p = builder->GetProduct();
  p->ListParts();
  delete p;

  std::cout << "Standard full featured product:\n";
  director.BuildFullFeaturedProduct();

  p = builder->GetProduct();
  p->ListParts();
  delete p;

  // Remember, the Builder pattern can be used without a Director class.
  std::cout << "Custom product:\n";
  builder->ProducePartA();
  builder->ProducePartC();
  p = builder->GetProduct();
  p->ListParts();
  delete p;

  delete builder;
}

int main() {
  Director* director = new Director();
  ClientCode(*director);
  delete director;
  return 0;
}