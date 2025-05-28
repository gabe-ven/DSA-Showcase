# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-src")
  file(MAKE_DIRECTORY "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-src")
endif()
file(MAKE_DIRECTORY
  "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-build"
  "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-subbuild/malena-populate-prefix"
  "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-subbuild/malena-populate-prefix/tmp"
  "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-subbuild/malena-populate-prefix/src/malena-populate-stamp"
  "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-subbuild/malena-populate-prefix/src"
  "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-subbuild/malena-populate-prefix/src/malena-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-subbuild/malena-populate-prefix/src/malena-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/gabrielvenezia/CLionProjects/DSAShowcase/cmake-build-debug/_deps/malena-subbuild/malena-populate-prefix/src/malena-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
