#include <CodeBook/LibraryNet/module.hpp>

#include <CodeBook/Library/module.hpp>

namespace CodeBook {
namespace LibraryNet {

public
ref class Module
{
   System::String ^ GetVersion() {
      return "CodeBook.LibraryNet (v0.0.1)";
   }
};

//CODE_BOOK_x_LIBRARY_NET_x_API std::string GetVersion()
//{
//   return "CodeBook.LibraryNet (v0.0.1)";
//}

}   // namespace LibraryNet
}   // namespace CodeBook
