#include <stdio.h>
#include <string.h>

// declaring a structure
struct __Person
{
  // this is a struct field, it can be
  // any data type, including other structs
  string name;
  string civilStatus;
  unsigned int age;
  unsigned short gender; // 0 male, 1 female, 2 non-binary, 99 other
};

typedef char string[255];

// using typedef so we dont have to use struct keyword
typedef struct __Person Person;

// struct used as argument in function
void printPerson(Person person)
{
  // to access fields, use the dot '.' operator
  printf("name = %s\n", person.name);
  printf("age = %d\n", person.age);

  switch (person.gender)
  {
  case 0:
    printf("gender = male\n");
    break;
  case 1:
    printf("gender = female\n");
    break;
  case 2:
    printf("gender = non-binary\n");
    break;
  default:
    printf("gender = other\n");
    break;
  }
}

// to modify struct fields, use pointers
void birthday(Person *person)
{
  // dereference the pointer to access the struct fields
  (*person).age += 1;
}

void married(Person *person)
{
  // using strcpy to copy string to struct field
  // using assignment operator is not allowed
  // since the string already has a base address
  // from where it was declared
  strcpy((*person).civilStatus, "married");
  strcpy((*person).name, "Mrs. Jane Doe");
}

int main(void)
{
  // declaring a struct variable
  Person aPerson = {
      // notice here that we explicitly show the field names, this is optional
      // but a struct initialization w/o fields is not recommended
      .name = "John Doe",
      .age = 30,
      .gender = 0};

  Person bPerson = {
      .name = "Jane Doe",
      .age = 28,
      .gender = 1};

  // converting variable to pointer for its fields to be updated
  birthday(&aPerson);
  married(&bPerson);

  // normal variable as we're only reading
  printPerson(aPerson);
  printPerson(bPerson);

  return 0;
}
