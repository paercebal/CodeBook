#include <CodeBook/LibraryNet/module.hpp>

#include <CodeBook/Library/module.hpp>

namespace CodeBook {
namespace LibraryNet {

public
ref class Module
{
public:
   System::String ^ GetVersion() {
      std::string libraryVersion = Library::GetVersion();
      System::String ^ libraryVersionNet = gcnew System::String(libraryVersion.c_str());;
      return "CodeBook.LibraryNet (v0.0.1) [based on: " + libraryVersionNet + "]";
   }
};

//CODE_BOOK_x_LIBRARY_NET_x_API std::string GetVersion()
//{
//   return "CodeBook.LibraryNet (v0.0.1)";
//}

}   // namespace LibraryNet
}   // namespace CodeBook
