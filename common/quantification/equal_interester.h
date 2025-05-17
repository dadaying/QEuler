#pragma once

#include "common/quantification/loaner.h"
#include "common/quantification/type.h"

namespace qeuler::quantification {

template <class Money>
class EqualInterester : public Loaner<Money> {
 public:
  EqualInterester(const Money money, const uint64_t term,
                  const InterestRateType interest_rate_type,
                  const double interest_rate)
      : Loaner<Money>(money, term, interest_rate_type, interest_rate) {}

  ~EqualInterester() = default;

  LoaneRecord<Money> ComputeAmount() const override {
    const Money total_interest =
        this->money_ * this->interest_rate_ * this->term_;
    const auto monthly_interest = this->money_ * this->interest_rate_;
    const auto monthly_pay =
        monthly_interest /
            (std::pow(1 + this->interest_rate_, this->term_) - 1) +
        monthly_interest;
    double tmp = 1.0;
    LoaneRecord<Money> result;
    for (uint64_t i = 0; i < this->term_; ++i) {
      const auto current_monthly_interest =
          (monthly_interest - monthly_pay) * tmp + monthly_pay;
      tmp *= (1 + this->interest_rate_);
      result.AddLoanTrade(CommonTradeType<Money>(
          monthly_pay - current_monthly_interest, current_monthly_interest));
    }
    return result;
  }

 private:
};

}  // namespace qeuler::quantification