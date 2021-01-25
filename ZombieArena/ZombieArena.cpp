#include "ZombieArena.h"

int createBackground(sf::VertexArray& rVA, sf::IntRect arena)
{
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;

	int worldWidth = arena.width / TILE_SIZE;
	int worldHeight = arena.height / TILE_SIZE;

	// set primitive type
	rVA.setPrimitiveType(sf::Quads);

	// set the size of the vertex array
	rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

	 // start at the beginning of the vertex array
	int currentVertex = 0;

	for (int w = 0; w < worldWidth; w++)
	{
		for (int h = 0; h < worldHeight; h++)
		{
			// positione each vertex in the current quad
			rVA[currentVertex].position = sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 3].position = sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);

			// define the position in the Texture for current quad
			// either grass, stone, bush, or wall
			if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1)
			{
				// wall texture
				rVA[currentVertex].texCoords = sf::Vector2f(0, TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = sf::Vector2f(TILE_SIZE, TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = sf::Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
			}
			else
			{
				// use a random floor texture
				srand((int)time(0) + h * w - h);
				int mOrG = (rand() % TILE_TYPES); // mud or grass
				int verticalOffset = mOrG * TILE_SIZE;

				rVA[currentVertex].texCoords = sf::Vector2f(0, verticalOffset);
				rVA[currentVertex + 1].texCoords = sf::Vector2f(TILE_SIZE, verticalOffset);
				rVA[currentVertex + 2].texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVA[currentVertex + 3].texCoords = sf::Vector2f(0, TILE_SIZE + verticalOffset);
			}

			// position ready for the next 4 vertices
			currentVertex += VERTS_IN_QUAD;
		}
	}

	return TILE_SIZE;

}