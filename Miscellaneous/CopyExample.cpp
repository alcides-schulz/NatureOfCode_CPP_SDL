#include "CopyExample.h"

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

bool CopyExample::Setup()
{
    Background(255);

    auto from_number = string(FROM_NUMBER);
    auto to_number = string(TO_NUMBER);
    auto from_namespace = "nature_of_code_chapter_" + string(CHAPTER) + "_example_" + string(FROM_EXAMPLE);
    auto to_namespace = "nature_of_code_chapter_" + string(CHAPTER) + "_example_" + string(TO_EXAMPLE);

    for (const auto& entry : fs::directory_iterator(string(COPY_FOLDER))) {
        auto from_filename = entry.path().string();
        if (from_filename.find(FROM_NUMBER, 0) == string::npos)
            continue;
        cout << "Copying from: " << from_filename << endl;
        auto to_filename = string(from_filename);
        to_filename.replace(from_filename.find(from_number, 0), from_number.length(), to_number);
        if (fs::exists(to_filename)) {
            cout << "  **** file already exists, will not copy: " << to_filename << endl;
            continue;
        }
        cout << "      Copying to: " << to_filename << endl;

        ifstream input_stream(from_filename);
        if (!input_stream.is_open()) {
            cout << "error opening: " << from_filename << endl;
            return false;
        }
        ofstream output_stream(to_filename);
        if (!output_stream.is_open()) {
            cout << "error creating: " << to_filename << endl;
            return false;
        }
        string line;
        while (getline(input_stream, line)) {
            auto from_number_pos = line.find(from_number, 0);
            if (from_number_pos != string::npos)
                line.replace(from_number_pos, from_number.length(), to_number);
            auto from_namespace_pos = line.find(from_namespace, 0);
            if (from_namespace_pos != string::npos)
                line.replace(from_namespace_pos, from_namespace.length(), to_namespace);
            output_stream << line << endl;
        }
        input_stream.close();
        output_stream.close();
    }

    return true;
}
