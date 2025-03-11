
typedef struct  {
    char name[100];
    int utility; // 0 - living, 1 - dining, 2 - bedroom, 3 - veranda
} Room;


typedef struct {
    char name[100];
    char address[100];
    int numLevels;
    Room rooms[10];
    int numberOfRooms;
} Home;

Home createHome() {
    Home home;
    strcpy(home.name, "New Home");
    strcpy(home.address, "123 Main St");
    home.numLevels = 2;
    home.numberOfRooms = 10;
    
    for (int i = 0; i < 10; i++) {
        strcpy(home.rooms[i].name, "Room ");
        home.rooms[i].utility = i % 2;
    }
    return home;
}

void printRoomsOfUtilityType(Home home, int utilityType) {
    int counter ;
    
    for (counter = 0; counter < home.numberOfRooms; counter++) {
        if (home.rooms[counter].utility == utilityType) {
            printf("%s\n", home.rooms[counter].name);
        }
    }
}

void removeRoomsOfUtilityType(Home *home, int utilityType, int *pNewRoomCount) {
    Room newRooms[10];
    
    int counter = 0;
    int newRoomCount = 0;
    
    for (counter = 0; counter < home->numberOfRooms; counter++) {
        if (home->rooms[counter].utility != utilityType) {
            newRooms[newRoomCount++] = home->rooms[counter];
        }
    }
    
    home->numberOfRooms = newRoomCount;
    memcpy(home->rooms, newRooms, sizeof(Room) * newRoomCount);
    
    *pNewRoomCount = newRoomCount;
}

void findAllHousesWithMoreThanThreeRooms(Home homes[], int numHomes, Home result[], int *pResultCount) {
    Home resultArray[10];
    
    int counter = 0;
    int resultCount = 0;
    
    for (counter = 0; counter < numHomes; counter += 1) {
        if (homes[counter].numberOfRooms > 3) {
            resultArray[resultCount++] = homes[counter];
        }
    }

    memcpy(result, resultArray, sizeof(Home) * resultCount);
    *pResultCount = resultCount;
}


// sir medyo lost lang po why is it when we're declaring a struct
// home variable is array po siya? like "Home ResultArray[10]"
// instead of just "Home ResultArray"?
// 
void function() {
    Home homes[10];
    
    
}

// hi sir, pwede po ba pareview po ng unti sa array at string functions?
// parang ung "assign value to array from user input" or
// "assign array to an empty string"
// 

void askHomes(int *pCount, Home homes[100]) {
    int bStop = 0;
    char continueChoice;
    
    int counter = 0;
    
    while (bStop == 0) {
        // ask for name
        scanf("%s", homes[counter].name);
        
        // ask for address
        scanf("%s", homes[counter].address);
        
        // ask for number of floors
        scanf("%d", &homes[counter].numberOfFloors);
        
        // ask user if they want to continue
        printf("Do you want to continue (Y/n):");
        scanf("%c", &continueChoice);
        
        if (continueChoice == 'Y' || continueChoice == 'y') {
            counter += 1;
        } else {
            bStop = 1;
            *pCount = counter + 1
        }
    }
}

void initializeName(char target[]) {
    strcpy(target, "");
}

/*

strcmp
strcpy
memcpy
strlen

review linear serach
review selection sort

*/


