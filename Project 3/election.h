#ifndef ELECTION_H
#define ELECTION_H

#define MAX_VOTERS 50

//Structure prototypes
typedef struct {
    char firstName[50];
    char lastName[50];
    int age;
    char ssn[12];
    char phone[15];
    char party_affiliation[50];
} Person;

typedef struct {
    char firstName[50];
    char lastName[50];
    int age;
} Candidate;

typedef struct {
    char partyName[50];
    Candidate president;
    Candidate senator;
    Candidate congress;
} Party;

typedef struct Vote {
    Candidate selectPresident;
    Candidate selectSenator;
    Candidate selectCongress;
    Person voter;
    struct Vote* next;
} Vote;

// Function declarations
void readVoterInfo(const char* filename, Person* voters, int* voterCount);
void getPartyInfo(Party* party);
void assignRandomAffiliations(Person* voters, int voterCount, Party* partyA, Party* partyB);
Vote* createVote(Candidate president, Candidate senator, Candidate congress, Person voter);
void castVotes(Person* voters, int voterCount, Party* partyA, Party* partyB, Vote** voteList);
void countVotes(Vote* voteList, Party* partyA, Party* partyB);

#endif // ELECTION_H
