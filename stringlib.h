//
// Created by Mateusz Magdziński on 01.07.2023.
//

#ifndef MYSTRING_STRINGLIB_H
#define MYSTRING_STRINGLIB_H


// The size is to the end of string without terminator
typedef struct string_t
{
    char* str;
    size_t size;

    size_t (*lenght)(struct string_t*);
    // String manipulation
    void (*stringDup)(struct string_t*, char*);
    void (*stringCat)(struct string_t*, char*);
    char*  (*stringSlice)(struct string_t*, unsigned int, unsigned int);
    char* (*stringReverse)(struct string_t*);

    //TODO: String Manipulation, Status: 0


    // Utilites
    void (*printStr)(struct string_t*);
    void (*clearStr)(struct string_t**);
    void (*addEnterAtEnd)(struct string_t*);
    void (*changeLetter)(struct string_t*, char, char);

    //TODO: String Utilites, Status: 0



}String, *PString;

String * String_Init();
void String_Destory(String **);

#endif //MYSTRING_STRINGLIB_H
