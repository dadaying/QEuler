#pragma once

#include "common/quantification/loaner.h"
#include "common/quantification/type.h"

namespace qeuler::quantification {

template <class Money>
class EqualPrincipaler : public Loaner<Money> {
 public:
  EqualPrincipaler(const Money money, const uint64_t term,
                   const InterestRateType interest_rate_type,
                   const double interest_rate)
      : Loaner<Money>(money, term, interest_rate_type, interest_rate) {}

  ~EqualPrincipaler() = default;

  LoaneRecord<Money> ComputeAmount() const override {
    auto result = LoaneRecord<Money>();
    if (this->term_ == 0) {
      return result;
    }
    const auto average_principal = this->money_ / this->term_;
    auto current_principal = this->money_;
    for (uint64_t i = 0; i < this->term_; ++i) {
      result.AddLoanTrade(CommonTradeType<Money>(
          average_principal, current_principal * this->interest_rate_));
      current_principal -= average_principal;
    }
    return result;
  }

 private:
};

}  // namespace qeuler::quantification