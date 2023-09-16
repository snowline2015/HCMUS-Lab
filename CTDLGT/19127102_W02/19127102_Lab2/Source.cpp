#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void searchDictionary(std::vector<std::string>& vec) {
    std::ifstream file("English-Vietnamese Dictionary.txt");
    std::string temp;
    for (std::vector<std::string>::iterator p = vec.begin(); p != vec.end() - 1; p++) {
        if (*(p + 1) == "//") {
            *p = (*p).append(" ").append(*(p + 2));
            vec.erase(p + 1, p + 3);
        }
        while (!file.eof()) {
            std::getline(file, temp);
            if (temp.std::string::substr(0, (*p).length()).compare(*p) == 0) {
                *p = temp;//.std::string::substr((*p).length() + 1);
                file.seekg(0, std::ios::beg);
                break;
            }
        }
    }
}

void output(std::vector<std::string>& vec) {
    std::ofstream file(vec[vec.size() - 1]);
    for (std::vector<std::string>::iterator p = vec.begin(); p != vec.end() - 1; p++) 
        file << *p << "\n";
    file.close();
    vec.clear();
}

int main(int argc, const char* argv[]) {
    std::cout << "If you want to seach for the definition of a word which has 2 words, try to use \"//\"\n"
        << "E.g: 19127102_Lab2.exe space // satellite out.txt" << std::endl;
    std::string str;
    std::vector<std::string> ok;
    for (int i = 1; i < argc; i++) {
        str = argv[i];
        ok.push_back(str);
    }
    searchDictionary(ok);
    output(ok);
    return 0;
}