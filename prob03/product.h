// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>
//
// Lab 11-3
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater

#include <memory>
#include <string>

class Product {
 public:
  // =================== YOUR CODE HERE ===================
  // Create a constructor that accepts a name, a price,
  // a Product pointer to the left and Product pointer to the right.
  // ======================================================

  const std::string &Name() const {
    return name_;
  }
  double Price() const {
    return price_;
  }
  // =================== YOUR CODE HERE ===================
  // Create a recursive function called FindPrice that returns
  // the price of a product.
  // ======================================================

 private:
  std::string name_;
  double price_;
  // =================== YOUR CODE HERE ===================
  // Create pointer to the left Product
  // Create pointer to the right Product
  // ======================================================
};