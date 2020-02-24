#include <CodeBook/Console/main.hpp>

#include <CodeBook/Library/CodeBook.Library.hpp>

#include <iostream>

int main(int argc, char * argv[])
{
   std::cout << "CodeBook.Console\n";
   std::cout << "=======================\n";
   std::cout << "\n";
   std::cout << " - CodeBook.Library: " << CodeBook::Library::GetVersion() << "\n\n";

   if (argc >= 3)
   {
      // CodeBook.Console.exe "n::m::C" "namespace n { namespace m { class C {}; } }"
      std::string symbol = argv[1];   // "n::m::C"
      std::string source = argv[2];   // "namespace n { namespace m { class C {}; } }"
      std::string output = CodeBook::Library::Testing(symbol, source);
      std::cout << "For\n - symbol [" << symbol << "]\n";
      std::cout << " - source [" << source << "]\n";
      std::cout << "... then output is [" << output << "]\n";
   }
   else
   {
      std::cout << "No valid input\n\nSuggestion: Try the following command in the console:\n\n";
      std::cout << "CodeBook.Console.exe \"n::m::C\" \"namespace n { namespace m { class C {}; } }\"\n";
   }
   std::cout << "\nOk\n";
}

namespace CodeBook {
namespace Console {

int pause(int p_value)
{
   std::cout << "\nPress RETURN to continue..." << std::endl;
   std::cin.ignore();
   return p_value;
}

}   // namespace Console
}   // namespace CodeBook
