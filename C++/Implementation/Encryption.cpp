#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

std::string remove_spaces(std::string s) 
{
    std::string result;
    for(char& c : s) {
        if(c != ' ')
            result.push_back(c);
    }
    return result;
}

std::string trim_end(std::string& s) 
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [&](auto c) {
        return !std::isspace(c);
    }).base(), s.end());
    return s;
}

auto get_bounds(std::string& s) -> std::pair<int, int>
{
    s = remove_spaces(s);
    auto root = sqrt(s.size());
    int bot = (int) floor(root);
    int top = (int) ceil(root);
    //std::cout << bot << " " << top << " " << s.size() << '\n';

    for(int i = bot; i <= top; ++i) {
        for(int j = i; j <= top; ++j) {
            if(i * j >= s.size())
                return std::make_pair(i, j);
        }
    }

    throw std::exception();
}

void encryption(std::string& s)
{
    auto bounds = get_bounds(s);
    int row = bounds.first;
    int col = bounds.second;

    std::string result;
    result.reserve(s.size() + (s.size() / row));
    for(int i = 0; i < col; ++i) {
        for(int j = 0; j < row; ++j) {
            size_t index = i + (j * col);
            if(!s[index])
                break;
            result.push_back(s[index]);
        }
        result.push_back(' ');
    }
    std::cout << trim_end(result) << '\n';
}

using namespace std;
int main() 
{
    string s;
    getline(cin, s);

    encryption(s);
}