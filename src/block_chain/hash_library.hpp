#include <string>
#include <vector>

std::vector< std::string > sha256( std::string );
std::string change_to_string( std::vector<std::string> data);
std::vector< unsigned int > change_hash_num( std::vector<std::string> hash );
std::string next_hash( std::vector<unsigned int> &hash_num );
void add_num( std::vector<unsigned int> &base_num, unsigned int num );
unsigned int zero_count( std::string hash );
