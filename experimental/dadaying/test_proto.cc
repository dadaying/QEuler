#include <string>
#include <iostream>

#include "proto/test_proto.pb.h"
#include "../../third_party/protobuf/include/descriptor.h"

namespace experiment::dadaying {
int main () {
    TestClassProto class_proto;
    const auto add_person = [&](const std::string& name, const double age, const bool is_boy) {
        auto& person = *class_proto.add_persons();
        person.set_name(name);
        person.set_age(age);
        person.set_is_boy(is_boy);
    };
    add_person("li ming", 10, true);
    add_person("zhang hua", 11, false);
    add_person("wang zi", 10, true);
    class_proto.set_name("4 年 1 班");
    std::cout << class_proto.DebugString().c_str();
    return 0;
}
}  // namespace experiment::dadaying