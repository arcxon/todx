==========
User Guide
==========

    This guide helps to provide a extended documentation for using the app.
    For development please check [development](development.md)

Data Concepts
-------------

..  toctree::
    :maxdepth: 2

    list

Entry Modes
-----------

=======  ===========================  ==========================
Command  Usual Meaning                Answer Format
=======  ===========================  ==========================
``*>``   Basic commands               commands like ``open`` etc
``+>``   Entry or Input for Content   String text or one word
``#>``   Usually index of Lists etc   Numbers
``?>``   Question Input               yes/no
=======  ===========================  ==========================

Basic Commands
--------------

- New
    **Command** : ``new`` or ``n``

    **Function** : Create a new Todo List

    When executed it Asks for Title and Tags(optional)

- Open
    **Command**  : ``open`` or ``o``

    **Function** : Open a Todo list from the available options.

    Open A new Note List to do further editing. When Executed it asks for the index of the list you want to open. If There is no list present then It tells you to create a new one.
