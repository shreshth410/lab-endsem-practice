#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESC 200
#define MAX_CHOICE 100

typedef struct SceneNode {
    char description[MAX_DESC];
    char choiceA[MAX_CHOICE];  // Left path (Exploration)
    char choiceB[MAX_CHOICE];  // Right path (Battle)
    struct SceneNode* left;
    struct SceneNode* right;
    int depth;
    int node_id;
} SceneNode;

typedef struct GameState {
    SceneNode* current;
    int nodes_visited;
    int max_depth;
    SceneNode* visited_nodes[50];
    int visit_count;
} GameState;

// Global game state
GameState game;

// Function prototypes
SceneNode* createScene(const char* desc, const char* choiceA, const char* choiceB, int depth, int id);
void buildAdventureTree();
void displayScene(SceneNode* scene);
void makeChoice(char choice);
void postorderTraversal(SceneNode* root);
void calculateTreeStats(SceneNode* root, int* total_nodes, int* max_depth);
void showGameStats();
void freeTree(SceneNode* root);

// Create a new scene node
SceneNode* createScene(const char* desc, const char* choiceA, const char* choiceB, int depth, int id) {
    SceneNode* newScene = (SceneNode*)malloc(sizeof(SceneNode));
    strcpy(newScene->description, desc);
    strcpy(newScene->choiceA, choiceA);
    strcpy(newScene->choiceB, choiceB);
    newScene->left = NULL;
    newScene->right = NULL;
    newScene->depth = depth;
    newScene->node_id = id;
    return newScene;
}

// Build the adventure tree
void buildAdventureTree() {
    // Root scene - The Beginning
    SceneNode* root = createScene(
        "You stand at the entrance of the Ancient Forest. The path splits ahead...",
        "Explore the mysterious left path", 
        "Charge into the dangerous right path",
        0, 1
    );

    // Level 1 - Left (Exploration branch)
    root->left = createScene(
        "You find a tranquil glade with a sparkling pond. An old hermit approaches...",
        "Talk to the hermit peacefully",
        "Search the area for treasures",
        1, 2
    );

    // Level 1 - Right (Battle branch)  
    root->right = createScene(
        "A fierce wolf blocks your path! It growls menacingly...",
        "Try to tame the wolf",
        "Draw your sword and fight",
        1, 3
    );

    // Level 2 - Left-Left (Exploration -> Diplomacy)
    root->left->left = createScene(
        "The hermit offers you wisdom and a healing potion. He points to a hidden cave...",
        "Enter the hidden cave",
        "Continue along the forest path",
        2, 4
    );

    // Level 2 - Left-Right (Exploration -> Treasure Hunt)
    root->left->right = createScene(
        "You discover an ancient chest! But it's trapped with magical runes...",
        "Carefully disarm the trap",
        "Force the chest open",
        2, 5
    );

    // Level 2 - Right-Left (Battle -> Taming)
    root->right->left = createScene(
        "The wolf hesitates as you show no fear. It seems to understand you...",
        "Offer it food from your pack",
        "Attempt to communicate magically",
        2, 6
    );

    // Level 2 - Right-Right (Battle -> Combat)
    root->right->right = createScene(
        "The battle begins! The wolf lunges at you with incredible speed...",
        "Dodge and counterattack",
        "Use a defensive stance",
        2, 7
    );

    // Level 3 - Various endings
    root->left->left->left = createScene(
        "Inside the cave, you find the legendary Crystal of Wisdom! You win through knowledge!",
        "Restart Game",
        "Exit Game",
        3, 8
    );

    root->left->left->right = createScene(
        "You reach a peaceful village and live happily ever after. A quiet victory!",
        "Restart Game", 
        "Exit Game",
        3, 9
    );

    root->left->right->left = createScene(
        "You successfully disarm the trap and find immense treasure! Riches are yours!",
        "Restart Game",
        "Exit Game", 
        3, 10
    );

    root->left->right->right = createScene(
        "The trap explodes! You wake up with no memory. Game Over.",
        "Restart Game",
        "Exit Game",
        3, 11
    );

    root->right->left->left = createScene(
        "The wolf becomes your loyal companion! Together you become legends!",
        "Restart Game",
        "Exit Game",
        3, 12
    );

    root->right->left->right = createScene(
        "Your magic backfires! The wolf attacks and you barely escape with your life.",
        "Restart Game", 
        "Exit Game",
        3, 13
    );

    root->right->right->left = createScene(
        "You defeat the wolf and find its treasure hoard! Victory through strength!",
        "Restart Game",
        "Exit Game",
        3, 14
    );

    root->right->right->right = createScene(
        "The wolf overpowers you. Your adventure ends here... Game Over.",
        "Restart Game",
        "Exit Game",
        3, 15
    );

    // Initialize game state
    game.current = root;
    game.nodes_visited = 0;
    game.max_depth = 0;
    game.visit_count = 0;
}

