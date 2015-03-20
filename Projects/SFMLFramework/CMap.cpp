#include "CMap.h"

CMap::CMap() {
    textureTileset = NULL;
}

bool CMap::OnLoad(std::string file) {
    TileList.clear();

    FILE* FileHandle = fopen(file.c_str(), "r");

    if(FileHandle == NULL) {
        return false;
    }

    for(int Y = 0;Y < MAP_HEIGHT;Y++) {
        for(int X = 0;X < MAP_WIDTH;X++) {
            CTile tempTile;

            fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);

            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    return true;
}

void CMap::OnRender(sf::RenderWindow* window, int mapX, int mapY) {
    if(textureTileset == NULL) return;

    sf::Vector2u textureSize = textureTileset->getSize();
    int TilesetWidth  = textureSize.x / TILE_SIZE;
    int TilesetHeight = textureSize.y / TILE_SIZE;

    int ID = 0;

    for(int Y = 0;Y < MAP_HEIGHT;Y++) {
        for(int X = 0;X < MAP_WIDTH;X++) {
            if(TileList[ID].TypeID == TILE_TYPE_NONE) {
                ID++;
                continue;
            }

            int tX = mapX + (X * TILE_SIZE);
            int tY = mapY + (Y * TILE_SIZE);

            int TilesetX = (TileList[ID].TileID % TilesetWidth) * TILE_SIZE;
            int TilesetY = (TileList[ID].TileID / TilesetHeight) * TILE_SIZE;

            CTexture::OnDraw(window, textureTileset, tX, tY, TilesetX, TilesetY, TILE_SIZE, TILE_SIZE);

            ID++;
        }
    }
}

CTile* CMap::GetTile(int X, int Y) {
    unsigned int ID = 0;

    ID = X / TILE_SIZE;
    ID = ID + (MAP_WIDTH * (Y / TILE_SIZE));

    if(ID < 0 || ID >= TileList.size()) {
        return NULL;
    }

    return &TileList[ID];
}
