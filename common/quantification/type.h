#pragma once

namespace qeuler::quantification {

enum class InterestRateType : uint8_t {
  kDay = 0,
  kMonth = 1,
  kYear = 2,
};

template <class Money>
class CommonTradeType {
 public:
  CommonTradeType(const Money principal, const Money interest)
      : principal_(principal), interest_(interest) {
    total_ = principal + interest;
    interest_fraction_ =
        static_cast<double>(interest_) / static_cast<double>(total_);
  }

  ~CommonTradeType() = default;

  std::string DebugString() const {
    return "total=" + std::to_string(total_) +
           ", principal=" + std::to_string(principal_) +
           ", interest=" + std::to_string(interest_) +
           ", interest_fraction=" + std::to_string(interest_fraction_);
  }

  const Money& get_principal() const { return principal_; }
  const Money& get_interest() const { return interest_; }
  const Money& get_total() const { return total_; }

 private:
  Money principal_ = 0.0;
  Money interest_ = 0.0;
  Money total_ = 0.0;
  double interest_fraction_ = 0.0;
};

template <class Money>
class LoaneRecord {
 public:
  LoaneRecord() = default;
  ~LoaneRecord() = default;

  void AddLoanTrade(const CommonTradeType<Money>& trade) {
    trades_.push_back(trade);
  }

  const std::vector<CommonTradeType<Money>>& get_trades() const {
    return trades_;
  }

 private:
  std::vector<CommonTradeType<Money>> trades_;
};

}  // namespace qeuler::quantification