#include "PimScene.h"
#include "PimLayer.h"
#include "PimGameControl.h"
#include "PimRenderWindow.h"

namespace Pim
{
	Scene::Scene()
	{
		dirtyZOrder = true;
	}
	Scene::~Scene()
	{
		for each (Layer *layer in layers)
		{
			GameControl::getSingleton()->addNodeToDelete(layer);
		}
	}

	void Scene::addLayer(Layer *l)
	{
		layers.push_back(l);
		l->parentScene = this;
		l->loadResources();

		dirtyZOrder = true;
	}
	void Scene::removeLayer(Layer *l)
	{
		for (unsigned int i=0; i<layers.size(); i++)
		{
			if (layers[i] == l)
			{
				layers.erase(layers.begin() + i);
				delete l;
			}
		}
	}

	Layer* Scene::pauseLayer()
	{
		// Return NULL by default. This will not pause the game.
		return NULL;
	}

	void Scene::drawScene()
	{
		orderLayers();

		for (unsigned int i=0; i<layers.size(); i++)
			layers[i]->draw();
	}

	void Scene::orderLayers()
	{
		if (!dirtyZOrder)
			return;

		// Insertion sorting - the layers should be somewhat sorted already.
		for (unsigned int j=1; j<layers.size(); j++)
		{
			Layer *key = layers[j];
			int i = j - 1;

			while (i >= 0 && layers[i]->zOrder > key->zOrder)
			{
				layers[i+1] = layers[i];
				i--;
			}
			layers[i+1] = key;
		}

		dirtyZOrder = false;
	}
} 