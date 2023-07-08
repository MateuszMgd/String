//
// Created by Mateusz Magdziński on 01.07.2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "stringlib.h"
#include "string.h"

// ********************* FUNCTIONS INSIDE STRUCTURE *********************

// *************************************************
// ** String Duplication **
// String *self -> a pointer to self
// char* str -> a text that will be stored in String
// Dose nothing if error happened.
// *************************************************
void stringDup(String *self, char* str)
{
    if(self == NULL)
    {
        printf("[Error] Function argument is NULL\n");
        return;
    }

    if(self->size)
    {
        printf("[Error] String is not empty. Use other function!\n");
        return;
    }

    self->str = strdup(str);
    if(self->str == NULL)
    {
        printf("[Error] Cannot allocate memory\n");
        return;
    }
    self->size = strlen(str);
}

// *************************************************
// ** String Concatenation **
// String *self -> a pointer to self
// char* str -> a text that will be stored at the end of String
// Dose nothing if error happened.
// *************************************************
void stringCat(String *self, char *str)
{
    if(self == NULL)
    {
        printf("[Error] Function argument is NULL\n");
        return;
    }
    if(!self->size) // String is empty
    {
        self->stringDup(self, str);
        return;
    }

    char* temp = (char *) realloc(self->str, sizeof(char)*(self->size + strlen(str) + 1));
    if(temp == NULL)
    {
        printf("[Error] Too little memory to allocate more for string concatenation\n");
        return;
    }
    self->str = temp;
    temp = NULL;

    strcat(self->str, str);

    self->size = self->size + strlen(str);
}

// *************************************************
// ** String Slice **
// String *self -> a pointer to self
// unsigned int index_first -> first included part of sliced string
// unsigned int index_last -> last included part of sliced string
// Dose nothing if error happened and returns NULL.
// *************************************************
char*  stringSlice(struct string_t* self, unsigned int index_first, unsigned int index_last)
{
    if(self == NULL || index_first > index_last || index_first >= self->size || index_last >= self->size)
    {
        return NULL;
    }

    int sliced_string_size = ((int)index_last - (int)index_first - 2) * (-1);

    char* sliced_string = (char*)calloc(sliced_string_size, sizeof(char));
    if(sliced_string == NULL)
    {
        return NULL;
    }

    for(unsigned int i = index_first; i <= index_last; i++)
        *(sliced_string + (i - index_first)) = *(self->str + i);

    return sliced_string;
}

// *************************************************
// ** String Reverse **
// String *self -> a pointer to self
// Dose nothing if error happened and returns NULL.
// *************************************************
char* stringReverse(struct string_t* self)
{
    if(self == NULL || self->str == NULL || self->size == 0)
    {
        return NULL;
    }

    char* reversed_string = (char *)calloc(self->size + 1, sizeof(char));
    if(reversed_string == NULL)
    {
        return NULL;
    }

    for(int i = 0; i < self->size; i++)
        *(reversed_string + i) = *(self->str + self->size - 1 - i);

    return reversed_string;
}


// *************************************************
// ** String Lenght **
// String *self -> a pointer to self
// Returns a size of String (text at char * of struct)
// *************************************************
size_t lenght(String *self)
{
    if(self == NULL)
    {
        printf("[Error] Function argument is NULL\n");
        return -1;
    }

    return self->size;
}

// *************************************************
// ** String Print **
// String *self -> a pointer to self
// Function prints Text at String structure (char *str)
// *************************************************
void printStr(String* self)
{
    if(self == NULL || self->str == NULL)
    {
        return;
    }
    printf("%s\n", self->str);
}

// *************************************************
// ** String Print **
// String *self -> a pointer to self
// Function clears Text at String structure (char *str) and set value of size to 0.
// *************************************************
void clearStr(String** self)
{
    if(self == NULL || (*self)->str == NULL)
    {
        return;
    }
    free((*self)->str);
    (*self)->str = NULL;
    (*self)->size = 0;
}

// *************************************************
// ** Add Enter At End **
// String *self -> a pointer to self
// Function at \n on the of string.
// Dose nothing if error happened.
// *************************************************
void addEnterAtEnd(struct string_t* self)
{
    if(self == NULL)
    {
        return;
    }
    self->stringCat(self, "\n");
}

// *************************************************
// ** Change Letter **
// String *self -> a pointer to self
// char letter_to_change -> letter that user want to change in String
// char new_letter -> new letter that will replace letter_to_change
// Function clears Text at String structure (char *str) and set value of size to 0.
// *************************************************
void changeLetter(struct string_t* self, char letter_to_change, char new_letter)
{
    if(self == NULL)
    {
        return;
    }

    for(int i = 0; i < self->size; ++i)
    {
        if(*(self->str + i) == letter_to_change)
        {
            *(self->str + i) = new_letter;
        }
    }
}

// ********************* FUNCTIONS OUTSIDE STRUCTURE *********************

// *************************************************
// ** String Initialization **
// Initializes a String Structure
// Returns a pointer to String structure
// *************************************************
String * String_Init()
{
    String *str = (String*) calloc(1, sizeof(String));
    if(!str)
    {
        printf("[Error] String allocation failed\n");
        return NULL;
    }

    str->str = NULL;
    str->size = 0;
    str->lenght = lenght;
    str->stringDup = stringDup;
    str->stringCat = stringCat;
    str->printStr = printStr;
    str->clearStr = clearStr;
    str->addEnterAtEnd = addEnterAtEnd;
    str->changeLetter = changeLetter;
    str->stringSlice = stringSlice;
    str->stringReverse = stringReverse;


    return str;
}

// *************************************************
// ** String Destroy **
// String **str -> destroy and change str to point at NULL
// *************************************************
void String_Destory(String **str)
{
    if(str == NULL)
    {
        return;
    }
    if(!((*str)->str))
        free((*str)->str);
    if(!(*str))
        free((*str));
    *str = NULL;
}
