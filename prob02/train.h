// Wen Fan
// CPSC 121L - 11
// April 22, 2024
// WenFan@csu.fullerton.edu
// @Wen-qqi
//
// Lab 1-2
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater

#include <memory>
#include <string>

#ifndef TRAIN_H
#define TRAIN_H

class Train {
 public:
  Train(int passenger_count, int seat_count,
        std::shared_ptr<Train> next_carriage)
      : passenger_count_(passenger_count),
        seat_count_(seat_count),
        next_carriage_(next_carriage) {}

  int GetPassengerCount() const {
    return passenger_count_;
  }
  int GetSeatCount() const {
    return seat_count_;
  }
  std::shared_ptr<Train> GetNextCarriage() const {
    return next_carriage_;
  }
  // ====================== YOUR CODE HERE ======================
  // Define the following recursive member functions, according
  // to the instructions in the README:
  //
  //   1. TotalTrainPassengers
  //   2. MaxCarriagePassengers
  //   3. IsTrainFull
  //   4. AddCarriageToEnd
  // ============================================================
  int TotalTrainPassengers() const {
    if (next_carriage_ == nullptr) {
      return passenger_count_;
    } else {
      return passenger_count_ + next_carriage_->TotalTrainPassengers();
    }
  }

  int MaxCarriagePassengers() const {
    if (next_carriage_ == nullptr) {
      return passenger_count_;
    } else {
      int max_next = next_carriage_->MaxCarriagePassengers();
      return std::max(passenger_count_, max_next);
    }
  }

  bool IsTrainFull() const {
    if (next_carriage_ == nullptr) {
      return passenger_count_ == seat_count_;
    }
    return passenger_count_ == seat_count_ && next_carriage_->IsTrainFull();
  }

  void AddCarriageToEnd(std::shared_ptr<Train> carriage) {
    if (next_carriage_ == nullptr) {
      next_carriage_ = carriage;
    } else {
      next_carriage_->AddCarriageToEnd(carriage);
    }
  }

 private:
  int passenger_count_;
  int seat_count_;
  std::shared_ptr<Train> next_carriage_;
};
#endif