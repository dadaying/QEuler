#pragma once

#include "common/quantification/interest_util.h"
#include "common/quantification/type.h"

namespace qeuler::quantification {

template <class Money>
class Loaner {
 public:
  Loaner(const Money money, const uint64_t term,
         const InterestRateType interest_rate_type, const double interest_rate)
      : money_(money),
        interest_rate_type_(interest_rate_type),
        interest_rate_(
            ComputeMonthlyInterestRate(interest_rate, interest_rate_type_)),
        term_(ComputeMonthlyTerm(term, interest_rate_type_)) {}
  virtual ~Loaner() {}

  // TODO(liying): Implementing public loan logic.
  virtual LoaneRecord<Money> ComputeAmount() const = 0;

  virtual const LoaneRecord<Money>& Execute(const uint64_t num) {
    return loan_record_;
  }

 protected:
  Money money_ = 0.0;
  const InterestRateType interest_rate_type_ = InterestRateType::kMonth;
  uint64_t term_ = 0;
  double interest_rate_ = 0.0;
  LoaneRecord<Money> loan_record_;
};

}  // namespace qeuler::quantification