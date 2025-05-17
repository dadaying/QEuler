#pragma once

#include "common/quantification/type.h"

namespace qeuler::quantification {

double ComputeMonthlyInterestRate(const double interest_rate,
                                  const InterestRateType type) {
  switch (type) {
    case InterestRateType::kDay:
      return 0.0;
    case InterestRateType::kMonth:
      return interest_rate;
    case InterestRateType::kYear:
      return interest_rate / 12.0;
  }
}

uint64_t ComputeMonthlyTerm(const uint64_t term, const InterestRateType type) {
  switch (type) {
    case InterestRateType::kDay:
      return 0;
    case InterestRateType::kMonth:
      return term;
    case InterestRateType::kYear:
      return term * 12;
  }
}

}  // namespace qeuler::quantification