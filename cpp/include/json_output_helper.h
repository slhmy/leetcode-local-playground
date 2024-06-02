#ifndef OUTPUT_HELPER_H
#define OUTPUT_HELPER_H

#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;

template <typename T>
void print_vector_as_json(const vector<T> &vec)
{
    auto output_json = nlohmann::json::array();
    for (int i = 0; i < vec.size(); i++)
    {
        output_json.push_back(vec[i]);
    }
    cout << output_json.dump() << endl;
}

void print_quoted_string(const string &str)
{
    cout << "\"" << str << "\"" << endl;
}

#endif