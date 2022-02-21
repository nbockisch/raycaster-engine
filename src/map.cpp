/**
 * @author Nathan Bockisch
 *
 * Header file for the Map class, containing all the class and variable
 * defintions for loading and updating the map
 **/

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "headers/map.hpp"

Map::Map()
{
    this->map = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                };        
}

void Map::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    int tile_len = 40;

    for (int row = 0; row < this->map.size(); row++) {
        for (int col = 0; col < this->map[row].size(); col++) {
            if (this->map[row][col] == 1) {
                SDL_Rect tile;
                tile.x = col * tile_len;
                tile.y = row * tile_len;
                tile.w = tile_len - 1;
                tile.h = tile_len - 1;

                SDL_RenderFillRect(renderer, &tile);
            }
        }
    }
}

void Map::update()
{
}

Map::~Map()
{
}

std::vector<std::vector<int>> &Map::get_map()
{
    return this->map;
}
