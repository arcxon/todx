..  _install-from-source:

========================
Installation from Source
========================

This step is critical for helping development in TodX. It will allow you to get the source-code, publish changes, and ask them to be included.

Getting Source
****************

If you have already thought of contributing by editing the code, It is much better to fork the `Repo <https://github.com/arcxon/todx>`_ and then clone it. ::

    $ git clone https://github.com/{user name}/todx

where ``{user name}`` should be your user name.

If you want the repo for just seeing the code. ::

    $ git clone https://github.com/arcxon/todx


Compiling and running
*********************

You should have ``make`` and ``g++`` installed, although I don't think the compilation is dependent on platform since the code uses mostly standard c++. To compile the source use ``$ make``. To run it use ``make run``.

..  Note:: Makefile already has a command for ``make clean`` so run it to remove the object files.

After successfull installation and running you can try out the program.

Building the Docs
*****************

After installation, you might want to build the docs, for this you need to install the following:

Sphinx
----------------
Install the Documentation generator.::

    $ pip install sphinx sphinx-autobuild

Sphinx RTD theme
----------------
Install the cool theme for Documentation. ::

    $ pip install sphinx_rtd_theme

Now we can build the docs. Switch to the folder/Directory ``docs`` in the repo and execute ::

    $ make html

This will build the docs. You can visit the index file at ``docs\_build\html\index.html``, open it in your browser and enjoy the docs.
