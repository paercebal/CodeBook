# How to prepare the project for development/compilation

I will describe below the step-by-step installation of the CodeBook project for
Windows. I will write similar installation for other OSes the moment I actually
try it elsewhere.

Important: I wrote that from memory, so if you have any problem, do not hesitate
to raise an issue for me to correct the process. Thanks!

## Install Kizuko Project on Windows

I expect you have a 64-bit Windows. If you don't, well, you'll have to bring the
32-bit packages of Kizuko dependencies, then add the 32-bit (i.e. Win32)
configuration to the VS project.

1. Install Visual Studio 2019
1. Install Git for Windows
1. Install VCPKG
1. Install the needed VCPKG packages
1. Install LLVM
1. Install CodeBook project from Github
1. Enjoy

### 1. Install Visual Studio 2019

You can freely download the installer for VS 2017 Community Edition here:
https://www.visualstudio.com/downloads/

### 2. Install Git for Windows

You can freely download the installer for Git for Windows here:
https://git-scm.com/download/win

### 3. Install VCPKG

You can find instruction to install VCPKG on their Github page, here:
https://github.com/Microsoft/vcpkg

I strongly suggest you to use user-wide integration:

```
.\vcpkg integrate install
```

Without that integration, you'll have to rely on an environment variable that
you will have to set to the directory where VCPKG is defined:

- name: `PAERCEBAL_VCPKG_DIR`
- value: `<PARENT DIRECTORY OF VCPKG>\vcpkg`

If you want to NOT rely on an environment variable, you only need to add the
target file of VCPKG in the project. The target file is here: `<PARENT DIRECTORY OF VCPKG>\vcpkg\scripts\buildsystems\msbuild\vcpkg.targets`

### 4. Install the need VCPKG packages

The following instructions will install all the packages needed by Kizuko:

```
.\vcpkg install gtest:x64-windows
```

These packages will bring their dependencies with them.

### 5. Install LLVM

### 6. Install CodeBook project from Github

Open a console, and go in a directory where the CodeBook directory (and project)
will be brought from Github.

If you have a Github account, then I suggest branching from CodeBook. If you don't,
or if you only want to compile the project, you can directly clone from my master
branch:

```
git clone https://github.com/paercebal/CodeBook.git
```

### 6. Enjoy

Kizuko is organized into the following binaries/modules:

- CodeBook.Library.dll: The library
- CodeBook.Console.exe: The console front-end
- CodeBook.LibraryTesting.exe: The GTest console

Open `<CODEBOOK DIRECTORY>\_vs2019\CodeBook.sln` on Visual Studio 2019, choose a
configuration between:

- Release: The delivery configuration
- ReleaseDev: The same as the the delivery configuratio, but without optimizations
- Debug: The debug configuration

I usually work on ReleaseDev, reverting on Debug when I suspect some memory
corruption to occur (which is quite rare with correctly used modern C++).

Once you chose your configuration, launch a compilation.

You can then go in the `<CODEBOOK DIRECTORY>\__bin directory to find the
executable with all its dependencies and resources installed.

Enjoy!

:-)
