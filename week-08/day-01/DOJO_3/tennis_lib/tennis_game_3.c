#include "tennis_game_3.h"
#include <string.h>
#include <stdlib.h>

tennis_game_3_t create_tennis_game_3(const char *player_one_name, const char *player_two_name)
{
    tennis_game_3_t result;
    result.player_one_score = 0;
    result.player_two_score = 0;
    result.player_one_name = calloc(strlen(player_one_name) + 1, 1);
    result.player_two_name = calloc(strlen(player_two_name) + 1, 1);
    strcpy(result.player_one_name, player_one_name);
    strcpy(result.player_two_name, player_two_name);
    return result;
}

void won_point_3(tennis_game_3_t *tennis_game, const char *player_name)
{
    if (strcmp(player_name, tennis_game->player_one_name) == 0) {
        tennis_game->player_one_score++;
    } else {
        tennis_game->player_two_score++;
    }
}

const char * get_score_3(tennis_game_3_t *tennis_game)
{
    char *result_string;

    if (tennis_game->player_one_score < 4 && tennis_game->player_two_score < 4) {
        static const char *score_strings[] = {"Love", "Fifteen", "Thirty", "Forty"};
        char temp_score_string[20];
        strcpy(temp_score_string, score_strings[tennis_game->player_one_score]);

        if (tennis_game->player_one_score == tennis_game->player_two_score) {
            strcat(temp_score_string, "-All");
        } else {
            strcat(temp_score_string, "-");
            strcat(temp_score_string, score_strings[tennis_game->player_two_score]);
        }

        result_string = calloc(strlen(temp_score_string) + 1, sizeof(char));
        strcpy(result_string, temp_score_string);
        return result_string;

    } else {
        if (tennis_game->player_one_score == tennis_game->player_two_score)
            return "Deuce";

        char temp_name_string[20];
        (tennis_game->player_one_score > tennis_game->player_two_score) ? strcpy(temp_name_string, tennis_game->player_one_name) : strcpy(temp_name_string, tennis_game->player_two_name);

        char temp_score_string[15];
        ((tennis_game->player_one_score - tennis_game->player_two_score) * (tennis_game->player_one_score - tennis_game->player_two_score) == 1) ? strcpy(temp_score_string, "Advantage ") : strcpy(temp_score_string, "Win for ");

        result_string = calloc(strlen(temp_name_string) + strlen(temp_score_string) + 1, sizeof(char));
        strcpy(result_string, temp_score_string);
        strcat(result_string, temp_name_string);
        return result_string;
    }
}