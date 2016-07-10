..  _fabric:

================
Fabric
================

..  Note:: Before proceding make sure you have read the :ref:`data-concept`

This is the header file which contains the data members used in the program.

They are as follows:

..  _todo:

Todo
****************

Todo is the basic unit of the application it contains the following public data members

- ``content`` a character array of 200 char elements.

- ``status`` user defined char that stores the :ref:`status`.

List
****************

It is the collection of Todos. Most operations are performed throught this class. All data members and functions are public.

It contains the following data members -

- ``Todo list[20]``

- ``char title[100]``
- ``char tags[10][20]``

- ``int _listIndex``
    Variable to count the filling of list

- ``int _tagIndex``
    Variable to count the filling of tags

- ``int _hasTags``


It contains the following functions -

- ``List()``
    Asks for title(required) and tags(can be skipped).

- ``List(char Title[100])``
    Initialize the list with title

- ``void enter()``
    Enter the info given by user

- ``void addTag(char Tag[20])``
    Add the tag to Tags

- ``void setTitle(char Title[100])``
    Set the Title given

- ``void view()``
    View the list's title tags and #content

- ``void indexView()``
    View the contents with the index

- ``void tagView()``
    View only Title and tags

- ``void todoView(int)``
    View the todo of index passed

- ``void tagIndexView()``
    View the Title and Tags with the index

- ``void append()``
    append a new ToDo in the list

- ``void removeTodo(int)``
    delete the list at index passed

- ``void removeTag(int)``
    delete the tag at index passed

- ``void changeStatus(int index, char status)``
    Changes Status of the Item of index to status
