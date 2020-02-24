#include <CodeBook/Console/main.hpp>

#include <CodeBook/Library/module.hpp>

#include <iostream>

int main(int argc, char * argv[])
{
   std::cout << "CodeBook.Console\n";
   std::cout << "=======================\n";
   std::cout << "\n";
   std::cout << " - CodeBook.Library: " << CodeBook::Library::GetVersion() << "\n";

   //return CodeBook::Console::pause(0) ;
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
