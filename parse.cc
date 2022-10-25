//#include <../parse.h>
#include <array>
#include <optional>
#include <string> 
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <string_view>
#include <variant>
#include <vector>
#include <ranges>
using colType = std::variant<int64_t, std::string, double>; 

inline namespace parse {

    using csvRow = std::vector<colType>;

    class csvObject {
        public: 
            /// @brief initilizes a CSV object which can be operated on
            /// @param fileName the path to the csv file 
            explicit csvObject(std::string fileName) {
                

            }
        private:

        std::unordered_map<std::string, csvRow> tableLookup; 


    };

    /// @brief Generates CSV Table
    /// @param fileName the path to the csv file 
    /// @param rowTypes the type of each row provided by user
    [[nodiscard]] inline auto createCsvTable(std::vector<std::string> & rowTypes, std::string fileName) -> bool {
        //parse names of tables
        std::istringstream buffer(fileName);
        std::string tableNames; 
        getline(buffer, tableNames, '\n');
        std::string x = buffer.str();
        auto rowNames = std::string_view{x} | std::ranges::views::split(',');
        // for (const auto & v : auto{rowNames}) {
        //     std::cout << v << "\n";
        // }
        return true;
        // while(getline(buffer, tableNames, ',')) {

        // }
        //parse data for tables
    }
    using t = std::vector<std::string>;  

    [[nodiscard]] inline std::optional<t> parseRowTypes(int argc, char ** argv) {
        std::vector<std::string> rowTypes; 
        static constexpr std::array<std::string_view, 4> supportedRowTypes{"int", "double", "string", "char"};
        int rowNum = 0;
        while(rowNum != argc - 1) {
            auto contains = [&]() -> bool {for (auto & v : supportedRowTypes) {if(v == argv[rowNum]) return true;} return false;} ();
            if(!contains) return {};
            rowTypes.push_back(argv[rowNum]); 
        }
        return rowTypes;
    }


}

int main(int argc, char ** argv) {
    // if (auto rowTypes = parseRowTypes(argc, argv); rowTypes.has_value()) {
        std::vector<std::string> debug;
    parse::createCsvTable(debug, "nycflightsjan13.csv");
    // } else {
    //     printf("Invalid row type provided\n");
    //     return 1;
    // }
      auto strings = std::string_view{"Hello C++ 20"} | std::views::split(' ');
      for (const auto &ref : strings) {
    // C++ 20
            //std::cout << std::string{ref} << "\n";
            //std::cout << '\n' << std::string_view{ref.begin(), ref.end()};
      }
    // return 0}
