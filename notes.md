# Some personal notes

Leandro D. Medus  
University of Valencia  
Leandro.D.Medus@uv.es  
[ October 2020 ]  

---

Current notes based on the book "Mastering Algorithms with C" by Kyle Loudon.

## Ch2. Pointer manipulation

### Aggregates and Pointer Arithmetic

One of the most common uses of pointers in C is referencing aggregate data.
Aggregate data is data composed of multiple elements grouped together because
they are somehow related. C supports two classes of aggregate data: structures
and arrays. (Unions, although similar to structures, are considered formally to be
in a class by themselves.)

typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
} ListElmt;

Structures are not permitted to contain instances of themselves, but they
may contain pointers to instances of themselves

Arrays are sequences of homogeneous elements arranged consecutively in memory.
When an array identifier
occurs in an expression, C converts the array transparently into an unmodifiable
pointer that points to the array’s first element.

### Pointers as Parameters to Functions

When defining a function that accepts a multidimensional array, all but the first
dimension must be specified so that pointer arithmetic can be performed when
elements are accessed, as shown in the following code:

int g(int a[][2]) {
    a[2][0] = 5;
    return 0;
}

### Cast

Casts are especially important with generic pointers because generic pointers cannot
be dereferenced without casting them to some other type.

Function Pointers

int (*match)(void *key1, void *key2);
This declaration means that we can set match to point to any function that accepts
two void pointers and returns an integer. For example, suppose match_int is a
function that accepts two void pointers. Assuming the previous declaration, we could set match to
point to this function by executing the following statement:
match = match_int;
assuming x, y, and retval have been declared as integers
retval = match(&x, &y);

## Ch3. Recursion
27



## Some basic reminders

```c
switch(grade)
{
    case 'A':
        printf("Excellent\n");
        break;
    case 'B':
        printf("Keep it up!\n\n");
        break;
    default:
        printf("Invalid\n");
}
```