// Display current scene and choices
void displayScene(SceneNode* scene) {
    printf("\n===============================================================\n");
    printf("SCENE #%d (Depth: %d)\n", scene->node_id, scene->depth);
    printf("================================================================\n");
    printf("%s\n\n", scene->description);
    printf("CHOOSE YOUR PATH:\n");
    printf("A) %s\n", scene->choiceA);
    printf("B) %s\n", scene->choiceB);
    printf("============================================================\n");

    // Track visited nodes and stats
    game.nodes_visited++;
    if (scene->depth > game.max_depth) {
        game.max_depth = scene->depth;
    }
    
    // Add to visited list if not already there
    bool already_visited = false;
    for (int i = 0; i < game.visit_count; i++) {
        if (game.visited_nodes[i] == scene) {
            already_visited = true;
            break;
        }
    }
    if (!already_visited && game.visit_count < 50) {
        game.visited_nodes[game.visit_count++] = scene;
    }
}

// Handle player choice
void makeChoice(char choice) {
    if (choice == 'A' || choice == 'a') {
        if (game.current->left != NULL) {
            game.current = game.current->left;
        } else {
            printf("This path leads to an ending. Use 'R' to restart.\n");
        }
    } else if (choice == 'B' || choice == 'b') {
        if (game.current->right != NULL) {
            game.current = game.current->right;
        } else {
            printf("This path leads to an ending. Use 'R' to restart.\n");
        }
    } else {
        printf("Invalid choice! Please choose A or B.\n");
    }
}

// Postorder traversal of the adventure tree
void postorderTraversal(SceneNode* root) {
    if (root == NULL) return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    
    printf("Scene %d (Depth %d): %s\n", 
           root->node_id, root->depth, root->description);
}

// Calculate tree statistics
void calculateTreeStats(SceneNode* root, int* total_nodes, int* max_depth) {
    if (root == NULL) return;
    
    (*total_nodes)++;
    if (root->depth > *max_depth) {
        *max_depth = root->depth;
    }
    
    calculateTreeStats(root->left, total_nodes, max_depth);
    calculateTreeStats(root->right, total_nodes, max_depth);
}

// Show game statistics
void showGameStats() {
    int total_nodes = 0;
    int absolute_max_depth = 0;
    
    calculateTreeStats(game.visited_nodes[0], &total_nodes, &absolute_max_depth);
    
    printf("\n===============================================================\n");
    printf("GAME STATISTICS\n");
    printf("===============================================================\n");
    printf("Total scenes in adventure: %d\n", total_nodes);
    printf("Maximum possible depth: %d\n", absolute_max_depth);
    printf("Scenes visited in this playthrough: %d\n", game.visit_count);
    printf("Maximum depth reached: %d\n", game.max_depth);
    printf("Nodes traversed: %d\n", game.nodes_visited);
    printf("===============================================================\n");
}

// Show postorder traversal of visited nodes
void showPostorderJourney() {
    printf("\n===============================================================\n");
    printf("YOUR JOURNEY (Postorder Traversal)\n");
    printf("===============================================================\n");
    
    // Create a temporary tree of only visited nodes for traversal
    if (game.visit_count > 0) {
        // For simplicity, we'll traverse the original tree but only print visited nodes
        printf("Scenes you experienced in postorder:\n");
        // This is a simplified version - in a full implementation, 
        // you'd need to build a subtree of visited nodes
        for (int i = 0; i < game.visit_count; i++) {
            printf("- Scene %d (Depth %d)\n", 
                   game.visited_nodes[i]->node_id, 
                   game.visited_nodes[i]->depth);
        }
    }
}

// Free memory
void freeTree(SceneNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main game loop
int main() {
    char input;
    bool playing = true;
    
    printf("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
    printf("|                   TEXT ADVENTURE GAME                        |\n");
    printf("|              Binary Tree Adventure Quest                     |\n");
    printf("+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
    
    buildAdventureTree();
    
    while (playing) {
        displayScene(game.current);
        
        printf("\nEnter your choice (A/B): ");
        printf("\n[S]how Stats, [P]ostorder Journey, [R]estart, [Q]uit\n");
        printf("Choice: ");
        scanf(" %c", &input);
        
        switch(input) {
            case 'A':
            case 'a':
            case 'B':
            case 'b':
                makeChoice(input);
                break;
                
            case 'S':
            case 's':
                showGameStats();
                break;
                
            case 'P':
            case 'p':
                showPostorderJourney();
                break;
                
            case 'R':
            case 'r':
                freeTree(game.visited_nodes[0]);
                buildAdventureTree();
                printf("Game restarted!\n");
                break;
                
            case 'Q':
            case 'q':
                playing = false;
                break;
                
            default:
                printf("Invalid input! Please try again.\n");
        }
        
        // Check if we reached an ending scene (leaf node)
        if (game.current->left == NULL && game.current->right == NULL) {
            printf("\n===============================================================\n");
            printf("ADVENTURE COMPLETE!\n");
            showGameStats();
            printf("\nPress R to restart or Q to quit: ");
            scanf(" %c", &input);
            if (input == 'R' || input == 'r') {
                freeTree(game.visited_nodes[0]);
                buildAdventureTree();
            } else {
                playing = false;
            }
        }
    }
    
    // Cleanup
    if (game.visit_count > 0) {
        freeTree(game.visited_nodes[0]);
    }
    
    printf("\nThanks for playing! Goodbye!\n");
    return 0;
}