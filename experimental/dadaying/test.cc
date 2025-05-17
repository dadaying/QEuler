#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

#include "common/math/vec_2.h"
#include "common/quantification/equal_interester.h"
#include "common/quantification/equal_principaler.h"
#include "common/quantification/type.h"

enum class EquipmentType : uint8_t {
  kArms = 0,
  kArmor = 1,
  kJewelry = 2,
};

enum class EquipmentGrade : uint8_t {
  kWhiteEquipment = 0,
  kBlueEquipment = 1,
  kPinkEquipment = 2,
  kEpicEquipment = 3,
  kMaxEpicEquipment = 4
};

class Equipment {
 public:
  Equipment(const std::string& name, const std::string& describe,
            const uint64_t level)
      : level_(level), name_(name), describe_(describe) {}
  virtual ~Equipment() = default;
  const std::string& get_name() const { return name_; }
  uint64_t get_level() const { return level_; }
  const std::string& get_describe() const { return describe_; }
  double get_charging_value() const { return charging_value_; }
  EquipmentType get_equipment_type() const { return equipment_type_; }
  EquipmentGrade get_equipment_grade() const { return equipment_grade_; }
  uint64_t get_enhance_level() const { return enhance_level_; }
  const std::map<uint64_t, uint64_t>& get_enhance_record() const {
    return enhance_record_;
  }
  void set_level(uint64_t level) { level_ = level; }
  void set_name(const std::string& name) { name_ = name; }
  void set_describe(const std::string& describe) { describe_ = describe; }
  void set_charging_value(double value) { charging_value_ = value; }
  void set_equipment_type(const EquipmentType equipment_type) {
    equipment_type_ = equipment_type;
  }
  void set_equipment_grade(const EquipmentGrade equipment_grade) {
    equipment_grade_ = equipment_grade;
  }
  void set_enhance_level(const uint64_t enhance_level) {
    enhance_level_ = enhance_level;
  }
  void UpdateEnhanceRecord() { ++enhance_record_[enhance_level_]; }

 protected:
  uint64_t level_ = 0;
  double charging_value_ = 0.0;
  uint64_t enhance_level_ = 0;
  EquipmentType equipment_type_ = EquipmentType::kArms;
  EquipmentGrade equipment_grade_ = EquipmentGrade::kWhiteEquipment;
  std::string name_ = "";
  std::string describe_ = "";
  std::map<uint64_t, uint64_t> enhance_record_;
};

enum class ArmsType {
  kJuJian = 0,
  kDuanJian = 1,
  kTaiDao = 2,
  kGuangJian = 3,
};

class Arms : public Equipment {
 public:
  Arms(const std::string& name, const std::string& describe,
       const uint64_t level, const ArmsType arms_type)
      : Equipment(name, describe, level), arms_type_(arms_type) {
    equipment_type_ = EquipmentType::kArms;
  }
  ~Arms() = default;

 private:
  ArmsType arms_type_ = ArmsType::kJuJian;
};

double ComputeEnhanceSuccessRate(Equipment* equipment) {
  if (equipment == nullptr) {
    return 0.0;
  }
  const auto equipment_level = equipment->get_enhance_level();
  const auto equipment_grade = equipment->get_equipment_grade();
  const auto grade_ratio =
      1.0 - static_cast<double>(equipment_grade) /
                static_cast<double>(EquipmentGrade::kMaxEpicEquipment);
  // TODO(liying): compute enhance success rate based on level and equipment
  // grade.
  if (equipment_level < 10) {
    return 0.8 * grade_ratio;
  } else if (equipment_level < 12) {
    return 0.6 * grade_ratio;
  } else if (equipment_level < 14) {
    return 0.4 * grade_ratio;
  } else if (equipment_level < 16) {
    return 0.2 * grade_ratio;
  } else {
    return 0.1 * grade_ratio;
  }
  return 0.0;
}

