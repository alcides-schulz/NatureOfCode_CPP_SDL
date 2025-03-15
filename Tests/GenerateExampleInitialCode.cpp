#include "GenerateExampleInitialCode.h"
#include <iostream>
#include <fstream>
#include <string>

bool GenerateExampleInitialCode::UserInit()
{
    ClearScreen();

    string chapter = "03";
    string example = "3_9";
    string title = string(example);
    title.replace(1, 1, ".");

    auto include_filename = "Chapter" + chapter + "/Example_" + example + ".h";
    auto class_filename = "Chapter" + chapter + "/Example_" + example + ".cpp";

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

    include_output_file << "#ifndef EXAMPLE_" << example << "_H" << endl;
    include_output_file << "#define EXAMPLE_" << example << "_H" << endl << endl;
    include_output_file << "#include \"../Common/SDL_Framework.h\"" << endl << endl;
    include_output_file << "class Example_" << example << " : public SDL_Framework" << endl;
    include_output_file << "{" << endl;
    include_output_file << "public:" << endl;
    include_output_file << "    Example_" << example << "() : SDL_Framework(\"Example " << title << ": DESC\", -1, -1, 640, 240, 0) {};" << endl;
    include_output_file << "    bool UserInit(void) override;" << endl;
    include_output_file << "    bool UserRender(int elapsed_time) override;" << endl;
    include_output_file << "private:" << endl;
    include_output_file << "};" << endl << endl;
    include_output_file << "#endif" << endl;

    include_output_file.close();
    cout << "generated include: " << include_filename << endl;

    ofstream class_output_file(class_filename);
    if (!class_output_file.is_open()) {
        cout << "error creating: " << class_filename << endl;
        return true;
    }
    class_output_file << "#include \"Example_" << example << ".h\"" << endl << endl;
    class_output_file << "bool Example_" << example << "::UserInit(void)" << endl;
    class_output_file << "{" << endl;
    class_output_file << "    return true;" << endl;
    class_output_file << "}" << endl << endl;
    class_output_file << "bool Example_" << example << "::UserRender(int elapsed_time)" << endl;
    class_output_file << "{" << endl;
    class_output_file << "    ClearScreen();" << endl << endl;
    class_output_file << "    return true;" << endl;
    class_output_file << "}" << endl << endl;
    class_output_file << "// END" << endl;

    class_output_file.close();
    cout << "generated class: " << class_filename << endl;

    return true;
}