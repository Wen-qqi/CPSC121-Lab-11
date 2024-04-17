// Wen Fan
// CPSC 121L - 11
// April 22, 2024
// WenFan@csu.fullerton.edu
// @Wen-qqi
//
// Lab 11-1
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater

#include <memory>
#include <string>

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
 public:
  // ====================== YOUR CODE HERE ======================
  // 1. Define a constructor using member initializer list syntax
  //    according to the README.
  // 2. Define the accessor functions (i.e. the getter functions)
  //    `GetName`, `GetProductCount`, and `GetNextCustomer`.
  //    You do not need to create mutator functions (setters).
  // 3. Define the recursive functions specified in the README.
  // ============================================================
  Customer(const std::string& customers_name, int product_count,
           std::shared_ptr<Customer> next_customer)
      : name_(customers_name),
        product_count_(product_count),
        next_customer_(next_customer) {}

  const std::string& GetName() const;
  int GetProductCount() const;
  std::shared_ptr<Customer> GetNextCustomer() const;

  int TotalCustomersInLine();

  int TotalProductsInLine();

  const std::string& FirstAlphabeticalCustomerInLine();

 private:
  std::string name_;
  int product_count_;
  std::shared_ptr<Customer> next_customer_;
};
#endif