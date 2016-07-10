.. _installation:

Installation
============


Currently Source code is available on github and can be compiled with any modern c++ compiler. although only g++ is tested and recommended.

..  Note::  The users of TC++ should know that thier compiler is older than me, and is supported neither by Borland nor by me. Please switch to g++.

Linux
******

1. Clone the repo using ``git clone https://github.com/arcxon/todx.git`` or Download the Source zip.

2. Use the command ``g++ -o main.cpp todx.out`` to compile the executable.

3. Now the ``todx.out`` file can be used anywhere. Just place it in your desired folder and execute in the command-line : ``./todx.out`` to enjoy the app.

..  Note:: You should also copy ``help.txt`` so that :ref:`help` command works.

Windows
****************

1. Clone the repo using ``git clone https://github.com/arcxon/todx.git`` or Download the Source zip.

2. Ensure ``g++`` is installed using the bellow command in the pallete :

    g++ -v

If it prints some strange stuff that relates to version number etc then all is well and good. If not, and it shows command not found, then download and install `MinGW`_.

3. Now, We compile the code :

    g++ main.cpp fabric.cpp -o todx.exe

4. The binary ``todx.exe`` is ready to be executed. Move it to your desired folder to store the todo's. Don't forget to move the ``help.txt``, since the program requires it. Then simply execute ``todx.exe`` to enjoy it.

Binary Executables
******************

There is a plan to offer stable binary builds for both Linux and Windows. Please Remain Calm and use compilation till then.


.. _MinGW: http://mingw.org/
