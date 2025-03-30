#include "GenerateExampleInitialCode.h"
#include <iostream>
#include <fstream>
#include <string>

bool GenerateExampleInitialCode::Setup()
{
    Background(255);

    string chapter = "05";
    string example = "11";
    string description = "Flocking";

    auto include_filename = "Chapter" + chapter + "/Example_" + chapter + "_" + example + "_Sketch.h";
    auto class_filename = "Chapter" + chapter + "/Example_" + chapter + "_" + example + "_Sketch.cpp";

    ifstream include_test_file(include_filename);
    if (include_test_file.is_open()) {
        include_test_file.close();
        cout << "include already exists: " << include_filename << endl;
        return true;
    }
    ifstream class_test_file(class_filename);
    if (class_test_file.is_open()) {
        class_test_file.close();
        cout << "class already exists: " << class_filename << endl;
        return true;
    }

    ofstream include_output_file(include_filename);
    if (!include_output_file.is_open()) {
        cout << "error creating: " << include_filename << endl;
        return true;
    }

    include_output_file << "#ifndef EXAMPLE_" << chapter << "_" << example << "_SKETCH_H" << endl;
    include_output_file << "#define EXAMPLE_" << chapter << "_" << example << "_SKETCH_H" << endl << endl;
    include_output_file << "#include \"../Common/P5SDL.h\"" << endl << endl;
    include_output_file << "namespace nature_of_code_chapter_" << chapter << "_example_" << example << endl;
    include_output_file << "{" << endl;
    include_output_file << "    class Sketch : public P5SDL" << endl;
    include_output_file << "    {" << endl;
    include_output_file << "    public:" << endl;
    include_output_file << "        Sketch() : P5SDL(\"Example " << stoi(chapter) << "." << stoi(example) << ": " << description << "\", -1, -1, 640, 240, 0) {};" << endl;
    include_output_file << "        bool Setup(void) override;" << endl;
    include_output_file << "        bool Draw(void) override;" << endl;
    include_output_file << "        void Cleanup(void) override;" << endl;
    include_output_file << "    private:" << endl;
    include_output_file << "    };" << endl;
    include_output_file << "}" << endl << endl;
    include_output_file << "#endif" << endl;

    include_output_file.close();
    cout << "generated include: " << include_filename << endl;

    ofstream class_output_file(class_filename);
    if (!class_output_file.is_open()) {
        cout << "error creating: " << class_filename << endl;
        return true;
    }
    class_output_file << "#include \"Example_" << chapter << "_" << example << "_Sketch.h\"" << endl << endl;
    class_output_file << "namespace nature_of_code_chapter_" << chapter << "_example_" << example << endl;
    class_output_file << "{" << endl;
    class_output_file << "    bool Sketch::Setup(void)" << endl;
    class_output_file << "    {" << endl;
    class_output_file << "        return true;" << endl;
    class_output_file << "    }" << endl << endl;
    class_output_file << "    bool Sketch::Draw(void)" << endl;
    class_output_file << "    {" << endl;
    class_output_file << "        Background(255);" << endl << endl;
    class_output_file << "        return true;" << endl;
    class_output_file << "    }" << endl;
    class_output_file << "}" << endl << endl;
    class_output_file << "// END" << endl;

    class_output_file.close();
    cout << "generated class: " << class_filename << endl;

    return true;
}