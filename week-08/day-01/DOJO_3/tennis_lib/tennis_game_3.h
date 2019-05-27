#ifndef TENNIS_GAME_TENNIS_GAME_3_H
#define TENNIS_GAME_TENNIS_GAME_3_H

typedef struct
{
    int player_one_score;
    int player_two_score;
    char *player_one_name;
    char *player_two_name;
} tennis_game_3_t;

tennis_game_3_t create_tennis_game_3(const char *, const char *);
void won_point_3(tennis_game_3_t *, const char *);
const char * get_score_3(tennis_game_3_t *);

#endif //TENNIS_GAME_TENNIS_GAME_3_H
