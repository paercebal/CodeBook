# CodeBook

Code Symbol Dependencies Discoverer

Important: This project is under construction, including its organization/layout. Also, MIT License.


## Third parties

To handle the 3rd parties, I use VCPKG, which is a no-nonsense package manager that does exactly what I want, without hindering me. If you are developping on a Windows machine, give it a try. You'll like it.

It is important to remove user-wide integration of VCPKG, as it may make the C++/CLI DLL compilation fail for a spurious error (conflict with Google Benchmark, in my case, for some reason, despite the DLL being at the time mostly empty). Execute the following command:

```
.\vcpkg integrate remove
```

... and install instead dependencies to VCPKG in another way.

Anyway, this project depends on the following third parties:

1. gtest

(some are the names of the DLLs VCPKG brought for me in my bin directory. The list fluctuate as I try alternatives)

## Configurations

This is a x64-only project. Sorry for the 32-bit users out there (the code should remain 32-friendly, though).

There are three configurations: "Release" and "Debug" are mostly the normal Visual Studion (not CMake) configurations. "ReleaseDev" is a "Release" configuration where optimizations were disabled, for debugging purposes.

## Platform

This is a Windows only program for the following reasons:

1. I use VCPKG as my package manager (I'm still learning, though)
1. I actually like Visual Studio/MSBuild project file format
1. CMake is crap (see below)

... But the code is cross platform, so it should work everywhere. If you want to try it on your platform, do not hesitate to create your own CMake files, and contribute. I will update them as needed (but I'll never use them).

## Why is CMake crap?

Despite its very interesting cross-platform nature, I don't use CMake for my projects.

There's a lot of reasons for that, but the main one for me is that it generates ridiculously bloated and wrong Visual Studio project files (probably coming from Visual C++ 6.0, as in, 1998). For example, the "Release" configuration doesn't produce debug symbols, which is absurdingly stupid.

## Your project is a mess!

Ok, I don't really care about the exact 3rd parties dependencies, because VCPKG solves them for me.

Currently, I'm trying to solve a specific problem, which is discovering code symbol dependencies. Which means my possible usage of this my priority.
