#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "unistd.h"
// Data
struct {
    struct {
        int width;
        int height;
        int halfWidth;
        int halfHeight;
        int scale;
    } screen;
    struct {
        int width;
        int height;
        int halfWidth;
        int halfHeight;
    } projection;
    struct {
        int delay;
    } render;
    struct {
        float incrementAngle;
        int precision;
    } rayCasting;
    struct {
        int fov;
        int halfFov;
        float x;
        float y;
        float angle;
        float radius;
        struct {
            float movement;
            float rotation;
        } speed;
    } player;
    int map[10][10];
    struct {
        struct {
            char code[4];
            int active;
        } up;
        struct {
            char code[4];
            int active;
        } down;
        struct {
            char code[4];
            int active;
        } left;
        struct {
            char code[4];
            int active;
        } right;
    } key;
    struct {
        struct {
            int width;
            int height;
            int bitmap[8][8];
            char* colors[2];
        } texture1;
        struct {
            int width;
            int height;
            char id[8];
            void* data;
        } texture2;
    } textures;
} data;

// Calculated data
void calculateData() {
    data.screen.halfWidth = data.screen.width / 2;
    data.screen.halfHeight = data.screen.height / 2;
    data.player.halfFov = data.player.fov / 2;
    data.projection.width = data.screen.width / data.screen.scale;
    data.projection.height = data.screen.height / data.screen.scale;
    data.projection.halfWidth = data.projection.width / 2;
    data.projection.halfHeight = data.projection.height / 2;
    data.rayCasting.incrementAngle = data.player.fov / data.projection.width;
}

// Canvas
void createScreen() {
    data.screen.width = 640;
    data.screen.height = 480;
    data.screen.scale = 4;
    data.screen.halfWidth = data.screen.width / 2;
    data.screen.halfHeight = data.screen.height / 2;

    // Create screen
    printf("Creating screen...\n");
}

// Main loop
void mainLoop() {
    int i;

    // Main loop
    while(1) {
        // Clear screen
        printf("Clearing screen...\n");

        // Move player
        printf("Moving player...\n");

        // Raycasting
        printf("Raycasting...\n");
        for(i = 0; i < data.projection.width; i++) {
            // Ray data
            float rayAngle = data.player.angle - data.player.halfFov + (i * data.rayCasting.incrementAngle);
            printf("Ray %d: Angle = %f\n", i, rayAngle);
        }

        // Delay
        printf("Delaying...\n");
        usleep(data.render.delay * 1000);
    }
}

// Start
int main() {
	printf("start cmd.exe /K \"echo Hello, world! && pause\"");
    // Create screen
    createScreen();

    // Calculate data
    calculateData();

    // Main loop
    mainLoop();

    return 0;
}