uint64_t ComputeCarbonBalanceNum(Equipment* equipment) {
  if (equipment == nullptr) {
    return std::numeric_limits<uint64_t>::max();
  }
  const auto equipment_level = equipment->get_enhance_level();
  const uint64_t grade_num =
      static_cast<uint64_t>(equipment->get_equipment_grade()) + 6;
  // TODO(liying): compute enhance success rate based on level and equipment
  // grade.
  if (equipment_level < 10) {
    return 20 * grade_num;
  } else if (equipment_level < 12) {
    return 40 * grade_num;
  } else if (equipment_level < 14) {
    return 60 * grade_num;
  } else if (equipment_level < 16) {
    return 100 * grade_num;
  } else if (equipment_level < 18) {
    return 150 * grade_num;
  } else if (equipment_level < 20) {
    return 200 * grade_num;
  } else {
    return (200 + 50 * (equipment_level - 20)) * grade_num;
  }
}

class Enhancer {
 public:
  Enhancer() = default;
  ~Enhancer() = default;
  static bool Run(Equipment* equipment, bool is_vip) {
    if (equipment == nullptr) {
      return false;
    }
    auto enhanc_success_rate = ComputeEnhanceSuccessRate(equipment);
    if (is_vip) {
      enhanc_success_rate = 1.0;
    }
    std::cout << "Enhanc Success Rate: " << enhanc_success_rate << "\n";
    const auto num = std::rand() / static_cast<double>(RAND_MAX);
    std::cout << "Random Num: " << num << "\n";
    return num < enhanc_success_rate;
  }

 private:
};

void PrintEquipmentInfo(Equipment* equipment) {
  if (equipment == nullptr) {
    return;
  }
  std::cout << "----Equipment Info Start----\n";
  std::cout << "Equipment Name: " << equipment->get_name() << "\n";
  std::cout << "Equipment Level: " << equipment->get_level() << "\n";
  std::cout << "Equipment Describe: " << equipment->get_describe() << "\n";
  std::cout << "Equipment Charging Value: " << equipment->get_charging_value()
            << "\n";
  std::cout << "Equipment Type: "
            << static_cast<int>(equipment->get_equipment_type()) << "\n";
  std::cout << "Equipment Grade: "
            << static_cast<int>(equipment->get_equipment_grade()) << "\n";
  std::cout << "Equipment Enhance Level: " << equipment->get_enhance_level()
            << "\n";
  std::cout << "Enhance Record:\n";
  for (const auto& [level, count] : equipment->get_enhance_record()) {
    std::cout << "Level: " << level << "->" << level + 1 << ", Count: " << count
              << "\n";
  }
  std::cout << "----Equipment Info End----\n";
}

