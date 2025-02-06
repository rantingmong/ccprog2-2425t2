#include <stdio.h>

typedef struct
{
  char name[255];
  char breed[255];
  char species[255];
  int age;
} Pet;

// notice here that we have another struct
// as the field of the Owner struct
//
// treat structs as just any other data types
// that's the advantage of structs
//
// the typedef makes it even cleaner!
typedef struct
{
  char name[255];
  char address[255];
  Pet pet;
} Owner;

// pointer because we want to modify the struct's
// contents
void birthdayNiPet(Owner *owner)
{
  // but modifying two levels deep,
  // you need to get the child struct
  //
  // notice here that we're using the arrow (->) operator
  // this is just a shorthand for dereferencing the pointer
  // and accessing the field ( same as (*owner).pet )
  Pet petToChange = owner->pet;

  // do the modifications
  petToChange.age += 1;

  // and assign to the parent struct
  owner->pet = petToChange;
}

int main(void)
{
  Pet pet = {
      .name = "liempo",
      .breed = "domestic shorthair",
      .species = "cat",
      .age = 5};

  Owner owner = {
      .name = "mong",
      .address = "Lipa city",
      .pet = pet};

  birthdayNiPet(&owner);
  printf("pet name %s\n", owner.pet.name);
  printf("pet age: %d\n", owner.pet.age);
}
