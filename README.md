# String
String structure made in C.

To make a String ,,object'' you have to use a function String_Init:

  PString str = String_Init();

Or

  String* str = String_Init();

PString is a pointer to structure and String is just a structre. 
String_Init function initializes a structure by assing a function pointers and initializes two other variabules: char* str and size_t size;

1. char* str will contain a string.
2. size_t size will have a string lenght.

If you want to see what function dose, just have a look to stringlib.c and look for the ones that interest you and just check text above it. 
To use String function you need a String variable. If you have one you just need to use it as a pointer to function inside a structure. Like this:

  str->stringDup(str, "Hello World");

The first argument is always a self-variable. For the rest of arguments you can just look into stringlib.c. The names should be self explanatory and if not - 
you have a explanation above a function. 

If you want to destroy a variable you can use String_Destory:

  PString str = String_Init();
  String_Destory(&str);
