// Wen Fan
// CPSC 121L - 11
// April 22, 2024
// WenFan@csu.fullerton.edu
// @Wen-qqi
//
// Lab 11-1
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater

#include "customer.h"

#include <iostream>

// ========================= YOUR CODE HERE =========================
// This implementation file (customer.cc) is where you should implement
// the member functions declared in the header (customer.h), only
// if you didn't implement them inline within customer.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the Customer class.
// ===================================================================
const std::string& Customer::GetName() const {
  return name_;
}

int Customer::GetProductCount() const {
  return product_count_;
}

std::shared_ptr<Customer> Customer::GetNextCustomer() const {
  return next_customer_;
}

int Customer::TotalCustomersInLine() {
  if (next_customer_ == nullptr) {
    return 1;
  }
  return 1 + next_customer_->TotalCustomersInLine();
}

int Customer::TotalProductsInLine() {
  if (next_customer_ == nullptr) {
    return product_count_;
  }
  return product_count_ + next_customer_->TotalProductsInLine();
}

const std::string& Customer::FirstAlphabeticalCustomerInLine() {
  if (next_customer_ == nullptr) {
    return name_;
  } else {
    const std::string& temp_name =
        next_customer_->FirstAlphabeticalCustomerInLine();
    if (name_ < temp_name) {
      return name_;
    } else {
      return temp_name;
    }
  }
}