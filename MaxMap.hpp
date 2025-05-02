#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

float consultMax(const std::string& search_term, const std::map<std::string, std::vector<float>>& data) {
   
    try{
        std::vector<float> search_vector = data.at(search_term);

        float max = 0;
        for(auto it = search_vector.begin(); it != search_vector.end(); it++){
            if (*it > max){
                max = *it;
            }
        }   
        return max;
    }
    catch (std::exception& e){
        return -1;
    }
}

std::map<std::string, float> returnMaxMap(const std::map<std::string, std::vector<float>>& in_map) {
    std::map<std::string, float> return_map;

    for(auto it = in_map.begin(); it != in_map.end(); it++){
        float max = it->second.front();
        for(auto vec_it = it->second.begin(); vec_it != it->second.end(); vec_it++){
            if (*vec_it > max){
                max = *vec_it;
            }
        }
        return_map[it->first] = max;
    }
    
    return return_map;
}