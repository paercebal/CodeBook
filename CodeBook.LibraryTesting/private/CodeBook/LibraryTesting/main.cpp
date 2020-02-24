#include <CodeBook/LibraryTesting/main.hpp>

#include <CodeBook/Library/CodeBook.Library.hpp>

#include <iostream>

#include <gtest/gtest.h>

int main(int argc, char * argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

TEST(CodeBook_LibraryTesting, GetVersion)
{
   EXPECT_EQ("CodeBook.Library (v0.0.1)", CodeBook::Library::GetVersion());
}

TEST(CodeBook_LibraryTesting, Simple)
{
   std::string symbol = "n::m::C";
   std::string source = "namespace n { namespace m { class C {}; } }";
   std::string output = CodeBook::Library::Testing(symbol, source);

   EXPECT_EQ("Found declaration [n::m::C] at 1:29\n", output);
}

namespace CodeBook {
namespace LibraryTesting {

}   // namespace LibraryTesting
}   // namespace CodeBook
