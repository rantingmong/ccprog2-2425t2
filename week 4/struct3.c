#include <stdio.h>
#include <string.h>

typedef char String[255];
typedef Pet Pets[10];

typedef struct
{
  String name;
  String breed;
  String species;
  int age;
} Pet;

typedef struct
{
  String name;
  String address;
  // struct field is an array of "Pet" structs
  Pets pet;
} Owner;

void birthdayNiPet(Owner *owner, String petName)
{
  for (int i = 0; i < 10; i++)
  {
    if (strcmp(owner->pet[i].name, petName) == 0)
    {
      // same mechanics as the previous example
      // but we're now also using the array index
      // operator to get the specific pet
      Pet newPet = owner->pet[i];
      newPet.age += 1;

      owner->pet[i] = newPet;

      break;
    }
  }
}

int main(void)
{
  Pet petLiem = {
      .name = "liempo",
      .breed = "domestic shorthair",
      .species = "cat",
      .age = 5};

  Pet petGorg = {
      .name = "george",
      .breed = "domestic shorthair",
      .species = "cat",
      .age = 4};

  Pet petClem = {
      .name = "clementine",
      .breed = "domestic shorthair",
      .species = "cat",
      .age = 3};

  Owner owner = {
      .name = "mong",
      .address = "Lipa city",
      // initializing the array of structs
      .pet = {petLiem, petGorg, petClem}};

  // this is also ok
  owner.pet[0] = petLiem;
  owner.pet[1] = petGorg;
  owner.pet[2] = petClem;

  birthdayNiPet(&owner, "liempo");

  for (int i = 0; i < 10; i++)
  {
    // iterating a struct field's array contents
    if (owner.pet[i].name[0] == '\0')
    {
      continue;
    }

    printf("pet name %s\n", owner.pet[i].name);
    printf("pet age: %d\n", owner.pet[i].age);
    printf("\n");
  }
}
