#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

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
