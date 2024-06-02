#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#include <vector>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;

template <typename T>
vector<T>
read_vector_from_json_str()
{
    string json_str;
    cin >> json_str;
    auto json_array = nlohmann::json::parse(json_str);
    vector<T> vec;
    for (int i = 0; i < json_array.size(); i++)
    {
        vec.push_back(json_array[i]);
    }
    return vec;
}

string read_quoted_string()
{
    string str;
    cin >> str;

    if (str[0] == '"')
        str = str.substr(1, str.length() - 1);
    if (str[str.length() - 1] == '"')
        str = str.substr(0, str.length() - 1);

    return str;
}

#endif