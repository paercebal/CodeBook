#include <CodeBook/LibraryNet/module.hpp>

#include <CodeBook/Library/CodeBook.Library.hpp>

#include <msclr/marshal_cppstd.h>

namespace CodeBook {
namespace LibraryNet {

public
ref class Module
{
public:
   System::String ^ GetVersion() {
      std::string libraryVersion = Library::GetVersion();
      System::String ^ libraryVersionNet = gcnew System::String(libraryVersion.c_str());
      return "CodeBook.LibraryNet (v0.0.1) [based on: " + libraryVersionNet + "]";
   };

public:
   System::String ^ Testing(System::String ^ symbol, System::String ^ source) {

      std::string symbolNative = msclr::interop::marshal_as<std::string>(symbol);
      std::string sourceNative = msclr::interop::marshal_as<std::string>(source);

      std::string outputNative = Library::Testing(symbolNative, sourceNative);

      System::String ^ output = gcnew System::String(outputNative.c_str());
      return output;
   };
};


}   // namespace LibraryNet
}   // namespace CodeBook
