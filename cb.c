#include <stdio.h>
#include <strings.h>
#include <time.h>
#include <stdlib.h>

void remove_white_spaces(char *user_input);
char *Response(char *user_input);
struct cb
{
    char question[50];
    char answer[50];
};
char response[30];
int main()
{
    int i;
    system("color 1F");
    system("cls");
    char user_input[50], name[30], copy_input[50];
    char *intent, *context;

    printf("\n\t\t\t\t\t\t\tCHATBOT\n");
    printf(" Please enter you name to proceed: ");
    gets(name);

    printf("\n Hello %s, I am Robo Your personal Chatbot.\n Ask me something...\n", name);

    while (1)
    {
        printf("\n %s: ", name);
        gets(user_input);

        strlwr(user_input);
        strcpy(copy_input, user_input);

        intent = strtok_r(copy_input, " ", &context);

        if ((strcmp(intent, "google") == 0) || (strcmp(intent, "search") == 0))
        {
            char s[100] = "START https://www.google.com/search?q=";
            for (i = 0; i <= 6; i++)
            {
                user_input[i] = ' ';
            }

            for (i = 0; user_input[i]; i++)
            {
                if (user_input[i] == ' ')
                {
                    user_input[i] = '+';
                }
            }

            strcat(s, user_input);

            system(s);
        }
        else if (strcmp(intent, "youtube") == 0)
        {
            char s[100] = "START https://www.youtube.com/results?search_query=";
            for (i = 0; i <= 7; i++)
            {
                user_input[i] = ' ';
            }

            for (i = 0; user_input[i]; i++)
            {
                if (user_input[i] == ' ')
                {
                    user_input[i] = '+';
                }
            }

            strcat(s, user_input);

            system(s);
        }
        else
        {
            remove_white_spaces(user_input);

            if (strcmp(user_input, "exit") == 0)
                break;

            printf("\n Robo: %s\n", Response(user_input));
        }
    }
}

char *Response(char *user_input)
{

    int n, i;
    int items_count = 0;
    struct cb query[100];
    FILE *items_file = fopen("data.txt", "r");
    if (items_file == NULL)
    {
        printf("ERROR: unable to read items file, aborting program\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        n = fscanf(items_file, "%s %[^\n]", query[items_count].question, query[items_count].answer);

        if (n == EOF)
        {
            break;
        }
        else
        {
            items_count++;
        }
    }
    fclose(items_file);

    // for (i = 0; i < items_count; i++)
    // {
    //     printf("\nQuestion: %s\nAnswer: %s", query[i].question, query[i].answer);
    // }

    for (i = 0; i < items_count; i++)
    {
        if ((strcmp(user_input, query[i].question) == 0))
        {
            strcpy(response, query[i].answer);
            return response;
        }
    }
    return "Sorry, my last transistor broke while processing your absolutely philosophical thought";
}

void remove_white_spaces(char *user_input)
{
    int i = 0, j = 0;
    while (user_input[i])
    {
        if (user_input[i] != ' ')
            user_input[j++] = user_input[i];
        i++;
    }
    user_input[j] = '\0';
}
