#include "GUIUserAticleItem.h"


GUIUserAticleItem::GUIUserAticleItem()
{
}


GUIUserAticleItem::~GUIUserAticleItem()
{
}

void GUIUserAticleItem::setItem(Node* _item)
{
	item = _item;
	this->addChild(item);
}