Mokka
=====

Open-source and cross-platform software to easily analyze biomechanical data

Overview
--------

This branch is only a proof of concept to show that we can have a Python console within an application based on Qt5 and PythonQt and access to some C++ methods/constants from the Python console. This branch could be also the basis for *Mokka2*: A reimplementation of (Mokka)[http://b-tk.googlecode.com/svn/web/mokka/index.html] based on Qt5, including a Python console, a plugin/extension system, the same features than before but refactorized for a better modularity, and... Who knows? 

Prerequisites
-------------

* CMake 2.8.9 or above
* Qt 5.1 or above
* (patched-5)[https://github.com/Alzathar/PythonQt] version of PythonQt

Build instructions
------------------

```
git clone git://github.com/Biomechanical-ToolKit/Mokka.git ./Mokka.git
cd Mokka.git
mkdir build
cd build
cmake -DPYTHONQT_INCLUDE_DIR:PATH=/path/to/PythonQt/src/folder -DPYTHONQT_GENERATED_CPP_DIR:PATH=/path/to/PythonQt/generated_cpp_50/folder -DPYTHONQT_LIBRARIES:FILEPATH=/path/to/PythonQt/library ..
make
```

Contributing
------------

Want to contribute to the project? It can be to improve the documentation, fix a bug, create a new feature, do some code review, and much more!

1. [Fork][fk] Mokka
2. Create a topic branch - `git checkout -b my_branch`
3. Do all your modifications. Commit, commit and commit ((smaller is better)[http://www.databasically.com/2011/03/14/git-commit-early-commit-often/]).
4. Push to your branch - `git push origin my_branch`
5. Create a [Pull Request][pr]
6. That's it!

Meta
----

* Code: `git clone git://github.com/Biomechanical-ToolKit/Mokka.git`
* Bugs: <https://github.com/Biomechanical-ToolKit/Mokka/issues>
* Mailing list: (BTK-Users)[https://groups.google.com/d/forum/btk-users]
* Twitter: (@btkwww)[https://twitter.com/btkwww]

License
-------

```
The Biomechanical ToolKit
Copyright (c) 2009-2013, Arnaud Barré
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

    * Redistributions of source code must retain the above
      copyright notice, this list of conditions and the following
      disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials
      provided with the distribution.
    * Neither the name(s) of the copyright holders nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written
      permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
```

[fk]: http://help.github.com/forking/
[pr]: https://help.github.com/articles/using-pull-requests
