#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "election.h"

//This function readVoterInfo opens the file of voters and stores their information to a data structure in dynamic memory
void readVoterInfo(const char* filename, Person* voters, int* voterCount) {
    //open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    //while loop to scan through lines in the file and store voter name, age, ssn, etc
    *voterCount = 0;
    while (fscanf(file, "%s %s %d %s %s %s", voters[*voterCount].firstName, voters[*voterCount].lastName,
                  &voters[*voterCount].age, voters[*voterCount].ssn, voters[*voterCount].phone, 
                  voters[*voterCount].party_affiliation) != EOF && *voterCount < MAX_VOTERS) {
        strcpy(voters[*voterCount].party_affiliation, "na");
        (*voterCount)++;
    }
    //close the file
    fclose(file);
}

//This function prompts the user to enter the candidates for a party (called twice, one for each party)
void getPartyInfo(Party* party) {
    printf("Enter party name: ");
    scanf("%s", party->partyName);
    printf("Enter President Candidate (first name, last name, age): ");
    scanf("%s %s %d", party->president.firstName, party->president.lastName, &party->president.age);
    printf("Enter Senator Candidate (first name, last name, age): ");
    scanf("%s %s %d", party->senator.firstName, party->senator.lastName, &party->senator.age);
    printf("Enter Congress Candidate (first name, last name, age): ");
    scanf("%s %s %d", party->congress.firstName, party->congress.lastName, &party->congress.age);
}

//This function assigns party affiliations to the voters, where 1/3 will be partyA, 1/3 is partyB, and 1/3 is na (ind.)
void assignRandomAffiliations(Person* voters, int voterCount, Party* partyA, Party* partyB) {
    for (int i = 0; i < voterCount; i++) {
        int random = rand() % 3;
        if (random == 0) {
            strcpy(voters[i].party_affiliation, "na");
        } else if (random == 1) {
            strcpy(voters[i].party_affiliation, partyA->partyName);
        } else {
            strcpy(voters[i].party_affiliation, partyB->partyName);
        }
    }
}

//This function creates the vote structure in dynamic memory
Vote* createVote(Candidate president, Candidate senator, Candidate congress, Person voter) {
    Vote* newVote = (Vote*)malloc(sizeof(Vote));
    newVote->selectPresident = president;
    newVote->selectSenator = senator;
    newVote->selectCongress = congress;
    newVote->voter = voter;
    newVote->next = NULL;
    //returns the pointer to the vote structure
    return newVote;
}

//This function castVotes assigns candidates to votes based on aprty affiliation
void castVotes(Person* voters, int voterCount, Party* partyA, Party* partyB, Vote** voteList) {
    for (int i = 0; i < voterCount; i++) {
        Candidate president, senator, congress;
        //based on party affiliation assigned in assignRandomAffiliations()
        if (strcmp(voters[i].party_affiliation, partyA->partyName) == 0) {
            president = partyA->president;
            senator = partyA->senator;
            congress = partyA->congress;
        //based on party affiliation assigned in assignRandomAffiliations()
        } else if (strcmp(voters[i].party_affiliation, partyB->partyName) == 0) {
            president = partyB->president;
            senator = partyB->senator;
            congress = partyB->congress;
        } else {
            // In this case, they're NA without party affiliation, so randomly select for each position
            if (rand() % 2 == 0) {
                president = partyA->president;
            } else {
                president = partyB->president;
            }

            if (rand() % 2 == 0) {
                senator = partyA->senator;
            } else {
                senator = partyB->senator;
            }

            if (rand() % 2 == 0) {
                congress = partyA->congress;
            } else {
                congress = partyB->congress;
            }

        }
        Vote* vote = createVote(president, senator, congress, voters[i]);
        vote->next = *voteList;
        *voteList = vote;

        // This print statement is used for troubleshooting the code
        //it prints the voters, party affiliations, and their votes
        printf("%d. Voter: %s --- Party Affiliation: %s --- pVote: %s --- sVote: %s --- cVote: %s\n", i+1, voters[i].firstName, voters[i].party_affiliation, president, senator, congress);
   }
}

// This function simply runs through the list counting votes
void countVotes(Vote* voteList, Party* partyA, Party* partyB) {
    int presidentVotesA = 0, senatorVotesA = 0, congressVotesA = 0;
    int presidentVotesB = 0, senatorVotesB = 0, congressVotesB = 0;

    Vote* current = voteList;
    while (current != NULL) {
        if (strcmp(current->selectPresident.firstName, partyA->president.firstName) == 0 &&
            strcmp(current->selectPresident.lastName, partyA->president.lastName) == 0) {
            presidentVotesA++;
        } else {
            presidentVotesB++;
        }

        if (strcmp(current->selectSenator.firstName, partyA->senator.firstName) == 0 &&
            strcmp(current->selectSenator.lastName, partyA->senator.lastName) == 0) {
            senatorVotesA++;
        } else {
            senatorVotesB++;
        }

        if (strcmp(current->selectCongress.firstName, partyA->congress.firstName) == 0 &&
            strcmp(current->selectCongress.lastName, partyA->congress.lastName) == 0) {
            congressVotesA++;
        } else {
            congressVotesB++;
        }

        current = current->next;
    }

//print the results
    printf("Election Results:\n");
    printf("President: %s %s (%s) - %d votes\n", 
           presidentVotesA > presidentVotesB ? partyA->president.firstName : partyB->president.firstName,
           presidentVotesA > presidentVotesB ? partyA->president.lastName : partyB->president.lastName,
           presidentVotesA > presidentVotesB ? partyA->partyName : partyB->partyName,
           presidentVotesA > presidentVotesB ? presidentVotesA : presidentVotesB);

    printf("Senator: %s %s (%s) - %d votes\n", 
           senatorVotesA > senatorVotesB ? partyA->senator.firstName : partyB->senator.firstName,
           senatorVotesA > senatorVotesB ? partyA->senator.lastName : partyB->senator.lastName,
           senatorVotesA > senatorVotesB ? partyA->partyName : partyB->partyName,
           senatorVotesA > senatorVotesB ? senatorVotesA : senatorVotesB);

    printf("Congress: %s %s (%s) - %d votes\n", 
           congressVotesA > congressVotesB ? partyA->congress.firstName : partyB->congress.firstName,
           congressVotesA > congressVotesB ? partyA->congress.lastName : partyB->congress.lastName,
           congressVotesA > congressVotesB ? partyA->partyName : partyB->partyName,
           congressVotesA > congressVotesB ? congressVotesA : congressVotesB);
}
