#include "tennis_game_1.h"
#include <string.h>
#include <stdlib.h>

tennis_game_1_t create_tennis_game_1(const char *player1_name, const char *player2_name)
{
    tennis_game_1_t result;

    result.player1_name = (char *) malloc(sizeof(char) * strlen(player1_name) + 1);
    strcpy(result.player1_name, player1_name);

    result.player2_name = (char *) malloc(sizeof(char) * strlen(player2_name) + 1);
    strcpy(result.player2_name, player2_name);

    result.P1point = 0;
    result.P2point = 0;

    return result;
}

void won_point_1(tennis_game_1_t *tennis_game, const char *player_name)
{
    if (strcmp(player_name, tennis_game->player1_name) == 0) {
        tennis_game->P1point += 1;
    } else {
        tennis_game->P2point += 1;
    }
}

char *get_score_1(tennis_game_1_t *tennis_game)
{
    char *score;
    char temp_string[20];
    static const char *score_strings[] = {"Love", "Fifteen", "Thirty", "Forty"};

    if (tennis_game->P1point < 4 && tennis_game->P2point < 4) {
        if (tennis_game->P1point == tennis_game->P2point) {
            strcpy(temp_string, score_strings[tennis_game->P1point]);
            strcat(temp_string, "-All");
        } else {
            strcpy(temp_string, score_strings[tennis_game->P1point]);
            strcat(temp_string, "-");
            strcat(temp_string, score_strings[tennis_game->P2point]);
        }
    } else {
        if (tennis_game->P1point == tennis_game->P2point) {
            strcpy(temp_string, "Deuce");
        }
        if (abs(tennis_game->P1point - tennis_game->P2point) == 1) {
            (tennis_game->P1point > tennis_game->P2point) ? strcpy(temp_string, "Advantage player1") : strcpy(temp_string,
                                                                                                              "Advantage player2");
        }

        if (abs(tennis_game->P1point - tennis_game->P2point) >= 2) {
            (tennis_game->P1point > tennis_game->P2point) ? strcpy(temp_string, "Win for player1") : strcpy(temp_string,
                                                                                                            "Win for player2");
        }
    }
    score = (char *) malloc(sizeof(char) * strlen(temp_string) + 1);
    strcpy(score, temp_string);
    return score;
}