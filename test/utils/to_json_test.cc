#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <limits>

#include "rapidjson_utils/rapidjson_utils.h"

#include "../structs/a.h"
#include "../structs/b.h"
#include "../structs/c.h"
#include "../structs/d.h"

namespace rapidjson::utils {

class ToJsonTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(ToJsonTest, to_json_a_and_c_test) {
    {
        auto tc = TestCase_A_0();
        auto a = tc.Instance();

        auto json_string_res = ToJson(&a);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&a);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_B_0();
        auto b = tc.Instance();

        auto json_string_res = ToJson(&b);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&b);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }
}

}  // namespace rapidjson::utils
