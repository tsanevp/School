#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct user_info User;

struct user_info {
    char *first_name;
    char *last_name;
    int id;
    char* location;
};

// Greetings and goodbyes
void StandardGreeting(User*);
void FormalGreeting(User*);
void InformalGoodbye(User*);
void FormalGoodbye(User*);

#endif
