#include <stdio.h>
#include <string.h>  // Include for strcpy and other string functions

// Define the PlayerStats structure
typedef struct {
    char name[50];  // Player's name
    int points;
    int assists;
    int rebounds;
    int steals;
    int blocks;
    int turnovers;
    int gamesPlayed;  // Number of games for normalization
} PlayerStats;

// Function Prototypes
void inputPlayerStats(PlayerStats *player);
void calculatePerformance(PlayerStats player);
void comparePlayers(PlayerStats players[], int numPlayers);
void saveToFile(PlayerStats players[], int numPlayers);
int loadFromFile(PlayerStats players[]);
void showMenu();
void updatePlayerStats(PlayerStats players[], int numPlayers);
int removePlayer(PlayerStats players[], int numPlayers);

// Function to input player statistics
void inputPlayerStats(PlayerStats *player) {
    printf("Enter player name: ");
    getchar();  // Clear the newline character in buffer
    fgets(player->name, 50, stdin);
    player->name[strcspn(player->name, "\n")] = '\0';  // Remove the newline character

    printf("Enter total points: ");
    scanf("%d", &player->points);

    printf("Enter total assists: ");
    scanf("%d", &player->assists);

    printf("Enter total rebounds: ");
    scanf("%d", &player->rebounds);

    printf("Enter total steals: ");
    scanf("%d", &player->steals);

    printf("Enter total blocks: ");
    scanf("%d", &player->blocks);

    printf("Enter total turnovers: ");
    scanf("%d", &player->turnovers);

    printf("Enter games played: ");
    scanf("%d", &player->gamesPlayed);
}

// Function to calculate and display performance statistics
void calculatePerformance(PlayerStats player) {
    float ppg = (float)player.points / player.gamesPlayed;
    float apg = (float)player.assists / player.gamesPlayed;
    float rpg = (float)player.rebounds / player.gamesPlayed;
    float spg = (float)player.steals / player.gamesPlayed;
    float bpg = (float)player.blocks / player.gamesPlayed;
    float topg = (float)player.turnovers / player.gamesPlayed;

    printf("\nPerformance Analysis for %s\n", player.name);
    printf("Points per game: %.2f\n", ppg);
    printf("Assists per game: %.2f\n", apg);
    printf("Rebounds per game: %.2f\n", rpg);
    printf("Steals per game: %.2f\n", spg);
    printf("Blocks per game: %.2f\n", bpg);
    printf("Turnovers per game: %.2f\n", topg);

    // Simple analysis
    if (ppg > 20) {
        printf("This player is a high scorer.\n");
    } else {
        printf("This player could improve their scoring.\n");
    }

    if (apg > 5) {
        printf("This player is an excellent playmaker.\n");
    } else {
        printf("This player should work on their assists.\n");
    }

    if (rpg > 8) {
        printf("This player is strong in rebounding.\n");
    } else {
        printf("This player could focus more on rebounding.\n");
    }
}

// Function to compare players and find the best scorer
void comparePlayers(PlayerStats players[], int numPlayers) {
    float maxPPG = 0;
    char bestScorer[50];

    for (int i = 0; i < numPlayers; i++) {
        float ppg = (float)players[i].points / players[i].gamesPlayed;
        if (ppg > maxPPG) {
            maxPPG = ppg;
            strcpy(bestScorer, players[i].name);
        }
    }

    printf("The best scorer is: %s with %.2f points per game.\n", bestScorer, maxPPG);
}

// Function to save player stats to a file
void saveToFile(PlayerStats players[], int numPlayers) {
    FILE *file = fopen("players.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numPlayers; i++) {
        fprintf(file, "%s %d %d %d %d %d %d %d\n", players[i].name, players[i].points, players[i].assists, players[i].rebounds,
                players[i].steals, players[i].blocks, players[i].turnovers, players[i].gamesPlayed);
    }
    fclose(file);
    printf("Player stats saved to file.\n");
}

// Function to load player stats from a file
int loadFromFile(PlayerStats players[]) {
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("No saved data found.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%s %d %d %d %d %d %d %d\n", players[i].name, &players[i].points, &players[i].assists, &players[i].rebounds,
                  &players[i].steals, &players[i].blocks, &players[i].turnovers, &players[i].gamesPlayed) != EOF) {
        i++;
    }
    fclose(file);
    printf("Player stats loaded from file.\n");
    return i;
}

// Function to update player stats
void updatePlayerStats(PlayerStats players[], int numPlayers) {
    char name[50];
    printf("Enter the name of the player to update: ");
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Updating stats for %s.\n", players[i].name);
            inputPlayerStats(&players[i]);
            printf("Stats updated successfully.\n");
            return;
        }
    }
    printf("Player not found.\n");
}

// Function to remove a player
int removePlayer(PlayerStats players[], int numPlayers) {
    char name[50];
    printf("Enter the name of the player to remove: ");
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, name) == 0) {
            for (int j = i; j < numPlayers - 1; j++) {
                players[j] = players[j + 1];
            }
            printf("Player %s removed successfully.\n", name);
            return numPlayers - 1;  // Decrease the total count
        }
    }
    printf("Player not found.\n");
    return numPlayers;  // Return unchanged count if not found
}

// Function to display the menu
void showMenu() {
    printf("\nBasketball Player Performance Analyzer Menu:\n");
    printf("1. Add Player Stats\n");
    printf("2. Calculate Performance\n");
    printf("3. Compare Players\n");
    printf("4. Save Stats to File\n");
    printf("5. Load Stats from File\n");
    printf("6. Update Player Stats\n");
    printf("7. Remove Player\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    PlayerStats players[100];
    int numPlayers = 0, choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputPlayerStats(&players[numPlayers]);
                numPlayers++;
                break;
            case 2:
                for (int i = 0; i < numPlayers; i++) {
                    calculatePerformance(players[i]);
                }
                break;
            case 3:
                comparePlayers(players, numPlayers);
                break;
            case 4:
                saveToFile(players, numPlayers);
                break;
            case 5:
                numPlayers = loadFromFile(players);
                break;
            case 6:
                updatePlayerStats(players, numPlayers);
                break;
            case 7:
                numPlayers = removePlayer(players, numPlayers);
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}


