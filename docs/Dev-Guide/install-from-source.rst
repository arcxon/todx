..  _install-from-source:
========================
Installation from Source
========================

This step is critical for helping development in TodX. It will allow you to get the source-code, publish changes, and ask them to be included.

Getting Source
****************

1. If you have already thought of contributing by editing the code, It is much better to fork the `Repo <https://github.com/arcxon/todx>`_ and then clone it.

`` $ git clone https://github.com/{user name}/todx``

where {user name} should be your user name.

If you want the repo for just seeing the code.

`` $ git clone https://github.com/arcxon/todx ``

2. You should have ``make`` and ``g++`` installed, although I don't think the compilation is dependent on platform since the code uses mostly standard c++. To compile the source use `` $ make``. To run it use ``make run``.

..  Note:: Makefile already has a command for ``make clean`` so run it to remove the object files.

After successfull installation and running you can try out the program.
