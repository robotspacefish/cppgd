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

			// position ready for the next 4 vertices
			currentVertex += VERTS_IN_QUAD;
		}
	}

	return TILE_SIZE;

}