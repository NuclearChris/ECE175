#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "election.h"

int main() {
    //random number seed
    srand(time(0));
    //declare variables
    int voterCount;
    Person voters[MAX_VOTERS];
    Party partyA, partyB;
    Vote* voteList = NULL;
    //call the function to read in voter info from the .txt file
    readVoterInfo("people.txt", voters, &voterCount);
    //prompt the user to enter the number of participants
    printf("Enter the number of people participating in the elections: ");
    scanf("%d", &voterCount);
    //participants must be between 3 & 50
    if (voterCount <= 3 || voterCount > 50) {
        printf("Number of participants must be greater than 3 and less than or equal to 50.\n");
        return 1;
    }
//Party A Details
    printf("Enter details for Party A:\n");
    //see election.c for more info on the function below
    getPartyInfo(&partyA);

    printf("Enter details for Party B:\n");
    //see election.c for more info on the function below
    getPartyInfo(&partyB);

    //begin the election
    char startElection;
    printf("Enter 'E' to begin elections: ");
    scanf(" %c", &startElection);
    //user must select E, otherwise a failure statement is printed
    if (startElection != 'E') {
        printf("Incorrect selection. Please enter 'E' to start the elections.\n");
        return 1;
    }

    //see main.c for details about these next three functions

    //assign voter affiliation to each voter in the list
    assignRandomAffiliations(voters, voterCount, &partyA, &partyB);
    //assign votes based on voter affiliation, or random for NA affiliation
    castVotes(voters, voterCount, &partyA, &partyB, &voteList);
    //count the votes & print the results after counting
    countVotes(voteList, &partyA, &partyB);

    return 0;
}
