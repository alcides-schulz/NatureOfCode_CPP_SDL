#include "GenerateExampleInitialCode.h"
#include <iostream>
#include <fstream>
#include <string>

bool GenerateExampleInitialCode::Setup()
{
    ClearScreen();

    string chapter = "04";
    string example = "06";
    string description = "A System of Systems";

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
    include_output_file << "#include \"../Common/SDL_Framework.h\"" << endl << endl;
    include_output_file << "namespace nature_of_code_chapter_" << chapter << "_example_" << example << endl;
    include_output_file << "{" << endl;
    include_output_file << "    class Sketch : public SDL_Framework" << endl;
    include_output_file << "    {" << endl;
    include_output_file << "    public:" << endl;
    include_output_file << "        Example_" << example << "() : SDL_Framework(\"Example " << chapter << "." << example << ": " << description << "\", -1, -1, 640, 240, 0) {};" << endl;
    include_output_file << "        bool Setup(void) override;" << endl;
    include_output_file << "        bool Draw(void) override;" << endl;
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
    class_output_file << "        ClearScreen();" << endl << endl;
    class_output_file << "        return true;" << endl;
    class_output_file << "    }" << endl << endl;
    class_output_file << "}" << endl << endl;
    class_output_file << "// END" << endl;

    class_output_file.close();
    cout << "generated class: " << class_filename << endl;

    return true;
}