int main() {
  std::cout << "Hello World\n";
  std::cout << "__clang__: " << __clang__ << std::endl;
  std::cout << "__cplusplus: " << __cplusplus << std::endl;
  const std::vector<int> vec_nums(3, 1);
  std::cout << "vec nums:\n";
  for (int i = 0; i < vec_nums.size(); ++i) {
    std::cout << "i = " << i << ", num is:" << vec_nums[i] << "\n";
  }
  std::cout << "\n";
  const qeuler::Vec2d vec_a(1.0, 2.0), vec_b(3.0, 4.0);
  std::cout << "vec_a: " << vec_a.DebugString() << std::endl;
  std::cout << "vec_b: " << vec_b.DebugString() << std::endl;
  std::cout << "vec_a + vec_b: " << (vec_a + vec_b).DebugString() << std::endl;

  // Loane.
  {
    auto equal_interester = qeuler::quantification::EqualInterester<double>(
        308 * 10'000, 30, qeuler::quantification::InterestRateType::kYear,
        0.0315);
    const auto record = equal_interester.ComputeAmount();
    const auto& trades = record.get_trades();
    std::cout << "Equal Interester Loane Trades Start:\n";
    for (size_t i = 0; i < trades.size(); ++i) {
      const auto& trade = trades[i];
      std::cout << "Term: " << i + 1 << ", Trade: " << trade.DebugString()
                << "\n";
    }
    double care_interest = 0.0;
    constexpr uint64_t kYearNum = 30;
    for (size_t i = 0; i < kYearNum * 12; ++i) {
      care_interest += trades[i].get_interest();
    }
    std::cout << "Equal Interester Loane Care Interest: "
              << std::to_string(care_interest) << ", kYearNum: " << kYearNum
              << "\n";
    std::cout << "Equal Interester Loane Trades End:\n";
  }
  {
    auto equal_principaler = qeuler::quantification::EqualPrincipaler<double>(
        308 * 10'000, 30, qeuler::quantification::InterestRateType::kYear,
        0.0315);
    const auto record = equal_principaler.ComputeAmount();
    std::cout << "Equal Principaler Loane Trades Start:\n";
    const auto& trades = record.get_trades();
    for (size_t i = 0; i < trades.size(); ++i) {
      const auto& trade = trades[i];
      std::cout << "Term: " << i + 1 << ", Trade: " << trade.DebugString()
                << "\n";
    }
    double care_interest = 0.0;
    constexpr uint64_t kYearNum = 30;
    for (size_t i = 0; i < kYearNum * 12; ++i) {
      care_interest += trades[i].get_interest();
    }
    std::cout << "Equal Principaler Loane Care Interest: "
              << std::to_string(care_interest) << ", kYearNum: " << kYearNum
              << "\n";
    std::cout << "Equal Principaler Loane Trades End:\n";
  }
  return 0;

  uint64_t carbon_num = 1000;
  std::vector<std::shared_ptr<Equipment>> equipments;
  equipments.push_back(
      std::make_shared<Arms>("子午七星剑", "一柄神奇的剑，可以用来杀戮敌人。",
                             /*levle=*/50, ArmsType::kJuJian));
  //   equipments.push_back(
  //       std::make_shared<Arms>("玉女剑", "一柄玉女剑，可以用来杀戮敌人。",
  //                              /*levle=*/55, ArmsType::kDuanJian));
  //   equipments.push_back(std::make_shared<Arms>("太虚剑",
  //                                               "一柄太虚剑，可以用来杀戮敌人。",
  //                                               /*levle=*/60,
  //                                               ArmsType::kTaiDao));
  Enhancer enhancer;
  while (true) {
    for (auto& equipment : equipments) {
      std::cout << "************Current Enhace Start************\n";
      PrintEquipmentInfo(equipment.get());
      std::cout << "Carbon Num: " << carbon_num << "\n";
      std::cout << "Whether To Enhace?\n";
      char current_char = ' ';
      std::cin >> current_char;
      if (current_char == 'y' || current_char == 'Y') {
        const auto enhance_carbor_num =
            ComputeCarbonBalanceNum(equipment.get());
        std::cout << "Enhance Carbon Num: " << enhance_carbor_num << "\n";
        if (carbon_num < enhance_carbor_num) {
          std::cout << "Not Enough Carbon\n";
          std::cout << "Whether To Top Up?\n";
          std::cin >> current_char;
          if (current_char == 'y' || current_char == 'Y') {
            std::cout << "Top Up Carbon Num: ";
            uint64_t top_up_num = 0;
            std::cin >> top_up_num;
            std::cout << "Old Carbon Num: " << carbon_num << "\n";
            std::cout << "Top Up Carbon Num: " << top_up_num << "\n";
            carbon_num += top_up_num;
            std::cout << "New Carbon Num: " << carbon_num << "\n";
          }
          if (carbon_num < enhance_carbor_num) {
            std::cout << "Not Enough Carbon\n";
            continue;
          }
        }
        const auto is_success = Enhancer::Run(equipment.get(), false);
        equipment->UpdateEnhanceRecord();
        if (is_success) {
          std::cout << "Enhace Success\n";
          equipment->set_enhance_level(equipment->get_enhance_level() + 1);
        } else {
          std::cout << "Enhace Failed\n";
        }
        std::cout << "Enhace Status: " << std::boolalpha << is_success << "\n";
        carbon_num -= enhance_carbor_num;
        std::cout << "Carbon Num: " << carbon_num << "\n";
        PrintEquipmentInfo(equipment.get());
      }
    }
  }
  return 0;
}