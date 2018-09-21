#include <gtest/gtest.h>
#include "json.hpp"
#include <nlohmann/json.hpp>

namespace {

const char * const json_data = R"(
{
    "lastname" : "Ivanov",
    "firstname" : "Ivan",
    "age" : 25,
    "islegal" : false,
    "marks" : [
    	4,5,5,5,2,3
    ],
    "address" : {
    	"city" : "Moscow",
        "street" : "Vozdvijenka"
    }
})";

TEST(Json, LoadFromString) {
  Json object = Json::parse(json_data);
  EXPECT_EQ(std::any_cast<std::string>(object["lastname"]), "Ivanov");
  EXPECT_EQ(std::any_cast<bool>(object["islegal"]), false);
  EXPECT_EQ(std::any_cast<double>(object["age"]), 25);

  auto marks = std::any_cast<Json>(object["marks"]);
  EXPECT_EQ(std::any_cast<double>(marks[0]), 4);
  EXPECT_EQ(std::any_cast<double>(marks[1]), 5);

  auto address = std::any_cast<Json>(object["address"]);
  EXPECT_EQ(std::any_cast<std::string>(address["city"]), "Moscow");
  EXPECT_EQ(std::any_cast<std::string>(address["street"]), "Vozdvijenka");
}

}

using json = nlohmann::json;

int main() {
	json json_data = R"(
[
    ["Si-9.15", "RTS-9.15", "GAZP-9.15"],
    [100024, 100027, 100050],
    ["Futures contract for USD/RUB", "Futures contract for index RTS", "Futures contract for Gazprom shares"]
])"_json;
	json j_0 = json_data[0];
	json j_1 = json_data[1];
	json j_2 = json_data[2];
	
	json json_data_converte;
	
	for (unsigned int i = 0; i < 3; i++){
		json jj;
		jj["ticker"] = j_0[i];
		jj["id"] = j_1[i];
		jj["description"] = j_2[i];
		json_data_converte.push_back(jj);
	}
	
	std::cout << json_data_converte << std::endl;
}
